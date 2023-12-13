//
// Created by wy on 23-10-19.
//

#include <stdio.h>

int main(void) {
  const double PI = 3.14159;
  int radius = 100;

  double surface_area = 4 * PI * radius * radius;
  double volume = 4.0 / 3 * PI * radius * radius;

  printf("%-15.4f: surface area\n%-15.4f: volume\n", surface_area, volume);
  return 0;
}