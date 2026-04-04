# Add source to this project's executable.
add_executable (bubble_sort "bubble_sort.c" )

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET bubble_sort PROPERTY C_STANDARD 23)
endif()

