cmake_minimum_required(VERSION 3.5)

project(ObjectOrientedProgramming CXX)

# C++20? Why not?
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_subdirectory(laboratory-works)
add_subdirectory(temp)

add_custom_target(${PROJECT_NAME})
add_dependencies(${PROJECT_NAME}
  LaboratorylWorks
)