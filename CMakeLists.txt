cmake_minimum_required(VERSION 3.10)
project(open-babel-symmetry LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake/modules)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

find_package(OpenBabel3 REQUIRED)
include_directories(${OpenBabel3_INCLUDE_DIRS})
# Add executable
add_executable(main src/main.cpp)

add_subdirectory(src)

# Include directories
# target_include_directories(grid_lib PUBLIC ${PROJECT_SOURCE_DIR}/include)

# Link raylib and other libraries to your project
target_link_libraries(main ${OpenBabel3_LIBRARIES})

target_compile_features(main PRIVATE cxx_std_11)
