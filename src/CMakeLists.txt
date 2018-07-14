# CMakeList.txt : CMake project for InfixToPostfix, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

include_directories("../include")
file(GLOB SOURCES "./*.cpp")

# Add source to this project's executable.
add_executable (ktree ${SOURCES})

# TODO: Add tests and install targets if needed.
