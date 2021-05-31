cmake_minimum_required(VERSION 3.1.2)
project(unittest CXX)

macro(package_add_test TESTNAME)
    # create an exectuable in which the tests will be stored
    add_executable(${TESTNAME} ${ARGN})
    # link the Google test infrastructure, mocking library, and a default main fuction to
    # the test executable.  Remove g_test_main if writing your own main function.
    target_link_libraries(${TESTNAME} CONAN_PKG::gtest)
    add_test(NAME ${TESTNAME}
            WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/bin
            COMMAND ${TESTNAME})
    set_target_properties(${TESTNAME} PROPERTIES FOLDER tests)
endmacro()

package_add_test(gtest_init gtest.test.cpp)