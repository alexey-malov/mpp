# CMakeList.txt : CMake project for fixed_point, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (math "math.c")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET math PROPERTY C_STANDARD 23)
endif()

# TODO: Add tests and install targets if needed.
