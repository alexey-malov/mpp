# CMakeList.txt : CMake project for sum_two_numbers
#

# Add source to this project's executable.
add_executable (sum_two_numbers "main.c")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET sum_two_numbers PROPERTY C_STANDARD 99)
endif()
