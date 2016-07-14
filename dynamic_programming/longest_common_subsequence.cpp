#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<vector<int> > makeMatrix(string string1, string string2) {
  vector<vector<int> > counts;
  // initialize counts matrix of 0s
  for(int i = 0; i < string1.size(); ++i) {
    vector<int> column; 
    for(int j = 0; j < string2.size(); ++j) {
      column.push_back(0);
    }
    counts[i] = column;
  }
  // initialize first row and column
  for(int i = 0; i < string1.size(); ++i) {
    if(string1[i] == string2[0]) {
      counts[i][0] = 1;
    }
  }
  for(int i = 0; i < string2.size(); ++i) {
    if(string1[0] == string2[i]) {
      counts[0][i] = 1;
    }
  }
  // begin algorithm
  for(int i = 1; i < string1.size(); ++i) {
    for(int j = 1; j < string2.size(); ++j) {
      if(string2[j] == string1[i]) {
        counts[i][j] = counts[i-1][j-1]+1;
      }
      else {
        counts[i][j] = max(counts[i][j-1], counts[i-1][j]);
      }
    }
  }
  return counts;
}

void printMatrix(vector<vector<int> > matrix) {
  for(int i = 0; i < matrix[0].size(); ++i) {
    for(int j = 0; j < matrix.size(); ++j) {
      cout << matrix[j][i] << " ";
    }
    cout << endl;
  }
}

int main(int argc, char *argv[]) {
  vector<vector<int> > counts = makeMatrix(argv[1], argv[2]);
  printMatrix(counts);
}
