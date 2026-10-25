#include <vector>

#include "../include/Motors.h"
#include "../include/LimitSwitch.h"

// Lengths based on material used for framing
constexpr int LENGTH_X = 50;
constexpr int LENGTH_Y = 50;

// Defining limit switch calculations for homing 
namespace LimitSwitch {
	namespace LimitMotor {

	}

	namespace LimitSide {
		static bool Orient() {
			bool X = (LENGTH_X != 0);

			return X;
		}
	}
}

// Defining rotation direction and instructions for motors
namespace Motors {
	namespace Motors1 {
		static int rotationDirection(int sizeX, int sizeY, const std::vector<std::vector<bool>>& matrix) {
			
		}
	}

	namespace Motors2 {
		static int rotationDirection(int sizeX, int sizeY, const std::vector<std::vector<bool>>& matrix) {

		}
	}
}