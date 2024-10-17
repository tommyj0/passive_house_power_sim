#pragma once

#include "load.h"
#include "battery.h"
#include "generator.h"
#include "common.h"


typedef enum {
	LOAD,
	GENERATOR,
	BATTERY
} NodeType;


typedef struct {
  Generator * generators[MAX_GEN];
	char gen_keys[MAX_GEN][40];
	int gen_count;
  Load * loads[MAX_LOAD];
	char load_keys[MAX_LOAD][40];
	int load_count;
  Battery * battery;
} System;


void print_System(System * sys);

extern System power_system;
