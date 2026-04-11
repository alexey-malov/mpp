# Add source to this project's executable.
add_executable (memory_layout "memory_layout.c" )

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET memory_layout PROPERTY C_STANDARD 23)
endif()

# TODO: Add tests and install targets if needed.
