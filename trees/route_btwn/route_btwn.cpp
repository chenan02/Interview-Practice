// Given a directed graph, design an algorithm to find
// out whether there is a route between two nodes

// Q's: are there self loops?
//      are all nodes connected?
//      what data type does the node contain?

// Assumptiions:

// Plan: use BFS bc related Nodes are more likely to be close to one another?

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node {
  int data;
  vector<Node *> next;
  Node(int data) : data(data) {}
};

void find_route(Node *first, Node *second, int n) {
  if(first == second) {
    cout << "yes" << endl;
    return;
  }
  vector<bool> visited(n, false);
  Node * current;
  queue<Node *> unvisited;
  unvisited.push(first);
  while(!unvisited.empty()) {
    current = unvisited.front();
    unvisited.pop();
    visited[current->data] = true;
    for(int i = 0; i < current->next.size(); ++i) {
      // if found pointer in list of next, return early
      if(current->next[i] == second) {
        cout << "yes" << endl;
        return;
      }
      if(visited[current->next[i]->data] != true) {
        unvisited.push(current->next[i]);
      }
    }
  }
  cout << "no" << endl;
}

int main() {
  Node n0(0);
  Node n1(1);
  Node n2(2);
  Node n3(3);
  Node n4(4);
  n0.next = {&n0, &n3};
  n1.next = {&n2};
  n2.next = {&n0, &n4};
  n3.next = {&n3, &n4};
  n4.next = {&n1};
  find_route(&n1, &n3, 5);
}
