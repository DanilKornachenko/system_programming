#include "part1.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int randint(unsigned int min, unsigned int max)
{
  return min + rand() / (RAND_MAX / (max - min + 1) + 1);
}

void part1()
{
  int* num = (int*)malloc(sizeof(int));
  *num = 5;
  printf("%d\n", *num);
  free(num);
}

void part2()
{
  int* array = (int*)malloc(sizeof(int) * 10);
  for (int i = 0; i < 10; i++)
  {
    array[i] = i;
  }

  for (int i = 0; i < 10; i++)
  {
    printf("%d ", array[i]);
  }
  putc('\n', stdout);
}

void part3()
{
  char* string = (char*)malloc(sizeof(char) * 50);
  char input[50];
  scanf("%s", input);

  strcpy(string, input);
  string[49] = '\0';
  printf("%s\n", string);
  free(string);
}

void part4()
{
  float* array = (float*)calloc(5, sizeof(float));
  for (int i = 0; i < 5; i++)
  {
    printf("%f ", array[i]);
  }
  putc('\n', stdout);
  free(array);
}

void part5()
{
  int* array1 = (int*)calloc(10, sizeof(int));
  int* array2 = (int*)calloc(10, sizeof(int));

  for (int i = 0; i < 10; i++)
  {
    array1[i] = i;
    array2[i] = 10 - i;
  }

  // Копирование
  for (int i = 0; i < 10; i++)
  {
    array1[i] = array2[i];
  }

  printf("array1 = ");
  for (int i = 0; i < 10; i++)
  {
    printf("%d ", array1[i]);
  }

  printf("\narray2 = ");
  for (int i = 0; i < 10; i++)
  {
    printf("%d ", array2[i]);
  }

  putc('\n', stdout);

  free(array1);
  free(array2);
}

void part6()
{
  printf("Выбери размер матрицы:\n");
  int M, N;
  scanf("%d %d", &M, &N);
  int** matrix = (int**)calloc(M, sizeof(int*));
  for (int i = 0; i < 3; i++)
  {
    matrix[i] = (int*)calloc(N, sizeof(int));
  }

  for (int i = 0; i < M; i++)
  {
    for (int j = 0; j < N; j++)
    {
      matrix[i][j] = randint(1, 100);
    }
  }

  for (int i = 0; i < M; i++)
  {
    for (int j = 0; j < N; j++)
    {
      printf("%d ", matrix[i][j]);
    }
    putc('\n', stdout);
  }

  putc('\n', stdout);

  for (int i = 0; i < M; i++)
  {
    free(matrix[i]);
  }
  free(matrix);
}

void part7()
{
  int* array = (int*)calloc(5, sizeof(int));
  for (int i = 0; i < 5; i++)
  {
    array[i] = randint(1, 100);
  }

  array = (int*)realloc(array, sizeof(int) * 10);

  for (int i = 5; i < 10; i++)
  {
    array[i] = randint(1, 100);
  }

  printf("array = ");
  for (int i = 0; i < 10; i++)
  {
    printf("%d ", array[i]);
  }
  putc('\n', stdout);

  free(array);
}

void part8()
{
  int** array = (int**)calloc(5, sizeof(int*));
  for (int i = 0; i < 5; i++)
  {
    array[i] = (int*)calloc(5, sizeof(int));
  }

  for (int i = 0; i < 5; i++)
  {
    for (int j = 0; j < 5; j++)
    {
      array[i][j] = randint(1, 100);
    }
  }

  for (int i = 0; i < 5; i++)
  {
    printf("array %d = ", i + 1);
    for (int j = 0; j < 5; j++)
    {
      printf("%d ", array[i][j]);
    }
    putc('\n', stdout);
  }

  for (int i = 0; i < 5; i++)
  {
    free(array[i]);
  }
  free(array);
}

void part9()
{
  linked_list* head = init_list(5);
  add_item(head, 4);
  add_item(head, 3);
  add_item(head, 2);
  add_item(head, 1);

  print_list(head);
  putc('\n', stdout);
  clean_list(head);
}

linked_list* init_list(int num)
{
  linked_list* head = (linked_list*)calloc(1, sizeof(linked_list));
  head->num = num;
  head->left = NULL;
  head->right = NULL;

  return head;
}

void add_item(linked_list *head, int num)
{
  linked_list* cur = head;
  while (cur->right != NULL)
  {
    cur = cur->right;
  }

  cur->right = (linked_list*)calloc(1, sizeof(linked_list));
  cur->right->num = num;
  cur->right->right = NULL;
  cur->right->left = cur;
}

void print_list(linked_list *head)
{
  linked_list* cur = head;
  do
  {
    printf("%d ", cur->num);
    cur = cur->right;
  } while (cur->right != NULL);
  printf("%d ", cur->num);
}

void clean_list(linked_list *head)
{
  while(head->right != NULL)
  {
    head = head->right;
    free(head->left);
  }
  free(head);
}
