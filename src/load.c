
#include "load.h"
#include "power_system.h"

void create_Load(const char *key, float (*load_in)[HOURS]) {
  Load *load = malloc(sizeof(Load));
  strncpy(load->key, key, sizeof(load->key));
  strncpy(power_system.load_keys[power_system.load_count], key,
          sizeof(power_system.load_keys[power_system.load_count]));
  // memcpy(load->hourly_load, load_in, HOURS * MONTHS * sizeof(float));
  load->hourly_load = load_in;
  power_system.loads[power_system.load_count] = load;
  power_system.load_count++;
  return;
}

void print_Load(Load *load) {
  if (load == NULL) {
    printf("ERR: appliance struct doesn't exist.");
  } else {
    printf("Load key: %s\n", load->key);
    for (int i = 0; i < MONTHS; ++i) {
      for (int j = 0; j < HOURS; ++j) {
        printf("Month %d Hour %d load: %.2f W\t", i, j, (load->hourly_load)[i][j]);
      }
      printf("\n");
    }
  }
}
