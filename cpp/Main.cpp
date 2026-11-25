#include <vector>
#include <iostream>

#include "include/Matrix.hpp"
#include "include/Drawing.hpp"

int main() {
	/*
	// Matrix
	using namespace Matrix;

	constexpr int SIZE_X = 1250;
	constexpr int SIZE_Y = 1000;

	const std::vector<std::vector<bool>>& matrix = writeMatrix(SIZE_X, SIZE_Y);

	// Drawing
	using namespace Drawing;
		drawChoice(SIZE_X, SIZE_Y, matrix); // Using Namespace
	*/
	return 0;
}

/*
#include <chrono>
#include <vector>
#include <random>
#include <iostream>
#include <algorithm>

#include "Matrix.hpp"

int main(void) {
	auto seed = std::chrono::system_clock::now().time_since_epoch().count();

	std::mt19937_64 gen(seed);

	std::vector<std::vector<int>>Matrix(ROWS, std::vector<int>(COLS, 0));

	matrixPopulate(Matrix, ROWS, COLS, gen);

	optimizedSearch(Matrix, ROWS-1, COLS-1);

	for (size_t i = 0; i < ROWS; i++) {
		for (size_t j = 0; j < COLS; j++) {
			std::cout
				<< Matrix[i][j]
				<< " "
				<< "\n"
				<< std::endl;
		}
	}

	return 0;

}

std::vector<std::vector<int>> matrixPopulate(std::vector<std::vector<int>>& matrix, int rows, int cols, std::mt19937_64& gen) {
	std::uniform_int_distribution<int> dist(0, 1);

	for (size_t i = 0; i < rows; i++) {
		for (size_t j = 0; j < cols; j++) {
			matrix[i][j] = dist(gen);
		}
	}
	return matrix;
}

std::vector<std::vector<int>> optimizedSearch(std::vector<std::vector<int>>& matrix, const int row, const int col) {
	int r = row;
	int c = col;

	// Step 1: Loop through the matrix until all 1s are set to 0s
	while (!isZero(matrix)) {
		// Direction counters
		std::vector<int> dirCounts(8, 0); // 0. Up, 1. Down, 2. Right, 3. Left, 4. Right-Up, 5. Left-Down, 6. Right-Down, 7. Left-Up

		int val = 0; // Current value of matrix position
		int index = 0; // Holds the index of direction

		// Row Holders
		std::vector<int> rowHolders(8, r); // 0. Up Row Holder, 1. Down Row Holder, 2. Right Row Holder, 3. Left Row Holder, 4. Right-Up Row Holder, 5. Left-Down Row Holder, 6. Right-Down Row Holder, 7. Left-Up Row Holder

		// Column Holders
		std::vector<int> colHolders(8, c); // 0. Up Column Holder, 1. Down Column Holder, 2. Right Column Holder, 3. Left Column Holder, 4. Right-Up Column Holder, 5. Left-Down Column Holder, 6. Right-Down Column Holder, 7. Left-Up Column Holder

		// For final count in each direction
		int dir = 0;

		for (size_t i = 1; i <= std::max(row, col); i++) {
			val = matrix[r][c];

			// Step 2. Check for 1s in all 8 directions and count them, while also storing the last row and column positions of each direction
			if (isValid(row, r - i, col, c) && (matrix[r - i][c] == 1)) {	// 0. Checks for the upward Y-direction
				rowHolders[0] = r - i;
				dirCounts[0]++;
			}

			if (isValid(row, r + i, col, c) && (matrix[r + i][c] == 1)) {	// 1. Checks for the downward Y-direction
				rowHolders[1] = r + i;
				dirCounts[1]++;
			}

			if (isValid(row, r, col, c + i) && (matrix[r][c + i] == 1)) {	// 2. Checks for the right X-direction
				colHolders[2] = c + i;
				dirCounts[2]++;
			}

			if (isValid(row, r, col, c - i) && (matrix[r][c - i] == 1)) {	// 3. Checks for the left X-direction
				colHolders[3] = c - i;
				dirCounts[3]++;
			}

			if (isValid(row, r - i, col, c + i) && (matrix[r - i][c + i] == 1)) {	// 4. Checks for the right-up diagonal
				rowHolders[4] = r - i;
				colHolders[4] = c + i;
				dirCounts[4]++;
			}

			if (isValid(row, r + i, col, c - i) && (matrix[r + i][c - i] == 1)) {	// 5. Checks for the left-down diagonal
				rowHolders[5] = r + i;
				colHolders[5] = c - i;
				dirCounts[5]++;
			}

			if (isValid(row, r + i, col, c + i) && (matrix[r + i][c + i] == 1)) {	// 6. Checks for the right-down diagonal
				rowHolders[6] = r + i;
				colHolders[6] = c + i;
				dirCounts[6]++;
			}

			if (isValid(row, r - i, col, c - i) && (matrix[r - i][c - i] == 1)) {	// 7. Checks for the left-up diagonal
				rowHolders[7] = r - i;
				colHolders[7] = c - i;
				dirCounts[7]++;
			}
		}

		// Step 3: Determines direction, row, column, and sets 1s to 0s
		if (						// Checks for a direction count > 0
			dirCounts[0] > 0 ||
			dirCounts[1] > 0 ||
			dirCounts[2] > 0 ||
			dirCounts[3] > 0 ||
			dirCounts[4] > 0 ||
			dirCounts[5] > 0 ||
			dirCounts[6] > 0 ||
			dirCounts[7] > 0
			) {

				// Step 4: Loops through the direction counts and sets the 1s to 0s in the matrix
			for (size_t i = 0; i < dirCounts.size(); i++) {
				if (dirCounts[i] > dir) {
					dir = dirCounts[i];
					index = i;
				}
			}

			matrix[r][c] = 0; // Sets the current position to 0

			// Step 5: Determines direction and sets the 1s to 0s in the matrix
			while (r != rowHolders[index] || c != colHolders[index]) {
				switch (index) {
				case 0:
					matrix[r--][c] = 0; // 0. up Y-direction
					break;
				case 1:
					matrix[r++][c] = 0; // 1. down Y-direction
					break;
				case 2:
						matrix[r][c++] = 0; // 2. right X-direction
					break;
				case 3:
					matrix[r][c--] = 0; // 3. left X-direction
					break;
				case 4:
					matrix[r--][c++] = 0; // 4. right-up diagonal
					break;
				case 5:
					matrix[r++][c--] = 0; // 5. left-down diagonal
					break;
				case 6:
					matrix[r++][c++] = 0; // 6. right-down diagonal
					break;
				case 7:
					matrix[r--][c--] = 0; // 7. left-up diagonal
					break;
				}

				matrix[r][c] = 0; // Sets the current position to 0
			}

			r = rowHolders[index];
			c = colHolders[index];
		}
		else {
			// Finds hanging 1s and goes there
			matrix[r][c] = 0;
			bool found = false;

			for (size_t i = 0; i < row && !found; i++) {
				for (size_t j = 0; j < col && !found; j++) {
					if (matrix[i][j] == 1) {
						r = i;
						c = j;
						found = true;
						break;
					}
				}
			}
		}
	}
	return matrix;
}

bool isValid(int row, int next_row, int col, int next_col) {
	if (next_row < 0 || next_row >= ROWS || next_col < 0 || next_col >= COLS) {
		return false;
	}
	return true;
}

bool isZero(std::vector<std::vector<int>>& matrix) {
	for (const auto& row : matrix) {
		if (!std::all_of(row.begin(), row.end(), [](int val) { return val == 0; })) {
			return false;
		}
	}
	return true;
}
*/