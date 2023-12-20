//
// Created by wy on 23-12-13.
//

#include <stdio.h>
int main(void){
  int year = 0;
  scanf("%d", &year);

  int leap = 0;

  if (year % 4 == 0) {
    if (year % 100 == 0) {
      if (year % 400 == 0) {
        leap = 1;
      } else {
        leap = 0;
      }
    } else {
      leap = 1;
    }
  } else {
    leap = 0;
  }

  if (leap == 0) {
    printf("%d is a common year\n", year);
  } else {
    printf("%d is a leap year\n", year);
  }

  return 0;
}