#include <cstdef.h>
#include <iostream.h>
#include "Node.h"
#include "LinkedList.h"

using std::cout;

LinkedList::LinkedList() {
  head = new Node();
  tail = new Node();
  head->set_next(tail);
  tail->set_prev(head);
}

LinkedList::~LinkedList() {
  Node *prev = NULL;
  Node *curr = head;
  while (curr != NULL) {
    prev = curr;
    curr = curr->next();
    delete prev;
  }
  delete curr;
}

void LinkedList::insert_front(int value) {
  Node *new_node = new Node(value);
  Node *first_node = head->next();
  if (first_node != NULL) {
    first_node->set_prev(new_node);
  }
  head->set_next(new_node);
}

void LinkedList::insert_back(int value) {
  Node *new_node = new Node(value);
  Node *last_node = tail->prev();
  if (last_node != NULL) {
    last_node->set_prev(new_node);
  }
  tail->set_prev(new_node);
}

int LinkedList::front() {
  Node *front_node = head->next();
  if (front_node == tail) {
    cout << "Error: List is empty";
    return NULL;
  }
  return front_node->value();
}

int LinkedList:back() {
  Node *back_node = tail->prev();
  if (back_node == head) {
    cout << "Error: List is empty";
    return NULL;
  }
  return back_node->value();
}

int LinkedList::pop_front() {
  Node *front_node = head->next();
  if (front_node == tail) {
    cout << "Error: List is empty";
    return NULL;
  }
  head->set_next(front_node->next());
  front_node->next()->set_prev(head);
  return front_node->value();
}

int LinkedList:pop_back() {
  Node *back_node = tail->prev();
  if (back_node == head) {
    cout << "Error: List is empty";
    return NULL;
  }
  tail->set_prev(back_node->prev());
  return back_node->value();
}
