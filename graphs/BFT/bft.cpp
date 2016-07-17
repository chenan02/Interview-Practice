// Breadth first traversal for a graph
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

struct Node {
  vector<Node *> adjacent;
  int data = 0;
  Node(int data) : data(data) {}
};

void BFT(Node *start, int n) {
  vector<bool> visited(n, false);
  queue<Node *> unvisited;
  unvisited.push(start);
  while(!unvisited.empty()) {
    Node *next = unvisited.front();
    unvisited.pop();
    if(!visited[next->data]) {
      cout << next->data << " ";
      visited[next->data] = true;
      for(int i = 0; i < next->adjacent.size(); i++) {
        unvisited.push(next->adjacent[i]);
      }
    }
  }
  cout << endl;
}

int main() {
  Node n0(0);
  Node n1(1);
  Node n2(2);
  Node n3(3);
  n0.adjacent = {&n1, &n2};
  n1.adjacent = {&n2};
  n2.adjacent = {&n0, &n3};
  n3.adjacent = {&n3};
  BFT(&n2, 4);
}
