#include <iostream>

#include "../Matrix.h"
#include "../Motors.h"

namespace Motors {
	namespace motor1 {
		bool isRunning = false;

		int rotationDirection(int sizeX, int sizeY, const std::vector<std::vector<bool>>& matrix) {
			using namespace Matrix;

			int z = 0;

			for (int x = 0; x < sizeX; ++x) {
				for (int y = 0; y < sizeY; ++y) {

					int cellValue = matrix[x][y];

					if (cellValue > 0) {
						isRunning = true;

						std::cout << "Step "
							<< z
							<< " Motor 1 is running!"
							<< std::endl;
					}
					else {
						std::cout << "Step "
							<< z
							<< ": Motor 1 is not running!"
							<< std::endl;
					};

					++z;
				}
			}
			// Insert new line for next print
			std::cout << "\n"
				<< std::endl;

			return isRunning;
		}
	}
	namespace motor2 {
		bool isRunning = false;

		int rotationDirection(int sizeX, int sizeY, const std::vector<std::vector<bool>>& matrix) {
			using namespace Matrix;

			int z = 0;

			for (int x = 0; x < sizeX; ++x) {
				for (int y = 0; y < sizeY; ++y) {

					int cellValue = matrix[x][y];

					if (cellValue > 0) {
						isRunning = true;

						std::cout << "Step "
							<< z
							<< ": Motor 2 is running!"
							<< std::endl;
					}
					else {
						std::cout << "Step "
							<< z
							<< " Motor 2 is not running!"
							<< std::endl;
					};

					++z;
				}
			}

			return isRunning;
		}
	}
}