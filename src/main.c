
#include "power_system.h"
#include "read_csv.h"
#include "utils.h"

float wind_speed_monthly[12] = {
    17, 14, 15, 11, 14, 10,
    10, 12, 11, 12, 15, 16}; // knots, variation in wind speed over the year

float gen[HOURS * DAYS] = {0};  // W
float load[HOURS * DAYS] = {0}; // W
float hourly_load_fridge[HOURS] = {1,  2,  3,  4,  5,  6,  7,  8,
                                   9,  10, 11, 12, 13, 14, 15, 16,
                                   17, 18, 19, 20, 21, 22, 23, 24}; // W
float hourly_gen_solar[HOURS] = {24, 23, 22, 21, 20, 19, 18, 17,
                                 16, 15, 14, 13, 12, 11, 10, 9,
                                 8,  7,  6,  5,  4,  3,  2,  1}; // W
float monthly_load_fridge[MONTHS] = {1, 2, 3, 4,  5,  6,
                                     7, 8, 9, 10, 11, 12};                 // W
float monthly_gen_solar[MONTHS] = {12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1}; // W

int main() {
  normalise_arr(&wind_speed_monthly[0], 12,
                7.5); // normalise and convert to m/s
  create_Battery(100);
  print_BatteryLevel(power_system.battery);
  print_System(&power_system);
  read_csv("generators.csv", GENERATOR);
  print_Generator(power_system.generators[0]);
}
