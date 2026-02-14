# CMakeList.txt : CMake project for c_samples, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (for_loop "for_loop.c")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET for_loop PROPERTY C_STANDARD 11)
endif()

# TODO: Add tests and install targets if needed.
