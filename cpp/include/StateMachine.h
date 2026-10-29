#pragma once

enum class StateMachine {
	BOOT,
	HOMING,
	IDLE,
	RUNNING,
	ERROR
};