#include <vector>
#include <fstream>
#include <iostream>


#include "../include/Matrix.h"


namespace Matrix {

	std::vector<std::vector<bool>> writeMatrix(const int x,const int y) {


		// Create the 2D vector with the user input size. Indices initialized to zero.
		std::vector<std::vector<bool>> matrix(x, std::vector<bool>(y, 0));

		return matrix;
	}
}