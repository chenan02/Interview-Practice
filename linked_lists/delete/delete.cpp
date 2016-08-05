#include <iostream>

using namespace std;

struct Node {
  int data = 0;
  Node *next = NULL;
  Node(int data) : data(data) {}
};

void deleteNode(Node **head, Node *deleting) {
  if(*head == deleting) {
    *head = deleting->next;
    delete deleting;
  }
  else {
    Node *current = *head;
    while(current->next != deleting) {
      current = current->next;
    }
    current->next = deleting->next;
    delete deleting;
  }
}

void print(Node *head) {
  while(head) {
    cout << head->data << " ";
    head = head->next;
  }
  cout << endl;
}

int main() {
  Node *n0 = new Node(0);
  Node *n1 = new Node(1);
  Node *n2 = new Node(2);
  n0->next = n1;
  n1->next = n2;
  deleteNode(&n0, n0);
  print(n0);
  deleteNode(&n1, n2);
  print(n1);
  deleteNode(&n1, n1);
}

