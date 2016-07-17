#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <ctype.h>

using namespace std;

string reverse(string toReverse);

int main() {
  string toReverse = "#$fsda@sf^&df*";
  string reversed = reverse(toReverse);
  cout << reversed << endl;
}
// O(n) time and constant memory
string reverse(string toReverse) {
  int l = 0, r = toReverse.size()-1;
  while(l < r) {
    while(!isalnum(toReverse[l])) {
      l++;
    }
    while(!isalnum(toReverse[r])) {
      r--;
    }
    swap(toReverse[l], toReverse[r]);
    l++;
    r--;
  }
  return toReverse;
}
    
