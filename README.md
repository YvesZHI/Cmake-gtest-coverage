Cmake-gtest-coverage
==========================


### Introduction ###
This project is a sample which presents how `gtest`, `gcovr` and `cmake` work together.


### Installation ###
`mkdir build && cd build && cmake .. && make`: compile the debug version.<br>
This will generate two binariy files: `student`, `student-test` and a bash script: `student-test-cov`. All of these can be removed by executing `make clean-all`<br><br>
`mkdir build && cd build && cmake -DRelease=ON .. && make`: compile the release version.<br>
This will generate one binary file: `student`. It can be removed by executing `make clean`.


### General Usage ###
`student` is the target bin file;<br>
`student-test` is the unit-test bin file;<br>
`student-test-cov` is to run `student-test` and to generate the html-format coverage file.
``
