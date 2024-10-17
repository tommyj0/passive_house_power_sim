#pragma once
#include "power_system.h"

typedef enum {
  NEITHER = 0,
  HOURLY = 1,
  MONTHLY = 2
} DataType;

void read_csv(const char *filename, NodeType type);