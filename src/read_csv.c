#include "read_csv.h"
#include "csv.h"
#include "power_system.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void read_csv(const char *filename, NodeType type) {

  float (*read_hourly)[HOURS] = malloc(HOURS * MONTHS * sizeof(float)); // INDEX USING hourly[MONTH][HOUR]
  char *row;

  int rows = 0;
  printf("Reading CSV file %s\n", filename);
  CsvHandle handle = CsvOpen("res/generators.csv");

  while ((row = CsvReadNextRow(handle))) {
    int cols = 0;
    printf("Row #%d: %s\n", rows, row);
    /* row = CSV row string */
    const char *key;
    const char *col;
    while ((col = CsvReadNextCol(row, handle))) {
      switch (cols) {
      case 0:
        key = col;
        break;
      default:
        read_hourly[rows ][cols - 1] = atof(col);
        break;
      }
      cols++; /* col = CSV col string */
      printf("Col: %.2f\n", atof(col));
    }
    rows++;

    if (rows % 12 == 0) {
      switch (type) {
      case GENERATOR:
        printf("creating generator: %s\n", key);
        create_Generator(key, read_hourly);
        break;
      case LOAD:
        printf("creating load: %s\n", key);
        create_Load(key, read_hourly);
        break;
      default:
        printf("ERR: Node Type not recognised\n");
        break;
      }
    }
  }
}
