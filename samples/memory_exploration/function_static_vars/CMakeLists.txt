# Add source to this project's executable.
add_executable (function_static_vars "function_static_vars.c" )

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET function_static_vars PROPERTY C_STANDARD 23)
endif()

# TODO: Add tests and install targets if needed.
