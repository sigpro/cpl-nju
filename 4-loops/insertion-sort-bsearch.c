//
// Created by wy on 24-12-11.
//
//
// Created by wy on 24-12-11.
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LEN 10000
#define RANGE 10

int main(void) {
  int numbers[MAX_LEN] = {0};

  int size = 0;
  scanf("%d", &size);

  srand(time(NULL));
  for (int i = 0; i < size; i++){
    numbers[i] = rand() % RANGE;
  }

  for (int i = 0; i < size; i++){
    printf("%d", numbers[i]);
  }
  printf("\n");

  for (int i = 1; i < size; i++) {
    int key = numbers[i];

    int low = 0;
    int high = i - 1;

    while (low <= high) {
      int mid = low + (high - low)/ 2;
      if (numbers[mid] <= key) {
        low = mid + 1;
      } else if (numbers[mid] > key) {
        high = mid - 1;
      }
    }

    for (int j = i - 1; j >= low; j--) {
      numbers[j + 1] = numbers[j];
    }
    numbers[low] = key;
    for (int i = 0; i < size; i++){
      printf("%d", numbers[i]);
    }
    printf("\n");
  }



  for (int i = 0; i < size; i++){
    printf("%d", numbers[i]);
  }
  printf("\n");

  return 0;
}