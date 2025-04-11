# version monimum de cmake
cmake_minimum_required(VERSION 3.16)

#nom du projet
project(Numcy-cpp)

# version du g++
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# création de la lib
add_library(numcy INTERFACE)   

# Inclure les headers
target_include_directories(numcy INTERFACE 
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)


# Executable
add_executable(example examples/example.cpp)

# Lier avec la lib numcy
target_link_libraries(example PRIVATE numcy)