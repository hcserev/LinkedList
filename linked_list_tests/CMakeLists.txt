cmake_minimum_required(VERSION 3.0.2)
set(This linked_list_tests)

set(Sources
	linked_list_tests.cpp
)

add_executable(${This} ${Sources})

target_link_libraries(${This} PUBLIC
gtest_main
linked_list
)

add_test(
NAME ${This}
COMMAND ${This}
)