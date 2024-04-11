#include <stdio.h>
int main() {
  int n, i, key, l, h, m;
  printf("Enter the number of elements: ");
  scanf("%d", &n);
  int arr[n];
  printf("Enter %d elements in ascending order:\n", n);
  for (i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }
  printf("Enter the element to search: ");
  scanf("%d", &key);
  l = 0;
  h = n - 1;
  m = (l + h) / 2;
  while (l <= h) {
    if (arr[m] == key) {
      printf("Element found at index %d.\n", m);
      break;
    } else if (arr[m] < key) {
      l = m + 1;
    } else {
      h = m - 1;
    }
    m = (l + h) / 2;
  }
  if (l > h) {
    printf("Element not found.\n");
  }
  return 0;
}
