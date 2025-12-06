#include "my_lib.h"
#include "config.h"
#include <stdio.h>

int main()
{
  print_hello_message();
  printf("Эта программа называется %s, версия %s\n", PACKAGE_NAME, PACKAGE_VERSION);
  return 0;
}
