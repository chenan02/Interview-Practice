// Given a sorted (increasing order) array with unique integer elements,
// write an algorithm to create a binary search tree with minimal height
//
// Q's:
// Assumptions:
// Plan: Recurse through through array at n/2, n/4, 3n/4, etc while making tree
//
#include <iostream>

using namespace std;

struct Node {
  int data = 0;
  Node * left = NULL;
  Node * right = NULL;
  Node(int data) : data(data) {}
};

Node* createTree(int a[], int l, int r) {
  if(l > r) {
    return NULL;
  }
  Node *newNode = new Node(a[(l+r)/2]);
  newNode->left = createTree(a, l, (r+l)/2-1);
  newNode->right = createTree(a, (r+l)/2+1, r);
  return newNode;
}

void printTree(Node *current) {
  if(!current) {
    return;
  }
  printTree(current->left);
  cout << current->data << " ";
  printTree(current->right);
}


int main() {
  int a[] = {0, 1, 2, 3, 4};
  Node *root = createTree(a, 0, 4);
  printTree(root);
}
