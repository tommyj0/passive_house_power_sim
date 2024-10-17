
#include "power_system.h"
#include "common.h"
#include "generator.h"


void print_Generator(Generator *gen) {
  if (gen == NULL) {
    printf("ERR: generator struct doesn't exist.");
  } else {
    printf("Generator key: %s\n", gen->key);
    for (int i = 0; i < MONTHS; ++i) {
      for (int j = 0; j < HOURS; ++j) {
        printf("Month %d, Hour %d, generation: %.2f W\t", i, j,
               (gen->hourly_gen)[i][j]);
      }
    }
    printf("\n");
  }
}

void create_Generator(const char *key, float (*hourly_gen)[HOURS]) {
  Generator *gen = malloc(sizeof(Generator));
  strncpy(gen->key, key, sizeof(gen->key));
  strncpy(power_system.gen_keys[power_system.gen_count], key,
          sizeof(power_system.gen_keys[power_system.gen_count]));
  // memcpy(gen->hourly_gen, hourly_gen, HOURS * MONTHS * sizeof(float));
  gen->hourly_gen = hourly_gen;
  power_system.generators[power_system.gen_count] = gen;
  power_system.gen_count++;
  return;
}
