cmake_minimum_required(VERSION 3.10)

project(LibrdKafkaSample VERSION 0.1)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

#just for debugging
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall")

set(RDKAFKA_BUILD_STATIC ON CACHE BOOL "")

include_directories( ./libs/yaml-cpp/include ./libs/librdkafka)

add_executable(LibrdKafkaSample src/LibrdKafkaSample.cpp)

add_subdirectory( ./libs/librdkafka)
target_link_libraries( LibrdKafkaSample debug rdkafka++)

target_include_directories(LibrdKafkaSample PUBLIC "${PROJECT_BINARY_DIR}/src")