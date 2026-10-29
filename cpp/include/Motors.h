/*******************************************************
* File Name: Motors.h
* 
* Author: Trennan "MolaRF" Tewksbury
* 
* Purpose: This file contains the class definitions for
* the motors of the whiteboard-drawer project.
* 
*******************************************************/

#pragma once

#include "Matrix.h"

namespace Motors {
	namespace motor1 {
		extern bool isRunning;
		extern int rotation(int sizeX, int sizeY, const std::vector<std::vector<bool>>& matrix); // -1 = clockwise, 1 = counter-clockwise, 0 = static
	};

	namespace motor2 {
		extern bool isRunning;
		extern int rotation(int sizeX, int sizeY, const std::vector<std::vector<bool>>& matrix); // -1 = clockwise, 1 = counter-clockwise, 0 = static
	};
}
