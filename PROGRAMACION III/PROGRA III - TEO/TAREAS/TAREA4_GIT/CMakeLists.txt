cmake_minimum_required(VERSION 3.10.2)
project(prog3_complejidad_algoritmica_v2023_0)

set(CMAKE_CXX_STANDARD 20)
if(UNIX AND NOT APPLE)
    SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")
endif()

include_directories(./src)
file(GLOB source_files
        main.cpp
        src/*.h
        src/*.cpp)

add_executable(${PROJECT_NAME}
        ${source_files}
    )

if(UNIX AND NOT APPLE)
    find_package(TBB)
    target_link_libraries(${PROJECT_NAME} TBB::tbb)
endif()

