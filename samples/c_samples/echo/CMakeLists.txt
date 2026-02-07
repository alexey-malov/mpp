# CMakeList.txt : CMake project for echo
#

# Add source to this project's executable.
add_executable (echo "main.c")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET echo PROPERTY C_STANDARD 99)
endif()
