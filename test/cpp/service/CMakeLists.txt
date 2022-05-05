
include(${CMAKE_CURRENT_LIST_DIR}/cmake/macros.cmake)

ROBOTRACONTEUR_GENERATE_THUNK(RR_THUNK_SRCS RR_THUNK_HDRS 
	com.robotraconteur.testing.TestService1.robdef 
	com.robotraconteur.testing.TestService2.robdef 
	com.robotraconteur.testing.TestService3.robdef
	com.robotraconteur.testing.TestService4.robdef
	com.robotraconteur.testing.TestService5.robdef
	MASTER_HEADER
	INCLUDE_DIRS ${ROBOTRACONTEUR_TEST_ROBDEF_DIR}
	)

RR_SERVICE_TEST_ADD_TEST(service SRC service_test.cpp ServiceTestClient.cpp CompareArray.cpp service_test_utils.cpp ${RR_THUNK_SRCS})

RR_SERVICE_TEST_ADD_TEST(single_thread_service SRC single_thread_test.cpp ServiceTestClient.cpp CompareArray.cpp service_test_utils.cpp ${RR_THUNK_SRCS})

RR_SERVICE_TEST_ADD_TEST(service2 SRC service_test2.cpp ServiceTestClient2.cpp ServiceTest2.cpp CompareArray.cpp service_test_utils.cpp ${RR_THUNK_SRCS})

RR_SERVICE_TEST_ADD_TEST(service3 SRC service_test3.cpp ServiceTestClient3.cpp ServiceTest3.cpp CompareArray.cpp service_test_utils.cpp ${RR_THUNK_SRCS})

RR_SERVICE_TEST_ADD_EXE(server SRC test_server.cpp ServiceTest.cpp ServiceTest2.cpp ServiceTest3.cpp CompareArray.cpp service_test_utils.cpp)
