
# Add source to this project's executable.
add_executable (opaque_struct "main.c" "point.h" "point.c")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET opaque_struct PROPERTY C_STANDARD 23)
endif()

