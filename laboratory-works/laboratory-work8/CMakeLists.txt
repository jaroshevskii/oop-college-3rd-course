# Set the minimum version of CMake that can be used
cmake_minimum_required(VERSION 3.5)

# Set project name
project(LaboratorylWork8)

# Add sub directories
add_subdirectory(task)

add_custom_target(${PROJECT_NAME})
add_dependencies(${PROJECT_NAME}
  ${PROJECT_NAME}Task
)