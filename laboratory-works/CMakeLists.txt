project(LaboratorylWorks)

add_subdirectory(laboratory-work1)
add_subdirectory(laboratory-work2)
add_subdirectory(laboratory-work8)

add_custom_target(${PROJECT_NAME})
add_dependencies(${PROJECT_NAME}
  LaboratorylWork1
  LaboratorylWork2
  LaboratorylWork8
)