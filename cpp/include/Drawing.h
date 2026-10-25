#pragma once

namespace Drawing {
	extern bool isDrawing;

	int drawChoice(int sizeX, int sizeY, const std::vector<std::vector<bool>>& matrix);
}