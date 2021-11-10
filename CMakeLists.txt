cmake_minimum_required(VERSION 3.3)
project(robotraconteur_improved_tests)

find_package(RobotRaconteur)
include_directories(${RobotRaconteur_INCLUDE_DIR})

include(CTest)

enable_testing()

add_subdirectory(test)