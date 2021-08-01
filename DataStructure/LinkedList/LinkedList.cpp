#include <iostream>
using namespace std;

class Node
{
  int data;
  Node *next;

public:
  Node(int data)
  {
    this->data = data;
    this->next = nullptr;
  }

  int getData()
  {
    return data;
  }

  Node *getNext()
  {
    return next;
  }

  void setNext(Node *next)
  {
    this->next = next;
  }
};

class SinglyLinkedList b
{
private:
  Node *head = NULL;
  int size = 0;

public:
  Node *getHead() { return this->head; }
  void addFront(int data)
  {
    if (this->head == NULL)
    {
      this->head = new Node(data);
    }
    else
    {
      Node *newNode = new Node(data);
      Node *curr = this->head;
      while (curr->getNext() != NULL)
      {
        curr = curr->getNext();
      }
      curr->setNext(newNode);
    }
    this->size++;
  };

  int get(int pos)
  {
    if (pos < 1 || pos > size)
    {
      return -1;
    }

    Node *curr = this->head;
    for (int i = 1; i < pos; i++)
    {
      curr = curr->getNext();
    }
    return curr->getData();
  }

  int getSize()
  {
    return this->size;
  }
};

int main(int argc, char **argv)
{
  SinglyLinkedList linkedList;

  linkedList.add(0);
  linkedList.add(1);

  cout << linkedList.get(1);
}