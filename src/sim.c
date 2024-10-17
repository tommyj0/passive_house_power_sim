#include "power_system.h"
#include "utils.h"

void run_Simulation(System system, int sim_length_days) {
  float total_power = 0;

  for (int day = 0; day < sim_length_days; ++day) {
    int month = find_month(day);
    for (int hour = 0; hour < HOURS; ++hour) {
      float hour_power = 0;
      for (int gens = 0; gens < system.gen_count; ++gens) {
        hour_power += system.generators[gens]->hourly_gen[month][hour];
      }
      for (int loads = 0; loads < system.load_count; ++loads) {
        hour_power -= system.generators[loads]->hourly_gen[month][hour];
      }
    }
  }
}
