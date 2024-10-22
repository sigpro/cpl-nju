//
// Created by wy on 24-10-17.
//
#include <stdbool.h>
#include <stdio.h>

int main(void) {
  int max = 0;
  scanf("%d", &max);
  int count = 0;
  for (int i=2; i<=max; i++) {
    // decide if i is a prime
    // C99: _Bool
    bool isPrime = true;
    if (i <= 1) {
      isPrime = 0;
    } else {
      for (int j = 2; j * j <= i; j++){
        if (i % j == 0){
          isPrime = 0;
          break;
        }
      }
    }

    if (isPrime) {
      count++;
//      printf("%d ", i);
    }

  }
  printf("\nTotal prime numbers: %d\n", count);
  return 0;
}