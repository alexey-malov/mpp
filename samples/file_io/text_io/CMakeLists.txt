
# Add source to this project's executable.
add_executable (text_io "text_io.c" )

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET text_io PROPERTY C_STANDARD 23)
endif()
