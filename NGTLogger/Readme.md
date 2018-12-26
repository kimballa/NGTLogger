NGTLogger
=========

This Win32 console application logs NMEA2000 datagrams from an NMEA2000 network,
as captured by the Actisense NGT-1. The application uses Actisense's NGT-1
SDK to interface with the NMEA2K network.

* Compile in visual studio
* Connect to NGT-1
* Creates csv-based logs of the raw, captured network data. You can pass
  a filename to the CLI program to use, or it will pick an unused filename
  based on today's date to use if none is provided.

File format
-----------

Each NMEA2000 record is on a single line of a text file, like the one as follows:
```
2018-12-25 16:21:10.994, 7, 65313, 3, 255, 8, 13, 99, c4, 0, ff, ff, ff, ff
```

The comma-delimited fields are:

* Msg timestamp
* priority (7)
* PGN (65313)
* src id (3)
* dest id (255, i.e. broadcast)
* data length (8)
* /n/ data bytes follow...
