# Set the minimum version of CMake that can be used
cmake_minimum_required(VERSION 3.5)

# Set project name
project(ObjectOrientedProgramming)

# Add sub directories
add_subdirectory(practical-works)

add_custom_target(${PROJECT_NAME})
add_dependencies(${PROJECT_NAME}
  PracticalWork1
)