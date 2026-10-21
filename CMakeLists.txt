cmake_minimum_required(VERSION 3.15)
project(fastfi LANGUAGES CXX)

# C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Boost setup
find_package(Boost REQUIRED COMPONENTS system)

# Source files
file(GLOB_RECURSE SOURCES src/*.cpp)

# Executable
add_executable(fastfi ${SOURCES})
target_include_directories(fastfi PRIVATE include)

# Link Boost libraries
target_link_libraries(fastfi PRIVATE Boost::system)

# Testing setup (optional)
# enable_testing()
# add_subdirectory(tests)
