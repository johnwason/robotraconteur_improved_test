ROBOTRACONTEUR_GENERATE_THUNK(RR_THUNK_SRCS RR_THUNK_HDRS 
	com.robotraconteur.testing.TestService1.robdef 
	com.robotraconteur.testing.TestService2.robdef 
	com.robotraconteur.testing.TestService3.robdef
	com.robotraconteur.testing.TestService4.robdef
	com.robotraconteur.testing.TestService5.robdef
	MASTER_HEADER
	INCLUDE_DIRS ${ROBOTRACONTEUR_TEST_ROBDEF_DIR}
	)

RR_TEST_ADD_EXECUTABLE(robotraconteur_service_test
    SRC service_test.cpp ServiceTestClient.cpp CompareArray.cpp ${RR_THUNK_SRCS}
    DEPS RobotRaconteurCore robotraconteur_test_cpp_common robotraconteur_test_lfsr GTest::gtest_main    
)
target_include_directories(robotraconteur_service_test PUBLIC ${CMAKE_CURRENT_BINARY_DIR})
if (MSVC)
	target_compile_options(robotraconteur_service_test PRIVATE "/bigobj")
endif()

RR_TEST_ADD_EXECUTABLE(robotraconteur_single_thread_service_test
    SRC single_thread_test.cpp ServiceTestClient.cpp CompareArray.cpp ${RR_THUNK_SRCS}
    DEPS RobotRaconteurCore robotraconteur_test_cpp_common robotraconteur_test_lfsr GTest::gtest_main    
)
target_include_directories(robotraconteur_single_thread_service_test PUBLIC ${CMAKE_CURRENT_BINARY_DIR})
if (MSVC)
	target_compile_options(robotraconteur_single_thread_service_test PRIVATE "/bigobj")
endif()

RR_TEST_ADD_EXECUTABLE(robotraconteur_service_test2
    SRC service_test2.cpp ServiceTestClient2.cpp ServiceTest2.cpp CompareArray.cpp ${RR_THUNK_SRCS}
    DEPS RobotRaconteurCore robotraconteur_test_cpp_common robotraconteur_test_lfsr GTest::gtest_main    
)
target_include_directories(robotraconteur_service_test2 PUBLIC ${CMAKE_CURRENT_BINARY_DIR})
if (MSVC)
	target_compile_options(robotraconteur_service_test2 PRIVATE "/bigobj")
endif()

RR_TEST_ADD_EXECUTABLE(robotraconteur_service_test3
    SRC service_test3.cpp ServiceTestClient3.cpp ServiceTest3.cpp CompareArray.cpp ${RR_THUNK_SRCS}
    DEPS RobotRaconteurCore robotraconteur_test_cpp_common robotraconteur_test_lfsr GTest::gtest_main    
)
target_include_directories(robotraconteur_service_test3 PUBLIC ${CMAKE_CURRENT_BINARY_DIR})
if (MSVC)
	target_compile_options(robotraconteur_service_test3 PRIVATE "/bigobj")
endif()