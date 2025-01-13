//
// Created by wy on 24-10-25.
//
#include <stdio.h>

int main(void) {
  int number = 0;
  scanf("%d", &number);

  int num_of_digits = 0;

  // For loop version
  for (; number > 0 || num_of_digits == 0; number /= 10) {
    num_of_digits++;
  }

  printf("Number of digits: %d\n", num_of_digits);

  return 0;
}
