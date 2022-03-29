project(LaboratorylWork1)

add_subdirectory(task1)
add_subdirectory(task2)

add_custom_target(${PROJECT_NAME})
add_dependencies(${PROJECT_NAME}
  ${PROJECT_NAME}Task1
  ${PROJECT_NAME}Task2
)