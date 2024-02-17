cmake_minimum_required(VERSION 2.6)
project(sortDemo)

# add_library(methods sortDemo.cpp)
add_executable(${PROJECT_NAME} main.cpp sortDemo.cpp)
# target_link_libraries(${PROJECT_NAME} methods)