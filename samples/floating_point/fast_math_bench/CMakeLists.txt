# Add source to this project's executable.
add_executable(fast_math_bench "fast_math_bench.c")
add_executable(fast_math_bench_fast "fast_math_bench.c")

if(CMAKE_VERSION VERSION_GREATER 3.12)
    set_property(TARGET fast_math_bench PROPERTY C_STANDARD 23)
    set_property(TARGET fast_math_bench_fast PROPERTY C_STANDARD 23)
endif()

if(MSVC)
    target_compile_options(fast_math_bench PRIVATE /O2)
    target_compile_options(fast_math_bench_fast PRIVATE /O2 /fp:fast)
else()
    target_compile_options(fast_math_bench PRIVATE -O3)
    target_compile_options(fast_math_bench_fast PRIVATE -O3 -ffast-math)
endif()

# Для math.h на GCC/Clang обычно нужна libm и mvec
if(NOT MSVC)
    target_link_libraries(fast_math_bench PRIVATE m mvec)
    target_link_libraries(fast_math_bench_fast PRIVATE m mvec)
endif()