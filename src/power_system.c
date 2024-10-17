#include "power_system.h"
#include "csv.h"
#include "read_csv.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

System power_system = {};

void print_System(System *sys) {
  if (sys == NULL) {
    printf("ERR: system struct doesn't exist.");
  } else {
    printf("Generators (%d): ", sys->gen_count);
    for (int i = 0; i < sys->gen_count; ++i) {
      printf("%s, ", sys->gen_keys[i]);
    }
    printf("\nLoads (%d): ", sys->load_count);
    for (int i = 0; i < sys->load_count; ++i) {
      printf("%s, ", sys->load_keys[i]);
    }
    printf("\nBattery capacity: %f, battery level: %f\n",
           sys->battery->capacity, sys->battery->charge);
  }
}

