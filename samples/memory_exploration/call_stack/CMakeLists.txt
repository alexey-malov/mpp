# Add source to this project's executable.
add_executable (call_stack "call_stack.c" )

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET call_stack PROPERTY C_STANDARD 23)
endif()

# TODO: Add tests and install targets if needed.
