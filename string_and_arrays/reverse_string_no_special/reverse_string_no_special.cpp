#include <iostream>
#include <vector>
#include <string>
#include <ctype.h>

using namespace std;

vector<char> reverseString(string toReverse);

int main() {
  string toReverse = "y#fds&^dsf*&^";
  vector<char> reversed = reverseString(toReverse);
  for(int i = 0; i < reversed.size(); ++i) {
    cout << reversed[i];
  }
  cout << endl;
}

vector<char> reverseString(string toReverse) {
  vector<char> v(toReverse.length(), '\0');
  for(int i = 0; i < toReverse.length(); ++i) {
    if(!isalnum(toReverse[i])) {
      v[i] = toReverse[i];
    }
  }
  int stringIndex = toReverse.length()-1, vIndex = 0;
  while(vIndex < toReverse.length()) {  
    if(v[vIndex] == '\0' && isalnum(toReverse[stringIndex])) {
      v[vIndex] = toReverse[stringIndex];
    }
    else if(v[vIndex] != '\0' && !isalnum(toReverse[stringIndex])) {
    }
    else if(!isalnum(toReverse[stringIndex])) {
      while(!isalnum(toReverse[stringIndex])) {
        stringIndex--;
      }
      v[vIndex] = toReverse[stringIndex];
    }
    else {
      while(v[vIndex] != '\0') {
        vIndex++;
      }
      v[vIndex] = toReverse[stringIndex];
    }
    vIndex++;
    stringIndex--;
  }
  return v;
} 

