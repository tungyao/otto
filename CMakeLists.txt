cmake_minimum_required(VERSION 3.13)
project(otto C)

set(CMAKE_C_STANDARD 99)

set(CMAKE_BUILD_TYPE "Debug")

add_executable(otto ./test/test_hash.c ./ottohash/ottohash.c ./ottofs/ottofs.c)