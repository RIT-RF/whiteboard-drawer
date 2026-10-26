#pragma once

#include <cstdint>

enum class StateMachine : std::uint8_t {
	HOMING,
	IDLE,
	RUNNING,
	ERROR,
	SHUTDOWN
};
