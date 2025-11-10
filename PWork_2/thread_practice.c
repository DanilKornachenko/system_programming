#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct {
  float* nums;
  size_t count;
} ThreadData;

void* even(void* arg) {
  ThreadData* data = (ThreadData*)arg;
  for (size_t i = 0; i < data->count; i++) {
    // Проверяем целую часть на четность
    int int_part = (int)data->nums[i];
    if (int_part % 2 == 0) {
      printf("Number %f is even\n", data->nums[i]);
    } else {
      printf("Number %f is odd\n", data->nums[i]);
    }
    usleep(50);
  }
  return NULL;
}

void* divide(void* arg) {
  ThreadData* data = (ThreadData*)arg;
  for (size_t i = 1; i < data->count; i++) {
    int int_part = (int)data->nums[i];
    if (int_part != 0) {
      float div = data->nums[i - 1] + data->nums[i];
      printf("Разность %f и %f равна %f\n", data->nums[i - 1], data->nums[i],
             div);
    } else {
      printf("Нельзя поделить %f на %f (Деление на ноль)\n", data->nums[i - 1],
             data->nums[i]);
    }
    usleep(10);
  }

  return NULL;
}

void* sum(void* arg) {
  ThreadData* data = (ThreadData*)arg;
  for (size_t i = 1; i < data->count; i++) {
    float sum = data->nums[i - 1] + data->nums[i];
    printf("Сумма %f и %f равна %f\n", data->nums[i - 1], data->nums[i], sum);
    usleep(100);
  }

  return NULL;
}

int main() {
  size_t count = 0;
  size_t capacity = 1;
  float* user_nums = (float*)malloc(capacity * sizeof(float));

  if (user_nums != NULL) {
    printf("Enter your numbers :D\n");
    float user_num;
    while (scanf("%f", &user_num) == 1) {
      if (count >= capacity) {
        capacity *= 2;
        user_nums = realloc(user_nums, capacity * sizeof(float));
      }
      user_nums[count++] = user_num;

      // Проверка на конец строки
      if (getchar() == '\n') break;
    }

    printf("Good job! Lets solve it!\n");

    // Вывод введенных чисел
    for (size_t i = 0; i < count; i++) {
      printf("%f ", user_nums[i]);
    }
    putchar('\n');

    // Создание структуры для передачи в потоки
    ThreadData data = {user_nums, count};

    pthread_t threads[3];
    // Создание потоков
    pthread_create(&threads[0], NULL, even, &data);
    pthread_create(&threads[1], NULL, divide, &data);
    pthread_create(&threads[2], NULL, sum, &data);

    // Ожидание завершения потоков
    for (int i = 0; i < 3; i++) {
      pthread_join(threads[i], NULL);
    }

    free(user_nums);  // Освобождение памяти
  } else {
    perror("Memory not allocated\n");
  }

  return 0;
}
