# AGENTS.md - Developer Guide for Coding Agents

This document provides essential information for AI coding agents working in this repository.

## Project Overview

**Course:** Программирование микропроцессоров (Microprocessor Programming)
**Primary Language:** C (C11 standard)
**Secondary Languages:** Assembly (x86/64, microcontroller assembly planned)
**Build System:** CMake (3.8+) with Ninja generator
**Target Platforms:** Windows (x64/x86), Linux, macOS

## Technology Stack

- **Language:** C11
- **Build Tool:** CMake 3.8+
- **Generator:** Ninja (Windows), platform-specific for Linux/macOS
- **Compilers:** 
  - Windows: MSVC (cl.exe)
  - Linux/macOS: GCC/Clang (default system compiler)
- **Version Control:** Git

## Project Structure

```
mpp/
├── samples/
│   └── c_samples/          # C programming samples
│       ├── CMakeLists.txt  # Top-level build configuration
│       ├── CMakePresets.json  # CMake preset configurations
│       └── hello_world/    # Individual sample projects
│           ├── CMakeLists.txt
│           └── hello.c
├── AGENTS.md               # This file
├── README.md               # Course structure
└── LICENSE
```

## Build Commands

### Configure Project

Configure for Windows x64 Debug:
```bash
cd samples/c_samples
cmake --preset x64-debug
```

Available presets:
- `x64-debug` - 64-bit Debug build
- `x64-release` - 64-bit Release build
- `x86-debug` - 32-bit Debug build
- `x86-release` - 32-bit Release build
- `linux-debug` - Linux Debug build
- `macos-debug` - macOS Debug build

### Build Project

Build all samples:
```bash
cd samples/c_samples
cmake --build out/build/x64-debug
```

Build specific target:
```bash
cd samples/c_samples
cmake --build out/build/x64-debug --target hello_world
```

### Run Executables

After building, executables are in `out/build/<preset>/`:
```bash
# Windows
.\out\build\x64-debug\hello_world\hello_world.exe

# Linux/macOS
./out/build/linux-debug/hello_world/hello_world
```

### Clean Build

```bash
# Remove build directory
rm -rf out/

# Or clean specific preset
rm -rf out/build/x64-debug
```

## Testing

Currently, the project does not have automated tests. When tests are added:

### Run All Tests
```bash
cd samples/c_samples
ctest --test-dir out/build/x64-debug
```

### Run Single Test
```bash
cd samples/c_samples
ctest --test-dir out/build/x64-debug -R test_name
```

## Code Style Guidelines

### Language Standard
- **C Standard:** C11 (ISO/IEC 9899:2011)
- Set via `set_property(TARGET <name> PROPERTY C_STANDARD 11)`

### File Organization
- **Source files:** `.c` extension
- **Header files:** `.h` extension
- **Assembly files:** `.asm` or `.s` extension (future)

### Naming Conventions
- **Functions:** `snake_case` (e.g., `calculate_sum`, `init_device`)
- **Variables:** `snake_case` (e.g., `counter`, `max_value`)
- **Constants:** `UPPER_SNAKE_CASE` (e.g., `MAX_BUFFER_SIZE`)
- **Macros:** `UPPER_SNAKE_CASE` (e.g., `#define PI 3.14159`)
- **Struct/Typedef:** `PascalCase` or `snake_case_t` (e.g., `typedef struct DeviceConfig device_config_t;`)

### Formatting
- **Indentation:** Tabs (based on existing code)
- **Braces:** K&R style or Allman style (opening brace on new line for functions)
- **Line length:** No strict limit, but keep reasonable (~80-120 chars)
- **Whitespace:** Space after keywords (`if (`, `for (`, `while (`)

### Comments
- **Single-line:** `// Comment` (C99+ style allowed)
- **Multi-line:** `/* Comment */`
- **Russian language:** Acceptable for educational comments (as seen in hello.c)
- **English language:** Preferred for production code
- Document complex logic, algorithms, and non-obvious behavior

### Include Directives
- Standard library headers first: `#include <stdio.h>`
- Project headers after: `#include "myheader.h"`
- Use angle brackets for system headers: `<header.h>`
- Use quotes for local headers: `"header.h"`

### Error Handling
- Check return values of functions that can fail
- Use meaningful error codes or errno
- Prefer explicit error handling over silent failures
- Document error conditions in function comments

### Memory Management
- Always free allocated memory
- Check malloc/calloc return values for NULL
- Initialize pointers to NULL when not immediately assigned
- Avoid memory leaks and buffer overflows

### Types
- Use standard integer types: `int`, `long`, `short`, `char`
- Use `<stdint.h>` for fixed-width types: `int32_t`, `uint8_t`, etc.
- Use `size_t` for sizes and array indices
- Use `bool` from `<stdbool.h>` for boolean values

## CMake Guidelines

### MSVC Configuration
The top-level `CMakeLists.txt` includes:
```cmake
if (MSVC)
  add_compile_definitions(_CRT_SECURE_NO_WARNINGS)
endif()
```
This disables deprecation warnings for standard C functions (scanf, strcpy, etc.) across all targets.

### Adding New Samples
1. Create subdirectory under `samples/c_samples/`
2. Add `CMakeLists.txt` with:
   ```cmake
   add_executable(sample_name "source.c")
   set_property(TARGET sample_name PROPERTY C_STANDARD 11)
   ```
3. Add subdirectory to parent `CMakeLists.txt`:
   ```cmake
   add_subdirectory("sample_name")
   ```

### Linking Libraries
```cmake
target_link_libraries(sample_name PRIVATE library_name)
```

### Adding Include Directories
```cmake
target_include_directories(sample_name PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
```

## Git Workflow

- Commit messages in English or Russian (consistent with project)
- Use descriptive commit messages
- Avoid committing build artifacts (`out/`, `.vs/`, etc.)

## Additional Notes

- This is an educational repository for a microprocessor programming course
- Code should prioritize clarity and educational value
- Examples should be well-commented to aid learning
- Future topics include x86/64 assembly and microcontroller programming
