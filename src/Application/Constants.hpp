#pragma once

namespace HardwarePins {
	constexpr int SHFT_REG_LATCH = 9;
	constexpr int SHFT_REG_CLOCK = 11;
	constexpr int SHFT_REG_DATA	 = 12;
	constexpr int MOTOR_REVERSE	 = 5;
	constexpr int MOTOR_FORWARDS = 6;
}  // namespace HardwarePins

// flush pin is the same

namespace DefaultTimes {
	const int FLUSH_TIME  = 20;
	const int SAMPLE_TIME = 20;
	const int IDLE_TIME	  = 3600 - FLUSH_TIME - SAMPLE_TIME;
}  // namespace DefaultTimes

namespace TPICDevices {
	constexpr int INTAKE_POS	= 0;
	constexpr int INTAKE_NEG	= 1;
	constexpr int AIR_VALVE		= 2;
	constexpr int ALCOHOL_VALVE = 3;
	constexpr int FLUSH_VALVE	= 5;
}  // namespace TPICDevices

namespace Shift {
	constexpr int FIRST_SAMPLE_VALVE = 8;
}