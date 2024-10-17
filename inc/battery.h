#pragma once

typedef struct {
	float capacity; // kWh
	float charge; // kWh
} Battery;

void create_Battery(const float capacity);

void print_BatteryLevel(Battery * bat);

