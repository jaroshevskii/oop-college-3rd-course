cmake_minimum_required(VERSION 3.5)

project(ObjectOrientedProgramming)

add_subdirectory(laboratory-works)
add_subdirectory(temp)

add_custom_target(${PROJECT_NAME})
add_dependencies(${PROJECT_NAME}
  LaboratorylWorks
)