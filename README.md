Cmake-gtest-coverage
==========================


### Introduction ###
This project is a sample which presents how `gtest`, `gcovr` and `cmake` work together.


### Installation ###
Execute `mkdir build && cd build && cmake .. && make` to compile.<br>
This will generate two binariy files: `student`, `student-test` and a bash script: `student-test-cov`.<br>


### General Usage ###
`student` is the target bin file;<br>
`student-test` is the unit-test bin file;<br>
`student-test-cov` is to show the result of unit-test and to generate the html-format coverage file.
