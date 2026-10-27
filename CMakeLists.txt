cmake_minimum_required(VERSION 3.10)
project(mini-task-manager CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(mini-task-manager
    src/main.cpp
    src/task.cpp
    src/task_manager.cpp
)

target_include_directories(mini-task-manager PRIVATE include)
