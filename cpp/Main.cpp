#include <vector>
#include <iostream>

#include "include/Matrix.h"
#include "include/Drawing.h"

int main() {
	// Matrix
	using namespace Matrix;
	const std::vector<std::vector<bool>> matrix = writeMatrix();

	int width = getWidth();

	int height = getHeight();

	// Drawing
	using namespace Drawing;
		drawChoice(width, height, matrix); // Using Namespace

	return 0;
}