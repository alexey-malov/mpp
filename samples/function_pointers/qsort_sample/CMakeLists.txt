# Add source to this project's executable.
add_executable (qsort_sample "qsort_sample.c" )

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET qsort_sample PROPERTY C_STANDARD 23)
endif()

