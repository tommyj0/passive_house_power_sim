#pragma once

#include "common.h"

typedef struct {
	char key[MAX_KEY]; 
	float (*hourly_load)[HOURS]; // W
} Load;

void create_Load(const char *key, float (*load_in)[HOURS]);

void print_Load(Load * load);

