#include <iostream>

using namespace std;

class List {
  public:
    struct Node {
      int data = 0;
      Node * next = NULL;
      Node(int data) : data(data) {}
    };
    void insert(int data);
    void print();
  private:
    Node *head = NULL;
};

void List::insert(int data) {
  Node *insertingPtr = new Node(data);
  if(!head || data < head->data) {
    insertingPtr->next = head;
    head = insertingPtr;
  }
  else {
    Node *current = head;
    while(current->next && data > current->next->data) {
      current = current->next;
    }
    insertingPtr->next = current->next;
    current->next = insertingPtr;
  }
}

void List::print() {
  Node *current = head;
  while(current) {
    cout << current->data << " ";
    current = current->next;
  }
  cout << endl;
}

int main() {
  List list;
  list.insert(1);
  list.insert(0);
  list.insert(-1);
  list.insert(5);
  list.insert(4);
  list.print();
}
