// Imagine  robot sitting on the upper left corner of a grid with
// r rows and c columns. The robot can only move in two directions,
// right and down, but certain cells are "off limits" such that the
// robot cannot step on them. Design an algorithm to find a path for
// the robot from the top left to the bottom right
//
// Qs:
//
// Assumptions:
//
// Strategy: 1) Solve without off-limit squares using memoization to
// store paths for each square's (column-1, row) and (column, row-1).
// 2) Find way to include off-limit spots

#include <iostream>
#include <vector>
#include <string>

using namespace std;

void printGrid(vector<vector<bool> > grid) {
  for(int r = 0; r < grid[0].size(); ++r) {
    for(int c = 0; c < grid.size(); ++c) {
      cout << grid[c][r] << " ";
    }
    cout << endl;
   }
}

// in interview act as if this exists
vector<vector<bool> > buildGrid(int r, int c, vector<pair<int, int> >offLimits) {
  vector<vector <bool> > columns;
  for(int i = 0; i < c; ++i) {
    vector<bool> rows(r, true);
    columns.push_back(rows);
  }
  for(int i = 0; i < offLimits.size(); ++i) {
    pair<int, int> square = offLimits[i];
    columns[square.first-1][square.second-1] = false;
  }
  return columns;
}

vector<string> findPaths(vector<vector<bool> >grid, vector<vector<vector<string> > >mem, int r, int c) {
  if(r < 0 || c < 0) {
    vector<string> empty;
    return empty;
  }
  if(r == 0) {
    vector<string> firstColumn;
    firstColumn.push_back(string(c, 'r'));
    return firstColumn;
  }
  if(c == 0) {
    vector<string> firstRow;
    firstRow.push_back(string(r, 'd'));
    return firstRow;
  }
  // creates new string every time? O(n)?
  // if(grid[c-1][r-2]) {
    vector<string> above = findPaths(grid, mem, r-1, c);
    for(int i = 0; i < above.size(); ++i) {
      mem[c-1][r-1].push_back(above[i] + "d");
    }
  // }
  // if(grid[c-2][r-1]) {
    vector<string> left = findPaths(grid, mem, r, c-1);
    for(int i = 0; i < left.size(); ++i) {
      mem[c-1][r-1].push_back(left[i] + "r");
    }
  // }
  return mem[c-1][r-1];
}

vector<string> findPaths_helper(int r, int c, vector<pair<int, int> >offLimits) {
  vector<vector<bool> >grid = buildGrid(r, c, offLimits);
  vector<vector<vector<string> > >columns;
  for(int i = 0; i < c; ++i) {
    vector<vector<string> > row;
    for(int j = 0; j < r; ++j) {
      vector<string> strings;
      row.push_back(strings);
    }
    columns.push_back(row);
  }
  return findPaths(grid, columns, r, c);
}

int main() {
  vector<pair<int, int> >offLimits = {pair<int, int>(1, 2), pair<int, int>(3, 4)};
  vector<string> paths = findPaths_helper(5, 5, offLimits);
  for(int i = 0; i < paths.size(); ++i) {
    cout << paths[i] << endl;
  }
}
