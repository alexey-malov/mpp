# Add source to this project's executable.
add_executable (stream "stream.c" )

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET stream PROPERTY C_STANDARD 23)
endif()

