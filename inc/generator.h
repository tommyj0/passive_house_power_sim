#pragma once
#include "common.h"

typedef struct {
	char key[MAX_KEY];
	float (*hourly_gen)[HOURS]; // W
} Generator;

void print_Generator(Generator * gen);

void create_Generator(const char *key, float (*hourly_gen)[HOURS]);

