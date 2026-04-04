# Add source to this project's executable.
add_executable (bubble_sort_with_comparator "bubble_sort_with_comparator.c" )

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET bubble_sort_with_comparator PROPERTY C_STANDARD 23)
endif()

