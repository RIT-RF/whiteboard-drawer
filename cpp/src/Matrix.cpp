#include <vector>
#include <iostream>

#include "../Matrix.h"


namespace Matrix {
	static int SIZE_X = 0;
	static int SIZE_Y = 0;

	std::vector<std::vector<bool>> writeMatrix() {

		// Get dimensions of board from user
		std::cout << "Please enter the dimension of the board in inches.\n"
			<< "X dimension: ", std::cin >> SIZE_X;

		std::cout << "Y dimension: ", std::cin >> SIZE_Y;

		// Report the size of the matrix to the user.
		std::cout << "\nSize of X: " 
			<< SIZE_X
			<< "\nSize of Y: " 
			<< SIZE_Y
			<< std::endl;

		// Create the 2D vector with the user input size. Indices initialized to zero.
		std::vector<std::vector<bool>> matrix(SIZE_X, std::vector<bool>(SIZE_Y, -1));

		return matrix;
	}

	int getWidth() {
		return SIZE_X;
	}

	int getHeight() {
		return SIZE_Y;
	}
}