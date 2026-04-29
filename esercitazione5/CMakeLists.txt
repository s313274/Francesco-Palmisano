cmake_minimum_required(VERSION 3.20)

project(esercitazione4)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wshadow -Werror=vla")

set(SRC_test_sorts timer_sort.cpp timecounter.cpp)
add_executable(measure_sorts ${SRC_test_sorts})

add_executable(test_bubble test_bubble.cpp)
add_test(NAME bubblesort COMMAND test_bubble)

add_executable(test_insertion test_insertion.cpp)
add_test(NAME insertionsort COMMAND test_insertion)

add_executable(test_selection test_selection.cpp)
add_test(NAME selectionsort COMMAND test_selection)

add_executable(test_mergesort test_mergesort.cpp)
add_test(NAME mergesort COMMAND test_mergesort)

add_executable(test_quickinsertionsort test_quickinsertionsort.cpp)
add_test(NAME quickinsertionsort COMMAND test_quickinsertionsort)

add_executable(test_quicksort test_quicksort.cpp)
add_test(NAME quicksort COMMAND test_quicksort)

enable_testing()