# Add source to this project's executable.
add_executable (cache_line "cache_line.c" )

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET cache_line PROPERTY C_STANDARD 23)
endif()

# TODO: Add tests and install targets if needed.
