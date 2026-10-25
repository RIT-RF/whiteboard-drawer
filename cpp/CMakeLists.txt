cmake_minimum_required(VERSION 3.16)
project(RFProject)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Define the executable target and explicity list source files
add_executable(Motors
	Main.cpp
	src/Motors.cpp
	src/Matrix.cpp
)