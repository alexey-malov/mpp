# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("c_samples")

# Disable MSVC deprecation warnings for standard C functions
if (MSVC)
  add_compile_definitions(_CRT_SECURE_NO_WARNINGS)
endif()

# Include sub-projects.
add_subdirectory ("hello_world")
add_subdirectory ("sum_two_numbers")
add_subdirectory ("echo")
add_subdirectory ("for_loop")
