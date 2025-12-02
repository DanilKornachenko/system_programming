#include <stdlib.h>

int main(void)
{
  int* data = malloc(5 * sizeof(int));
  data[0] = 42;

  return 0;
}
