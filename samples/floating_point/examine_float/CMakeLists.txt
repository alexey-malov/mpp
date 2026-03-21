# CMakeList.txt : CMake project for fixed_point, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (examine_float "examine_float.c")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET examine_float PROPERTY C_STANDARD 23)
endif()

# TODO: Add tests and install targets if needed.
