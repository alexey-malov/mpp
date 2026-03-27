
# Add source to this project's executable.
add_executable (read_point "read_point.c" )

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET read_point PROPERTY C_STANDARD 23)
endif()
