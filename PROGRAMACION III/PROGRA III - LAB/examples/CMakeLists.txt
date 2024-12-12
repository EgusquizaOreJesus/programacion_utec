# Setup the project and settings
project(examples)

cmake_minimum_required(VERSION 3.23)
# Directories that contain examples
set(example_dirs
        audio
        core
        models
        others
        shaders
        shapes
        text
        textures
        )

set(CMAKE_REQUIRED_DEFINITIONS -D_POSIX_C_SOURCE=199309L)

include(CheckSymbolExists)
check_symbol_exists(CLOCK_MONOTONIC time.h HAVE_CLOCK_MONOTONIC)
check_symbol_exists(QueryPerformanceCounter windows.h HAVE_QPC)
set(CMAKE_REQUIRED_DEFINITIONS)

if (HAVE_QPC OR HAVE_CLOCK_MONOTONIC)
    set(example_dirs ${example_dirs} physac)
endif ()
add_executable(${example_name} ${example_source} main.cpp)
include_directories(BEFORE SYSTEM others/external/include)
# Copy all of the resource files to the destination
file(COPY ${example_resources} DESTINATION "resources/")