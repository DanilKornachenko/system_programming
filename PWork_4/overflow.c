#include <stdlib.h>

int main(void)
{
  int* arr = malloc(5 * sizeof(int));
  for (int i = 0; i <= 5; i++)
  {
    arr[i] = i * 10;
  }

  return 0;
}
