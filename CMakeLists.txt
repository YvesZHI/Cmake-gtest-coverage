cmake_minimum_required(VERSION 3.9)
project(Student CXX)

set(CMAKE_CXX_COMPILER g++)
set(CMAKE_CXX_STANDARD 11)

set(INCLUDES include)
set(SOURCES src/Student.cpp)
set(MAIN src/main.cpp)
set(TARGET student)

add_executable(${TARGET} ${MAIN} ${SOURCES})
target_include_directories(${TARGET} PRIVATE ${INCLUDES})

# release
# cmake -DRelease=ON ../
set(Release OFF CACHE BOOL "release or debug")
if(${Release})
    # normal release bin file
    target_compile_options(${TARGET} PRIVATE -std=c++11 -O3)
    return()
endif()

# debug
target_compile_options(${TARGET} PRIVATE -std=c++11 -g -O0)

# unit-test and code coverage
add_subdirectory(unittest) # directory name
