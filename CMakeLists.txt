cmake_minimum_required(VERSION 3.0.0)

project(ObjectOrientedProgramming)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_subdirectory(laboratory-works)
add_subdirectory(temp)

add_custom_target(ObjectOrientedProgramming)
add_dependencies(ObjectOrientedProgramming
  LaboratorylWorks
)
