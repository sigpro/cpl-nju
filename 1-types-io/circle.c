//
// Created by wy on 23-10-19.
//

#include <stdio.h>

int main(void) {
  int radius = 10;
  const double PI = 3.14159;

  double area = PI * radius * radius;
  double circumference = 2 * PI * radius;

  printf("radius = %d\nciucumference = %.2f\narea = %.2f\n",
         radius, circumference, area);
  return 0;
}