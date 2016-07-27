#include <iostream>
#include <vector>

using namespace std;

struct Node {
  int data;
  vector<Node *> adjacent;
  Node(int data) : data(data) {}
};

void dft(Node *start, vector<bool> &visited) {
  if(visited[start->data]) {
    return;
  }
  cout << start->data << " ";
  visited[start->data] = true;
  for(int i = 0; i < start->adjacent.size(); ++i) {
    dft(start->adjacent[i], visited);
  }
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
  vector<bool> visited(4, false);
  dft(&n2, visited);
  cout << endl;
}

