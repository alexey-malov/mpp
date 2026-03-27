# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("file_io")

# Include sub-projects.
add_subdirectory ("stdio")
add_subdirectory ("text_io")
add_subdirectory ("str_char_io")
add_subdirectory ("write_point")
add_subdirectory ("read_point")
add_subdirectory ("fp_text_io")
add_subdirectory ("fp_bin_io")
add_subdirectory ("le_be")
add_subdirectory ("seeking")
add_subdirectory ("two_streams")
