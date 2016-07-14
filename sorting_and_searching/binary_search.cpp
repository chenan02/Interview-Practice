#include <array>
#include <iostream>

using namespace std;

int binarySearch(int arr[], int n, int x) {
  int index = n/2, lower = 0, upper = n;
  for(int i = n; i > 0; i /= 2) {
    if(x == arr[index]) {
      return x;
    }
    else if(x > arr[index]) {
      lower = index;
      index = (upper + index)/2;
    }
    else {
      upper = index;
      index = (lower + index)/2;
    }
  }
  return -1;
}

int main() {
  int arr1[5] = {1, 2, 3, 4, 5};
  cout << binarySearch(arr1, 5, 4) << endl;
  cout << binarySearch(arr1, 5, 10) << endl;
  cout << binarySearch(arr1, 5, -1) << endl;
}

