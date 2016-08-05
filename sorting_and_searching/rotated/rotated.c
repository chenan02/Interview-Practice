#include <stdio.h>
#include <stdlib.h>

int findRotation(int a[], int size) {
  int l = 0, r = size-1;
  while(l < r) {
    if(a[l] < a[r]) {
      r = (r+l)/2;
    }
    else {
      l = (r+l)/2;
    }
  }
  return l;
}

int binarySearch(int a[], int size, int n) {
  int l = 0, r = size-1;
  while(l < r) {
    if(a[(l+r)/2] > n) {
      r = (r+l)/2;
    }
    else {
      l = (r+l)/2;
    }
  }
  return l;
}

int* buildOrdered(int a[], int size, int rotation) {
  int *ordered = (int *) malloc(size);
  for(int i = 0; i < size-rotation; ++i) {
    ordered[i] = a[i+rotation];
  }
  for(int i = size-rotation; i < size; ++i) {
    ordered[i] = a[i-(size-rotation)];
  }
  return ordered;
}

int main() {
  printf("hey");
  int a[] = {3, 4, 5, 1, 2};
  printf("hello");
  int size_a = (int) (sizeof(a) / sizeof(a[0]));
  printf("size_a: %d", size_a);
  int rotation = findRotation(a, size_a);
  printf("rotation: %d", rotation);
  int *ordered = buildOrdered(a, size_a, rotation);
  int i = binarySearch(ordered, size_a, 2);
  i = (i + rotation) % size_a;
  printf("The index is %d", i);
}

