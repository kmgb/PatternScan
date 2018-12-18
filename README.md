# PatternScan

Used for scanning a memory range for a given pattern, supporting both codestyle and IDA-style patterns.  
Example usages can be found in main.cpp.

Codestyle: bytes and mask eg. {0x8B, 0x0D, 0, 0, 0xAA, 0xBB} and {true, true, false, false, true, true}  
Wildcard bytes are signified with a corresponding mask entry being false

IDA-style: string pattern eg. "8B 0D ? ? AA BB" 
Bytes separated by spaces, wildcard bytes are signified with a `?`
