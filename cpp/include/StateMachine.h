#pragma once

#include <cstdint>

enum class StateMachine : uint8_t {
	HOMING,
	IDLE,
	RUNNING,
	ERROR,
	SHUTDOWN
};
