cmake_minimum_required(VERSION 3.22.1)

project(Qobloqc
    VERSION 0.1.0
    DESCRIPTION "this is the qobloqc client idk"
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCES
    src/main.cpp
    src/display.cpp
    src/generated/builtin_textures.cpp
    src/nodes.cpp
    src/node_map.cpp
    src/debug.cpp
    misc/icon.rc
    misc/info.rc
)

add_executable(Qobloqc "${SOURCES}")

target_include_directories(Qobloqc
    PRIVATE
        include
)

if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU" OR CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    target_link_options(Qobloqc PRIVATE -static-libgcc -static-libstdc++)
endif()

set_target_properties(Qobloqc
    PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/build"
)