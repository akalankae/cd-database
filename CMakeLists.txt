#
# CMakeLists.txt for cmake utility
#
cmake_minimum_required(VERSION 3.17.2)

# Name of the project
project("VTC_Course_Project" C)

# Include directory with header files for the project
include_directories(include)

# Create compile_commands.json file
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# All .c files in src/ dir are source files
# Adding using GLOB function
file(GLOB SOURCES "src/*.c")

# Name of the final program
add_executable(cddb ${SOURCES})
