int abs_example(int x)
{
  if (x >= 0)
    return x;
  else
    return -x;
}

int main(void)
{
  int x = 42;

  x = abs_example(x);

  x = abs_example(-x);

  return 0;
}


