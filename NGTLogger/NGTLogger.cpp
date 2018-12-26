// (c) Copyright 2018 Aaron Kimball
// 
// NGTLogger: Simple application to log NMEA2000 data from NGT-1 to files.
//

#include "stdafx.h"
#include "NGTLogger.h"

// The name of the device as read from the serial port enumerator.
const string ACTISENSE_NGT_NAME("Actisense NGT");
const int INVALID_SERIAL_PORT = -1;
const int BAUD_RATE = 115200; // NGT-1 standard baud rate.
const int ERR_OK = 0; // success return code from Actisense

// Main thread wakes up this often (10 Hz) to check for new events.
const int SLEEP_TIME_MILLIS = 100;

map<int, string> pgnList; // Some PGNs we care about decoding in a more descriptive way.
void initPgns() {
  pgnList[126992] = "system time";
  pgnList[126996] = "component product info";
  pgnList[127233] = "MOB notification";
  pgnList[127250] = "vessel heading";
  pgnList[127257] = "Attitude pitch/yaw/roll";
  pgnList[127251] = "rate of turn";
  pgnList[127258] = "Magnetic variation";
  pgnList[128000] = "Leeway";
  pgnList[128259] = "Speed";
  pgnList[128267] = "Water depth";
  pgnList[128275] = "Distance log";
  pgnList[129025] = "Position (rapid update)";
  pgnList[129026] = "COG/SOG (rapid update)";
  pgnList[129027] = "Position delta (rapid update)";
  pgnList[129029] = "GNSS Position";
  pgnList[129033] = "Time and date";
  pgnList[129284] = "Navigation data";
  pgnList[129285] = "Navigation route";
  pgnList[129291] = "Set and drift (rapid update)";
  pgnList[129301] = "Time to mark";
  pgnList[129302] = "Bearing and distance between marks";
  pgnList[129541] = "GPS Almanac data";
  pgnList[129283] = "XTE";
  pgnList[129539] = "GNSS DOPs";
  pgnList[129540] = "GNSS Sats in view";
  pgnList[130306] = "Wind data";
  pgnList[130310] = "Environment: temperature and pressure";
  pgnList[130311] = "Environment: data sources";
  pgnList[130577] = "Direction data";
}

// Return true if the file exists.
bool fileExists(const string &filename) {
  struct stat statBuf;
  return (stat(filename.c_str(), &statBuf) == 0);
}

// return a (possibly) unique filename consisting of the date string and the id suffix.
string makeFilename(const string &dateStr, int id) {
  char fileIdBuf[24];
  memset(fileIdBuf, 0, 24);
  _itoa_s(id, fileIdBuf, 10);
  string fileIdStr(fileIdBuf);

  return dateStr + "-" + fileIdStr + ".csv";
}

// return an output filename, specified by the user on argv, or make up a unique one if not specified.
string getOutputFilename(int argc, char **argv) {
  if (argc >= 2) {
    // User has provided a filename.
    return string(argv[1]);
  }

  // Make up our own filename. Format will be yyyy-mm-dd-<n>.csv
  // We'll pick a unique 'n' suffix by checking for existing files.
  time_t curTime;
  time(&curTime);
  const char *DATE_FMT = "%Y-%m-%d";
  const int TIMESTAMP_STR_LEN = 256;
  struct tm timeinfo;
  localtime_s(&timeinfo, &curTime);
  char timestamp_str[TIMESTAMP_STR_LEN];
  memset(timestamp_str, 0, TIMESTAMP_STR_LEN);
  strftime(timestamp_str, TIMESTAMP_STR_LEN - 1, DATE_FMT, &timeinfo);
  string dateStr(timestamp_str);

  int fileId = 0;
  string filename = makeFilename(dateStr, fileId);
  while (fileExists(filename)) {
    fileId++;
    filename = makeFilename(dateStr, fileId);
  }

  return filename;
}

int initNGT1(int comPort) {
  int handle;
  int err;

  // Nothing to open.
  if (INVALID_SERIAL_PORT == comPort) {
    return ACOMMS_INVALID_HANDLE;
  }

  err = ACommsCreate(&handle);
  if (err != ERR_OK) {
    cout << "Could not create AComms handle (" << err << ")" << endl;
    return ACOMMS_INVALID_HANDLE;
  }

  cout << "Opening COM" << comPort << " at baudRate=" << BAUD_RATE << "...";
  err = ACommsOpen(handle, comPort, BAUD_RATE);
  if (err != ERR_OK) {
    cout << "Error (" << err << ")" << endl;
    return ACOMMS_INVALID_HANDLE;
  }

  cout << "OK." << endl;
  return handle; // successfully opened port.
}

// Print the list of available serial ports and associated devices and status to the console.
void enumerateSerialPorts() {
  sPortEnum portEnum;

  if (!ACommsEnumerateSerialPorts(&portEnum)) {
    cout << "Available ports:" << endl;
    for (u32 i = 0; i < portEnum.Size; i++) {
      cout << "COM" << portEnum.Ports[i] << ": \"" << ACommsEnumerateSerialPortsGetName(portEnum.Ports[i]) << "\" ";
      if (portEnum.PortStatus[i] == ACPES_Available) {
        cout << "(Available)";
      } else if (portEnum.PortStatus[i] == ACPES_Unavailable) {
        cout << "(Unavailable)";
      } else if (portEnum.PortStatus[i] == ACPES_Open) {
        cout << "(Already open)";
      } else {
        cout << "(Error/unknown)";
      }

      cout << endl;
    }
  }

  cout << endl;
}

// Enumerate avaiable serial ports and return an available NGT-1 device if it can be detected.
// This returns an integer 'x' such that COMx is the device. Returns -1 on failure.
int getSerialPortNumForNGT1() {
  sPortEnum portEnum;

  if (!ACommsEnumerateSerialPorts(&portEnum)) {
    for (u32 i = 0; i < portEnum.Size; i++) {
      if (portEnum.PortStatus[i] == ACPES_Available && ACTISENSE_NGT_NAME == ACommsEnumerateSerialPortsGetName(portEnum.Ports[i])) {
        return portEnum.Ports[i]; // Available NGT-1 on COMx where x = Ports[i].
      }
    }
  }

  return INVALID_SERIAL_PORT; // No available NGT-1.
}


// Clear out any waiting console messages.
void clearKeypressBuffer() {
  HANDLE hStdIn = GetStdHandle(STD_INPUT_HANDLE); // get Windows HANDLE to stdin.
  const int NUM_RECORDS = 10;
  INPUT_RECORD inputRecords[NUM_RECORDS];
  DWORD numEventsRead;

  bool keepReading = true;
  while (keepReading) {
    // Scan for up to 10 events on the console input at a time.
    int ret = PeekConsoleInput(hStdIn, inputRecords, NUM_RECORDS, &numEventsRead);
    if (0 == ret) {
      // Can't peek at the console. Assume no input / further work to do here.
      return;
    }

    if (numEventsRead > 0) {
      // There are 'numEventsRead' events waiting. Consume them.
      // We always ask for up to NUM_RECORDS. ReadConsoleInput() blocks until at least 1 event is ready.
      ret = ReadConsoleInput(hStdIn, inputRecords, NUM_RECORDS, &numEventsRead);
      if (0 == ret) {
        return; // Error performing read. Nothing left to do.
      }
    } else {
      keepReading = false; // No events to be read. We're done.
    }
  }
}

// Return true if a key was pressed recently, false otherwise.
bool isKeyPressed() {
  HANDLE hStdIn = GetStdHandle(STD_INPUT_HANDLE); // get Windows HANDLE to stdin.
  const int NUM_RECORDS = 10;
  INPUT_RECORD inputRecords[NUM_RECORDS];
  DWORD numEventsRead;

  // Scan for up to 10 events on the console input at a time.
  int ret = PeekConsoleInput(hStdIn, inputRecords, NUM_RECORDS, &numEventsRead);
  if (0 == ret) {
    // operation failed.
    return false;
  }

  for (unsigned int i = 0; i < numEventsRead; i++) {
    if ((inputRecords[i].EventType & KEY_EVENT) == KEY_EVENT) {
      return true; // Got a keypress event
    }
  }

  return false; // no keypress detected.
}

// atexit handler for NGT1 handle.
void cleanup_NGT1() {
  ACommsDestroyAll();
}

CRITICAL_SECTION time_callback_cs;
int callbackHandle; // NGT-1 handle to use in callback fn.

const int RUNTIME_NOT_SET = 0;   // We are still waiting for runtime info from the NGT-1.
const int RUNTIME_SET_ERROR = 1; // Could not set the runtime.
const int RUNTIME_SET_OK = 2;
int runtimeStatus = RUNTIME_NOT_SET;
u32 runningTime = 0;

// Callback function initiated by getNGTRunningTime() to process the response from NGT-1.
void __stdcall totalRuntimeCallback(void* pCallbackData, DecodeData_t dataType, DecodeReason_t reason) {
  if (dataType != ddTotalTime) {
    cout << "Got data of invalid type; ignoring";
    return;
  }

  if (reason == drDecodeDataInvalid) {
    // Data is invalid.
    cout << "Callback for invalid data." << endl;
    EnterCriticalSection(&time_callback_cs);
    runtimeStatus = RUNTIME_SET_ERROR;
    LeaveCriticalSection(&time_callback_cs);
    return;
  } else if (reason == drDecodeTimeout) {
    cout << "Callback timed out." << endl;
    EnterCriticalSection(&time_callback_cs);
    runtimeStatus = RUNTIME_SET_ERROR;
    LeaveCriticalSection(&time_callback_cs);
    return;
  } else if (reason == drDecodeDataArrived) {
    EnterCriticalSection(&time_callback_cs);

    // We've received the response payload we need. Decode it.
    sDecodeTotalTime totalTime;
    int err = ACommsDecode_GetTotalTime(callbackHandle, &totalTime);
    if (err != ERR_OK) {
      cout << "Error retrieving runtime from NGT-1 (" << err << ")" << endl;
      runtimeStatus = RUNTIME_SET_ERROR;
    } else if (!totalTime.Valid) {
      // Decoded correctly, but got an invalid result.
      cout << "Invalid time response from NGT-1" << endl;
      runtimeStatus = RUNTIME_SET_ERROR;
    } else {
      runningTime = totalTime.Time;
      runtimeStatus = RUNTIME_SET_OK;
    }

    LeaveCriticalSection(&time_callback_cs);      
  } else {
    cout << "Unknown reason code (" << reason << ")" << endl;
    EnterCriticalSection(&time_callback_cs);
    runtimeStatus = RUNTIME_SET_ERROR;
    LeaveCriticalSection(&time_callback_cs);
    return;
  }
}

/**
 * Timestamps on messages are referenced relative to how long the NGT-1 system has been running.
 * First we need to query for that. 
 *
 * This method returns the total number of seconds since the NGT-1 started.
 */
u32 getNGTRunningTime(int ngtHandle) {
  InitializeCriticalSection(&time_callback_cs);
  runningTime = 0;
  runtimeStatus = RUNTIME_NOT_SET;
  
  // ACommsCommand_GetTotalTime() will issue a request for total running time, but the resopnse
  // will be serviced by a callback. Set up the callback fn.
  callbackHandle = ngtHandle;
  int ret = ACommsDecode_SetCallback(ngtHandle, ddTotalTime, totalRuntimeCallback, NULL);
  if (ret != ERR_OK) {
    cout << "Could not set up callback function (" << ret << ")" << endl;
    exit(1);
  }
  ret = ACommsCommand_GetTotalTime(ngtHandle);
  if (ret != ERR_OK) {
    cout << "Could not request total time (" << ret << ")" << endl;
    exit(1);
  }

  cout << "Waiting for response..." << endl;

  // Wait for callback response.
  bool waiting = true;
  u32 myTime;
  u32 myStatus;
  while (waiting) {
    cout << ".";
    // Test if we've received data from the callback yet.
    EnterCriticalSection(&time_callback_cs);
    myTime = runningTime;
    myStatus = runtimeStatus;
    LeaveCriticalSection(&time_callback_cs);

    if (myStatus == RUNTIME_SET_ERROR) {
      cout << "Registered error returning time" << endl;
      ACommsDecode_SetCallback(ngtHandle, ddTotalTime, NULL, NULL); // disable callback
      exit(1); // Give up, hard.
    } else if (myStatus == RUNTIME_SET_OK) {
      waiting = false; // We're done! myTime is now poopulated correctly.
    } else {
      // myStatus should be RUNTIME_NOT_SET. Still waiting.
      Sleep(SLEEP_TIME_MILLIS);
    }
  }

  // Disable the callback.
  ACommsDecode_SetCallback(ngtHandle, ddTotalTime, NULL, NULL);
  return myTime;
}

string formatTime(time_t timestamp) {
  const char *TIMESTAMP_FMT = "%Y-%m-%d %H:%M:%S";
  const int TIMESTAMP_STR_LEN = 256;
  struct tm timeinfo;
  localtime_s(&timeinfo, &timestamp);

  char timestamp_str[TIMESTAMP_STR_LEN];
  memset(timestamp_str, 0, TIMESTAMP_STR_LEN);
  strftime(timestamp_str, TIMESTAMP_STR_LEN - 1, TIMESTAMP_FMT, &timeinfo);

  return string(timestamp_str);
}

// We got an NMEA2000 message from the device. Log it!
void logMessage(const sN2KMsg &msg, ofstream &outFile, time_t deviceStartTime) {
  /*
  u32 Timestamp;
  u32 PGN;
  u8	Priority;
  u8	SrcAddr;
  u8	DestAddr;
  u32	Length;
  u8	Data[N2K_MAXLEN_TP];
  */

  // Format the timestamp.
  time_t timestamp = msg.Timestamp / 1000 + deviceStartTime;
  int tsMillis = msg.Timestamp % 1000;

  string timestampStr = formatTime(timestamp);
  char millisStr[24];
  memset(millisStr, 0, 24);
  _itoa_s(tsMillis, millisStr, 10);
  timestampStr = timestampStr + "." + millisStr;

  //// log to console ////

  cout << dec; // decimal output.
  cout << "Msg: " << msg.PGN;
  if (pgnList.count(msg.PGN) == 1) {
    cout << " (" << pgnList[msg.PGN] << ")";
  }
  cout << " @ " << timestampStr << " p" << (int)msg.Priority << " From " << (int)msg.SrcAddr << " To " << (int)msg.DestAddr << ", len=" << msg.Length;

  cout << " [";
  cout << hex; // hex values for data packet.
  bool first = true;
  for (unsigned int i = 0; i < msg.Length; i++) {
    if (!first) {
      cout << ", ";
    }
   
    cout << (int) msg.Data[i];
    first = false;
  }
  cout << "]" << endl << dec;

  //// log to file ////

  // Each NMEA2000 record is on a single line of a text file, like the one as follows:
  // 2018-12-25 16:21:10.994, 7, 65313, 3, 255, 8, 13, 99, c4, 0, ff, ff, ff, ff
  // The comma-delimited fields are:
  // * Msg timestamp
  // * priority (7)
  // * PGN (65313)
  // * src id (3)
  // * dest id (255, broadcast)
  // * data length (8)
  // * /n/ data bytes follow...
  outFile << dec;
  outFile << timestampStr << ", ";
  outFile << (int)msg.Priority << ", ";
  outFile << msg.PGN << ", ";
  outFile << (int)msg.SrcAddr << ", ";
  outFile << (int)msg.DestAddr << ", ";
  outFile << msg.Length; // ',' added by data payload.
  outFile << hex;
  // Now output all the data bytes.
  for (unsigned int i = 0; i < msg.Length; i++) {
    outFile << ", " << (int)msg.Data[i];
  }
  outFile << dec << endl;
}

/**
 * Main entry point.
 *
 * Usage: NGTLogger <fileNameOut.csv> [ <comPortIn> ]
 */
int main(int argc, char **argv) {
  int ngtHandle;
  bool running = true;

  string filename = getOutputFilename(argc, argv);

  initPgns();
  enumerateSerialPorts();
  atexit(cleanup_NGT1);  // Clean up on our way out.

  // TODO: Allow user to specify serial port to override this.
  int serialPortId = getSerialPortNumForNGT1();
  if (INVALID_SERIAL_PORT == serialPortId) {
    cout << "Error: Could not detect serial port" << endl;
    return 1;
  }
  cout << "Selected serial port COM" << serialPortId << endl;

  ngtHandle = initNGT1(serialPortId);
  if (ACOMMS_INVALID_HANDLE == ngtHandle) {
    return 1; // cannot go further.
  }

  size_t bufferLen;
  int ret;
  sN2KMsg msg;

  clearKeypressBuffer(); // clear out any queued up keypresses.

  ACommsCommand_ReInitMainApp(ngtHandle);
  cout << "Waiting for device restart" << endl;
  Sleep(2000); // TODO(aaron): Wait for ddStartupStatus callback to do this correctly.
  cout << "Hopefully that's long enough." << endl;

  // Flush old data from queues.
  ACommsBST_FlushRx(ngtHandle);
  ACommsN2K_FlushRx(ngtHandle);

  cout << "Determining system runtime..." << endl;
  u32 runtime = getNGTRunningTime(ngtHandle); // Returns the num seconds the device has been live.
  cout << "Got runtime of " << runtime << " seconds." <<  endl;

  time_t curTime;
  time(&curTime);
  cout << "Current time: " << formatTime(curTime) << endl;

  // Device timestamps relative to this point. For whatever reason, they seem to be
  // relative to curTime though. Unclear why.
  time_t deviceStartTime = curTime - runtime; 
  cout << "Device boot time: " << formatTime(deviceStartTime) << endl;

  cout << "Logging NMEA output to file " << filename << endl;
  ofstream outFile;
  outFile.open(filename);


  cout << "Waiting for messages." << endl;
  cout << endl << endl << "*** Press any key to quit *** " << endl << endl;
  unsigned int totalMessages = 0;
  while (running) {
    if (isKeyPressed()) {
      cout << "Keypress detected" << endl;
      running = false;
      break; // Got a signal to exit.
    }

    ret = ACommsN2K_GetRxQSize(ngtHandle, &bufferLen);
    if (ret != ERR_OK) {
      cout << "Error getting RX Queue length (" << ret << ")" << endl;
      running = false;
      break;
    }

    if (bufferLen > 0) {
      // We have data to receive.
      for (size_t i = 0; i < bufferLen; i++) {
        ret = ACommsN2K_Read(ngtHandle, &msg);
        if (ret != ERR_OK) {
          cout << "Error retrieving message from N2K (" << ret << ")" << endl;
          // Try to flush the recv queue and try again.
          ret = ACommsN2K_FlushRx(ngtHandle);
          if (ret != ERR_OK) {
            cout << "Could not flush / reset queue (" << ret << ")" << endl;
            // Ok, that failed too. Now we give up.
            running = false;
          }
          // Regardless of whether the flush succeeded or not, give up on receiving msgs
          // in this pass.
          bufferLen = 0; 
          continue;
        }

        // We got a message in our buffer struct.
        // Let's log it.
        // Unclear why the msg timestamps seem to be relative to curTime, not deviceStartTime.
        // But.. it works?
        totalMessages++;
        logMessage(msg, outFile, curTime);
      }
    }
    
    if (running && bufferLen == 0) {
      // Don't busy-wait; give the system some time to queue up more messages.
      // If bufferLen was > 0 (i.e., we had messages) check for more immediately to avoid backlog.
      Sleep(SLEEP_TIME_MILLIS);
    }
  }

  clearKeypressBuffer(); // clear out any keypresses to avoid echo on next cmdline.

  cout << "Done!" << endl;
  cout << "Captured " << totalMessages << " messages." << endl;
  outFile.close();
  cout << "Log recorded to " << filename << endl;

  return 0;
}

