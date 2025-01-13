//
// Created by wy on 24-11-14.
//
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define SIZE 6

const int board[SIZE][SIZE] = {
    {0},
    {0, 1, 1, 0, 0, 0},
    {0, 1, 1, 0, 0, 0},
    {0, 0, 0, 1, 1, 0},
    {0, 0, 0, 1, 1, 0},
    {0}
};

int main(void) {
  // expand the board
  int old_board[SIZE + 2][SIZE + 2] = {0};

  for (int i = 1; i <= SIZE; i++) {
    for (int j = 1; j < SIZE; ++j) {
      old_board[i][j] = board[i - 1][j - 1];
    }
  }

  for (int i = 1; i <= SIZE; i++) {
    for (int j = 1; j < SIZE; ++j) {
      printf("%c ", old_board[i][j] ? '*' : ' ');
    }
    printf("\n");
  }


    // old board => new board by applying the rules
  int new_board[SIZE + 2][SIZE + 2] = {0};

  for (int round = 1; round <= 10; round++){
    for (int i = 1; i <= SIZE; i++) {
      for (int j = 1; j <= SIZE; ++j) {
        int num_of_live_neighnours =
            old_board[i - 1][j - 1] + old_board[i - 1][j] +
            old_board[i - 1][j + 1] + old_board[i][j - 1] + old_board[i][j + 1] +
            old_board[i + 1][j - 1] + old_board[i + 1][j] +
            old_board[i + 1][j + 1];

        if (old_board[i][j]) {
          new_board[i][j] =
              num_of_live_neighnours == 2 || num_of_live_neighnours == 3;
        } else {
          new_board[i][j] = num_of_live_neighnours == 3;
        }
      }
    }
    for (int i = 1; i <= SIZE; i++) {
      for (int j = 1; j <= SIZE; ++j) {
        printf("%c ", new_board[i][j] ? '*' : ' ');
      }
      printf("\n");
    }
    // Linux: unistd.h
    // Windows: windows.h (Sleep(ms))
    sleep(1);
    system("clear");

    for (int i = 1; i <= SIZE; i++) {
      for (int j = 1; j < SIZE; ++j) {
        old_board[i][j] = new_board[i][j];
      }
    }
  }
  // for each cell, count the number of live cells
  return 0;
}