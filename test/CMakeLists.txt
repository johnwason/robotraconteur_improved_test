
function(RR_SET_TEST_TARGET_DIRS target bindir libdir)

set_target_properties(${target} PROPERTIES ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/test/out/${libdir}")
set_target_properties(${target} PROPERTIES ARCHIVE_OUTPUT_DIRECTORY_DEBUG "${CMAKE_BINARY_DIR}/test/out_debug/${libdir}")
set_target_properties(${target} PROPERTIES ARCHIVE_OUTPUT_DIRECTORY_RELEASE "${CMAKE_BINARY_DIR}/test/out/${libdir}")
set_target_properties(${target} PROPERTIES ARCHIVE_OUTPUT_DIRECTORY_RELWITHDEBINFO "${CMAKE_BINARY_DIR}/test/out_reldebug/${libdir}")

set_target_properties(${target} PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/test/out/${bindir}")
set_target_properties(${target} PROPERTIES RUNTIME_OUTPUT_DIRECTORY_DEBUG "${CMAKE_BINARY_DIR}/test/out_debug/${bindir}")
set_target_properties(${target} PROPERTIES RUNTIME_OUTPUT_DIRECTORY_RELEASE "${CMAKE_BINARY_DIR}/test/out/${bindir}")
set_target_properties(${target} PROPERTIES RUNTIME_OUTPUT_DIRECTORY_RELWITHDEBINFO "${CMAKE_BINARY_DIR}/test/out_reldebug/${bindir}")

set_target_properties(${target} PROPERTIES LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/test/out/${libdir}")
set_target_properties(${target} PROPERTIES LIBRARY_OUTPUT_DIRECTORY_DEBUG "${CMAKE_BINARY_DIR}/test/out_debug/${libdir}")
set_target_properties(${target} PROPERTIES LIBRARY_OUTPUT_DIRECTORY_RELEASE "${CMAKE_BINARY_DIR}/test/out/${libdir}")
set_target_properties(${target} PROPERTIES LIBRARY_OUTPUT_DIRECTORY_RELWITHDEBINFO "${CMAKE_BINARY_DIR}/test/out_reldebug/${libdir}")

endfunction()

find_package(GTest)
include(googletest)

add_subdirectory(lfsr)
add_subdirectory(cpp)
