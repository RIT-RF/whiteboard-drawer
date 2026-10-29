#include <vector>
#include <iostream>

#include "include/Matrix.h"
#include "include/Drawing.h"

int main() {
	// Matrix
	using namespace Matrix;

	constexpr int SIZE_X = 1250;
	constexpr int SIZE_Y = 1000;

	const std::vector<std::vector<bool>>& matrix = writeMatrix(SIZE_X, SIZE_Y);

	// Drawing
	using namespace Drawing;
		drawChoice(SIZE_X, SIZE_Y, matrix); // Using Namespace

	return 0;
}