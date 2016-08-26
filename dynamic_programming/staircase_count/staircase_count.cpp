// A child is running aup a staircase with n steps and can hop either
// 1 step, 2 steps, or 3 steps at a time. Implement a method to count
// how many possible ways the child can run up the stairs.
//
// Qs: Can the child go down steps?
//
// Assumptions: The child cannot go down steps
//
// Strategy: Use top-down memoization to store number of ways at
// step n-1, n-2, n-3, etc

#include <iostream>
#include <vector>

using namespace std;

void printMem(vector<int> mem) {
  for(int i = 0; i < mem.size(); ++i) {
    cout << mem[i] << " ";
  }
  cout << endl;
}

int countSteps(int n, vector<int> mem) {
  if (n < 0) {
    return 0;
  }
  if (n == 0) {
    return 1;
  }
  if(mem[n] != -1) {
    return mem[n];
  }
  mem[n] = countSteps(n-1, mem) + countSteps(n-2, mem) + countSteps(n-3, mem);
  return mem[n];
 }

int countSteps_helper(int n) {
  vector<int> mem(n+1, -1);
  return countSteps(n, mem);
}

int main() {
  int n = 3;
  cout << "There are " << countSteps_helper(n) << " ways to go up " << n << " steps" << endl;
}

// Analysis: This algorithm would use O(n) time because it makes n calls to countSteps,
// all of which return immediately. It uses O(n) space because it stores it creates one
// vector of size n; the stack calls and their respective memps are immediately destroyed.
