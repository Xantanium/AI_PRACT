cmake_minimum_required(VERSION 3.10)
project(AI_PRACT)

set(CMAKE_CXX_STANDARD 17)

# Find all .cpp files in the directory
file(GLOB CPP_FILES *.cpp)

# Loop through each file and create an executable
foreach(SRC_FILE ${CPP_FILES})
    get_filename_component(EXE_NAME ${SRC_FILE} NAME_WE)
    add_executable(${EXE_NAME} ${SRC_FILE})
endforeach()
