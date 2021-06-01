cmake_minimum_required(VERSION 3.1.2)
project(crucible CXX)

set(CMAKE_CXX_STANDARD 17)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

option(BUILD_TESTS "Run unit tests" OFF)

if(EXISTS ${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
    include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
    conan_basic_setup(TARGETS)
else()
    message(WARNING "The file conanbuildinfo.cmake doesn't exist, you have to run conan install first")
endif()

include_directories(include)

conan_basic_setup()

file(GLOB_RECURSE LIB_SRC
    lib/*.hpp
    lib/*.cpp
)

file(GLOB_RECURSE APP_SRC
    src/*.hpp
    src/*.cpp
)

add_library(crucible_lib ${LIB_SRC})
add_executable(crucible ${APP_SRC})
target_link_libraries(crucible crucible_lib ${CONAN_LIBS})

if(BUILD_TESTS)
  enable_testing()
  add_subdirectory(tests)
endif()