project(LaboratorylWorks)

add_subdirectory(laboratory-work1)
add_subdirectory(laboratory-work2)
add_subdirectory(laboratory-work3)
# add_subdirectory(laboratory-work4)
# add_subdirectory(laboratory-work5)
# add_subdirectory(laboratory-work6)
# add_subdirectory(laboratory-work7)
add_subdirectory(laboratory-work8)

add_custom_target(${PROJECT_NAME})
add_dependencies(${PROJECT_NAME}
  LaboratorylWork1
  LaboratorylWork2
  LaboratorylWork3
  # LaboratorylWork4
  # LaboratorylWork5
  # LaboratorylWork6
  # LaboratorylWork7
  LaboratorylWork8
)