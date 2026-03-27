
# Add source to this project's executable.
add_executable (fp_bin_io "fp_bin_io.c" )

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET fp_bin_io PROPERTY C_STANDARD 23)
endif()
