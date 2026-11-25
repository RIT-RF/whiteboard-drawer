cmake_minimum_required(VERSION 3.16)
project(RFProject LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Define the executable target and explicity list source files
add_executable(WPlot
	Main.cpp
	src/Pins.cpp
	src/Server.cpp
	src/Matrix.cpp
	src/Motors.cpp
	src/Drawing.cpp
	src/StateMachine.cpp
 "include/httplib.h")