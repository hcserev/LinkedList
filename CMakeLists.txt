cmake_minimum_required(VERSION 3.0.2)
project(linked_list C CXX)

set(CMAKE_CXX_STANDARD 11)

enable_testing()

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

add_subdirectory(googletest)

set(sources main.cpp linked_list.cpp)
set(headers linked_list.h algorythms.h)

include_directories("${PROJECT_SOURCE_DIR}/headers"
 "googletest/googletest/include/")

add_executable(${PROJECT_NAME}
               ${sources}
               ${headers})

#add_subdirectory(linked_list_tests)

target_link_libraries(gtest
)