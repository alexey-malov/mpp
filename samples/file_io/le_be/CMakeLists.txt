
# Add source to this project's executable.
add_executable (le_be "le_be.c" )

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET le_be PROPERTY C_STANDARD 23)
endif()
