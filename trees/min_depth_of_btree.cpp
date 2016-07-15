#include <iostream>
#include <algorithm>

using namespace std;

struct Node {
  Node * left = NULL;
  Node * right = NULL;
  int data = 0;
  Node(int data) : data(data) {}
};

int minDepth(Node * head) {
  // corner case - NULL head
  if(!head) {
    return 0;
  }
  if(!head->left && !head->right) {
    return 1;
  }
  if(!head->left) {
    return minDepth(head->right) + 1; 
  }
  if(!head->right) { 
    return minDepth(head->left) + 1;
  }
  else {
    return min(minDepth(head->right), minDepth(head->left)) + 1;
  }
}

int main() {
  Node node1(1);
  Node node2(2);
  Node node3(3);
  Node node4(4);
  Node node5(5);
  node1.left = &node2;
  node1.right = &node3;
  node2.left = &node4;
  node2.right = &node5;
  cout << minDepth(&node1) << endl;
}
