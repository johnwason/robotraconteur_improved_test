
include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/macros.cmake)

find_package(GTest)
include(googletest)

add_subdirectory(robdef)
add_subdirectory(lfsr)
add_subdirectory(cpp)
