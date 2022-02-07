# Set the minimum version of CMake that can be used
cmake_minimum_required(VERSION 3.5)

# Set project name
project(LaboratorylWork1)

# Add sub directories
add_subdirectory(task1)
add_subdirectory(task2)

add_custom_target(${PROJECT_NAME})
add_dependencies(${PROJECT_NAME}
  ${PROJECT_NAME}Task1
  ${PROJECT_NAME}Task2
)