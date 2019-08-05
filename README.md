Cmake-gtest-coverage
==========================


### Introduction ###
This project is a sample which presents how `gtest`, `gcovr` and `cmake` work together.


### Installation ###
Execute `mkdir build && cd build && cmake .. && make` to compile the debug version.<br>
This will generate two binariy files: `student`, `student-test` and a bash script: `student-test-cov`.<br>
Execute `mkdir build && cd build && cmake -DRelease=ON .. && make` to compile the release version.<br>


### General Usage ###
`student` is the target bin file;<br>
`student-test` is the unit-test bin file;<br>
`student-test-cov` is to run `student-test` and to generate the html-format coverage file.
