//
// Created by wy on 23-11-1.
//

#include <stdio.h>
int main(void) {
  int a = 0;
  int b = 0;
  int min = 0;

  scanf("%d%d", &a, &b);
  
  if (a < b) {
    min = a;
  } else {
    min = b;
  }

  printf("min(%d, %d) = %d\n", a, b, min);

  return 0;

}