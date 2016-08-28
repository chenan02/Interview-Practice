// Mergesort
// recurse down halves of arrays until size is one
// merge them back together in order

#include <iostream>
using namespace std;

void merge(int a[], int size, int l, int m, int r) {
  int helper[size];
  for(int i = 0; i < size; ++i) {
    helper[i] = a[i];
  }
  int helperl = l;
  int helperr = m+1;
  int count = l;
  while(helperl <= m && helperr <= r) {
    if(helper[helperl] > helper[helperr]) {
      a[count] = helper[helperr];
      helperr++;
    }
    else {
      a[count] = helper[helperl];
      helperl++;
    }
    count++;
  }
  // copy rest of left if there is any
  for(int i = helperl; i <= m; ++i) {
    a[count] = helper[i];
    count++;
  }
}

void partition(int a[], int size, int l, int r) {
  if(l >= r) {
    return;
  }
  int m = (l+r)/2;
  partition(a, size, l, m);
  partition(a, size, m+1, r);
  merge(a, size, l, m, r);
}

int main() {
  int a[5] = {3, 1, 5, 4, 2};
  partition(a, 5, 0, 4);
  for(int i = 0; i < 5; ++i) {
    cout << a[i] << " ";
  }
  cout << endl;
}
