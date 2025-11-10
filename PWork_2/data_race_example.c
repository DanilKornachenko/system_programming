#include <pthread.h>
#include <stdio.h>

int counter = 0;  // Объявлять так переменные - это кринж

void* encrement(void* unused) {
  size_t i = 0;
  while (i != 1000000) {
    counter++;
    i++;
  }
}

int main() {
  pthread_t thread[2];
  pthread_create(&thread[0], NULL, encrement, NULL);
  pthread_create(&thread[1], NULL, encrement, NULL);

  for (size_t i = 0; i < 2; i++) {
    pthread_join(thread[i], NULL);
  }

  printf("%d\n", counter);

  return 0;
}
