# Add source to this project's executable.
add_executable (shapes "main.c"  "shapes.h" "shapes.c")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET shapes PROPERTY C_STANDARD 23)
endif()

