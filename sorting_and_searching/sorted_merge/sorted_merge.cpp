// You are given two sorted arrays, A and B, where A has a large
// enough buffer at the end to hold B. Write a method to merge
// B into A in sorted order.
//
// Qs: type?
//
// Assumptions: Ints
//
// Strategy: Start from the end of both, so swapping is easier.
// Take adv of sortedness by starting from last swap

#include <iostream>

using namespace std;

void sortedMerge(int a[], int b[], int sizea, int sizeb) {
  int counta = sizea-sizeb-1;
  int countb = sizeb-1;
  int insert = sizea-1;
  while(countb >= 0) {
    if(b[countb] > a[counta]) {
      a[insert] = b[countb];
      countb--;
    }
    else {
      a[insert] = a[counta];
      counta--;
    }
    insert--;
  }
}

int main() {
  int a[10] = {1, 3, 5, 7, 9};
  int b[5] = {2, 4, 6, 8, 10};
  sortedMerge(a, b, 10, 5);
  for(int i = 0; i < 10; ++i) {
    cout << a[i] << " ";
  }
}

// this algorithm runs in O(n) time, where n is the size of b.
// This is because we must go over every element in b for
// comparison and insertion, though we dont need to do so for a.
// It takes O(1) space because we are not allocating any new
// space in addition to the buffer.
