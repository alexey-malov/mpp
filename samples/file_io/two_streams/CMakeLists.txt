
# Add source to this project's executable.
add_executable (two_streams "two_streams.c" )

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET two_streams PROPERTY C_STANDARD 23)
endif()
