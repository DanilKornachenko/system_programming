#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
  int n;
  scanf("%d", &n);

  int arr[1000];

  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }

  int x;
  scanf("%d", &x);

  int closest = arr[0];
  int min_diff = abs(arr[0] - x);

  for (int i = 1; i < n; i++) {
    int diff = abs(arr[i] - x);
    if (diff < min_diff) {
      min_diff = diff;
      closest = arr[i];
    }
  }

  printf("%d\n", closest);

  return 0;
}
