
#include "common.h"
#include "battery.h"
#include "power_system.h"

void create_Battery(const float capacity) {
  Battery *inst_bat = malloc(sizeof(Battery));
  inst_bat->capacity = capacity;
  inst_bat->charge = capacity;
  power_system.battery = inst_bat;
  return;
}

void print_BatteryLevel(Battery *bat) {
  if (bat == NULL) {
    printf("ERR: battery struct doesn't exist.");
  } else {
    printf("Battery capactiy: %f, battery level: %f\n", bat->capacity,
           bat->charge);
  }
}
