cmake_minimum_required(VERSION 3.0.2)
project(linked_list C CXX)

set(CMAKE_CXX_STANDARD 11)

enable_testing()

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

add_subdirectory(googletest)

set(sources main.cpp)
set(headers linked_list.h )

include_directories("${PROJECT_SOURCE_DIR}/headers"
 "googletest/googletest/include/")

add_library(${PROJECT_NAME} STATIC
               ${sources}
               ${headers})

add_subdirectory(linked_list_tests)

target_link_libraries(gtest
)