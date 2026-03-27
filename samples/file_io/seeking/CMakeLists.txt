
# Add source to this project's executable.
add_executable (seeking "seeking.c" )

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET seeking PROPERTY C_STANDARD 23)
endif()
