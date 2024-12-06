cmake_minimum_required(VERSION 3.15)
project(FastFinancial LANGUAGES CXX)

# C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Boost setup
find_package(boost REQUIRED COMPONENTS system thread)

# Include directories
include_directories(${Boost_INCLUDE_DIRS} include )
include_directories(include/FastFinancial)

# Source files
file(GLOB_RECURSE SOURCES src/*.cpp)

# Executable
add_executable(FastFinancial ${SOURCES})

# Link Boost libraries
target_link_libraries(FastFinancial PRIVATE ${Boost_LIBRARIES})

# Testing setup (optional)
# enable_testing()
# add_subdirectory(tests)
