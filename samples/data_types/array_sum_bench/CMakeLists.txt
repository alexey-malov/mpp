# CMakeList.txt : CMake project for array_sum_bench, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (array_sum_bench "array_sum_bench.c" )

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET array_sum_bench PROPERTY C_STANDARD 23)
endif()

# TODO: Add tests and install targets if needed.
