//
// Created by wy on 23-10-13.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(void) {
  /*
   * print the rule
   */
  int chance = 7;
  printf("The computer will generate a random number.\n"
      "You have %d chances\n", chance);
  int high = 100;
  int secret = 0;
  int guess = 0;

  /*
   * choose a random number between 1 and high
   */
  srand(time(NULL));
  secret = rand() % high + 1;
  printf("%d\n", secret);


  while (chance > 0) {
    printf("Please enter your guess.\n");
    scanf("%d", &guess);
    if (guess == secret) {
      printf("You Win!\n");
      break;
    } else if (guess > secret) {
      printf("guess > secret\n");
    } else {
      printf("guess < secret\n");
    }
    chance -= 1;
  }

  return 0;
}