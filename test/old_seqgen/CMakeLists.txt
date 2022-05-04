

add_library(robotraconteur_test_old_seqgen SHARED src/robotraconteur_test_old_seqgen.cpp src/robotraconteur_test_old_seqgen_cpp.cpp)
target_include_directories(robotraconteur_test_old_seqgen PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_link_libraries(robotraconteur_test_old_seqgen RobotRaconteurCore)

if(WIN32)
	target_compile_definitions(robotraconteur_test_old_seqgen PRIVATE ROBOTRACONTEUR_TEST_OLD_SEQGEN_EXPORTS INTERFACE ROBOTRACONTEUR_TEST_OLD_SEQGEN_IMPORTS)
endif()

RR_SET_TEST_TARGET_DIRS(robotraconteur_test_old_seqgen bin lib)