#include <iostream>

#include "../Matrix.h"
#include "../Drawing.h"

namespace Drawing {
	bool isDrawing = false;

	int drawChoice(int sizeX, int sizeY, const std::vector<std::vector<bool>>& matrix) {
			using namespace Matrix;

		int step = 0;

		for (int x = 0; x < sizeX; ++x) {
			for (int y = 0; y < sizeY; ++y) {

				int cellValue = matrix[x][y];

				if (cellValue > 0) {
					isDrawing = true;

					std::cout << "Index "
						<< step
						<< ": contains the drawing!"
						<< std::endl;
				}
				else {
					std::cout << "Index "
						<< step
						<< ": does not contain the drawing!"
						<< std::endl;
				};

				++step;
			}
		}
		// Insert new line for next print
		std::cout << "\n"
			<< std::endl;

		return isDrawing;
	}
}