//
// Created by wy on 24-10-25.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INITIAL_SIZE 10
#define BUFFER_SIZE 1024

int main(void) {

  int *numbers = malloc(INITIAL_SIZE * sizeof(int));  // 动态分配初始空间
  int capacity = INITIAL_SIZE;
  int count = 0;
  char buffer[BUFFER_SIZE];

  if (numbers == NULL) {
    printf("内存分配失败\n");
    return 1;
  }

  printf("请输入任意数量的整数，用空格分隔，然后按 Enter：\n");

  // 读取整行输入
  if (fgets(buffer, BUFFER_SIZE, stdin) != NULL) {
    char *ptr = buffer;
    char *endptr;

    while (*ptr != '\0') {
      // 使用 strtol 将字符串转换为整数
      int num = strtol(ptr, &endptr, 10);

      // 检查是否成功解析了一个整数
      if (ptr == endptr) {
        break;  // 没有更多的整数
      }

      // 存储解析的整数
      if (count >= capacity) {  // 如果容量不够，扩展容量
        capacity *= 2;
        int *temp = realloc(numbers, capacity * sizeof(int));
        if (temp == NULL) {
          printf("内存扩展失败\n");
          free(numbers);
          return 1;
        }
        numbers = temp;
      }
      numbers[count++] = num;

      // 移动指针到下一个可能的整数位置
      ptr = endptr;
    }
  } else {
    printf("读取输入失败。\n");
    free(numbers);
    return 1;
  }

  printf("\n你输入的数字是：\n");
  for (int i = 0; i < count; i++) {
    printf("%d ", numbers[i]);
  }
  printf("\n");


  for(int i = 0; i < count; i++){
    int min = numbers[i];
    int min_index = i;
    for(int j = i+1; j < count; j++){
      if(numbers[j] < min){
        min = numbers[j];
        min_index = j;
      }
    }
    int temp = numbers[min_index];
    numbers[min_index] = numbers[i];
    numbers[i] = temp;
  }
  printf("\n排序后的数字是：\n");
  for (int i = 0; i < count; ++i) {
    printf("%d ", numbers[i]);
  }
  free(numbers);
  return 0;
}