/*******************************************************
* File Name: Motors.h
* 
* Author: Trennan "Mola RF" Tewksbury
* 
* Purpose: This file contains the class definitions for
* the motors of the RF Project.
* 
*******************************************************/

#pragma once

#include <gpiod.hpp>

#include "Pins.hpp"
#include "Matrix.hpp"

/*
class Motor {
private:
	long currentPosition;

	Pin stepPin;
	Pin dirPin;

public:
	// Constructor to initialize pins for each motor
	Motor(int sPin, int dPin);

	// Finding location of next step
	void stepTo(int targetPosition);

	// Getting current position of the motor
	int getCurrentPosition() const;
};
*/