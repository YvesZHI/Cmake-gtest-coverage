cmake_minimum_required(VERSION 3.9)
project(Student CXX)

set(CMAKE_CXX_COMPILER g++)
set(CMAKE_CXX_STANDARD 11)

set(SOURCES src/Student.cpp)
set(TARGET student)
set(TESTSOURCES unittest/TestStudent.cpp)
set(TESTTARGET student-test)
set(TESTTARGETCOV ${TESTTARGET}-cov)
set(RESULTCOV cov.html)
set(INCLUDES include)

find_program(gcovr REQUIRED)
find_package(GTest REQUIRED)

add_executable(${TARGET} src/main.cpp ${SOURCES})
target_include_directories(${TARGET} PRIVATE ${INCLUDES})
target_compile_options(${TARGET} PRIVATE -std=c++11 -g)

add_executable(${TESTTARGET} ${TESTSOURCES} ${SOURCES})
target_include_directories(${TESTTARGET} PRIVATE ${INCLUDES})
target_compile_options(${TESTTARGET} PRIVATE -std=c++11 -g -O0 -coverage)
#target_link_libraries(${TESTTARGET} -lgtest -lpthread gcov)
target_link_libraries(${TESTTARGET} GTest::GTest GTest::Main gcov)

add_custom_target(cov ALL)

add_custom_command(
    TARGET cov
    COMMAND touch xxx
    COMMAND -E echo -e '#!/bin/bash' > xxx
    )
#find . \( -name "*.gcda" -o -name "*.gcno" \) -exec cp {} ./ \;
##file(WRITE ${CMAKE_BINARY_DIR}/${TESTTARGETCOV} "#!/bin/bash\n\n./${TESTTARGET}\nfind . \\( -name \"*.gcda\" -o -name \"*.gcno\" \\) -exec cp {} ./ \; && gcovr -r .. --html -o ${RESULTCOV} && rm *.gcda *.gcno")
##execute_process(COMMAND bash -c "chmod +x ${TESTTARGETCOV}")

enable_testing()
include(GoogleTest)
gtest_add_tests(TARGET student-test AUTO)
