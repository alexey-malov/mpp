
# Add source to this project's executable.
add_executable (str_char_io "str_char_io.c" )

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET str_char_io PROPERTY C_STANDARD 23)
endif()
