cmake_minimum_required(VERSION 3.28)

project(VanK VERSION 1.0)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 20)

# Add the subdirectories for the static library and the application
add_subdirectory(VanK)
add_subdirectory(SandBox)