cmake_minimum_required(VERSION 4.0.2)
project(my_LogSystem)
set(CMAKE_CXX_STANDARD 11)

# link the head files with source files
include_directories(${PROJECT_SOURCE_DIR}/include)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

aux_source_directory(${PROJECT_SOURCE_DIR}/src SRC_LIST)

# make the source files to exe file
add_executable(
    my_LogSystem
    ${SRC_LIST}
)