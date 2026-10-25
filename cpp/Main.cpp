#include <vector>
#include <iostream>

#include "Matrix.h"
#include "Motors.h"

int main() {
	// Matrix
	using namespace Matrix;
	const std::vector<std::vector<bool>> matrix = writeMatrix();

	int width = getWidth();

	int height = getHeight();

	// Motors
	Motors::motor1::rotationDirection(width, height, matrix); // Using Namespace

	Motors::motor2::rotationDirection(width, height, matrix); // Using Namespace

	return 0;
}