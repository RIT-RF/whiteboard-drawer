/*******************************************************
* File Name:
*
* Author: Trennan "Mola RF" Tewksbury
*
* Purpose:
*
*******************************************************/

#pragma once

#include <string>
#include <gpiod.hpp>

/*
class Pin {
private:
	int pinNumber;
	bool isOutputConfig;

	gpiod::chip Chip;
	gpiod::line Line;
	std::string consumerName;
public:
	//Constructor takes the physics GPIO offset and a label for 'gpioinfo'
	Pin(int pinNum, const std::string& consumer = "WPlot-Pin", const std::string& chipName = "gpiochip4");
	~Pin();

	// Config methods
	void configAsOut(int initialValue = 0);
	void configAsIn();

	//State control
	void set(int value);
	int get() const;
	void toggle();
};
*/