## Mini Project 3 - Translation Lookaside Buffer (TLB)
### Chad Callender
### Description:

TLBs are fully associative cache memory that store the page table entries in use. They are very small, and in this project we assume there are 12 entries. The program must read a file with a million addresses and count and output the number of TLB misses (a TLB miss happens when the required page is not in the TLB).

### Files

|   #   | File                       | Description                                                |
| :---: | -------------------------- | ---------------------------------------------------------- |
|   1   | [mini_3.cpp](./mini_3.cpp) | Main code for calculating TLB misses. |
|   2   | [mini_3.txt](./mini_3.txt) | `mini_3.cpp` as a text file. |
|   3   | [spice.txt](./spice.txt)    | Input data with virtual addresses. |
|   4   | [test_file_mini_3.cpp](./test_file_mini_3.cpp)   | Code to create `test.txt`, a file with a few addresses from `spice.txt`. |
|   5   | [test.txt](./test.txt) | `test.txt`. |
