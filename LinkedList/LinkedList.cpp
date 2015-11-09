#include <iostream>
#include "Node.h"
#include "LinkedList.h"

using std::cout;

LinkedList::LinkedList() {
  size = 0;
  head = new Node();
  tail = new Node();
  head->next = tail;
  tail->prev = head;
}

LinkedList::~LinkedList() {
  size = 0;
  Node *prev = NULL;
  Node *curr = head;
  while (curr != NULL) {
    prev = curr;
    curr = curr->next;
    delete prev;
  }
  delete curr;
}

int LinkedList::get_size() {
  return size;
}

int LinkedList::index_of(int val) {
  int index = 0;
  Node *curr = head->next;
  while (curr != tail) {
    if (curr->value == val) {
      return index;
    }
    curr = curr->next;
    index++;
  }
  return index;
}

void LinkedList::insert_front(int value) {
  Node *first_node = head->next;
  Node *new_node = new Node();
  new_node->value = value;
  new_node->prev = head;
  new_node->next = first_node;
  first_node->prev = new_node;
  head->next = new_node;
  size++;
}

void LinkedList::insert_back(int value) {
  Node *last_node = tail->prev;
  Node *new_node = new Node();
  new_node->value = value;
  new_node->next = tail;
  new_node->prev = last_node;
  last_node->next = new_node;
  tail->prev = new_node;
  size++;
}

int LinkedList::front() {
  Node *front_node = head->next;
  if (front_node == tail) {
    cout << "Error: List is empty\n";
    return -1;
  }
  return front_node->value;
}

int LinkedList::back() {
  Node *back_node = tail->prev;
  if (back_node == head) {
    cout << "Error: List is empty\n";
    return -1;
  }
  return back_node->value;
}

int LinkedList::pop_front() {
  Node *front_node = head->next;
  if (front_node == tail) {
    cout << "Error: List is empty\n";
    return -1;
  }
  head->next = front_node->next;
  front_node->next->prev = head;
  size--;
  int val = front_node->value;
  delete front_node;
  return val;
}

int LinkedList::pop_back() {
  Node *back_node = tail->prev;
  if (back_node == head) {
    cout << "Error: List is empty\n";
    return -1;
  }
  tail->prev = back_node->prev;
  back_node->prev->next = tail;
  size--;
  int val = back_node->value;
  delete back_node;
  return val;
}

void LinkedList::print_elements_front_to_back() {
  Node *curr = head->next;
  while (curr != tail) {
    cout << curr->value << ' ';
    curr = curr->next;
  }
  cout << '\n';
}

int main() {
  LinkedList *l = new LinkedList();
  l->insert_front(1);
  l->insert_front(2);
  l->insert_back(3);
  l->insert_back(4);
  l->insert_back(3);
  cout << "Should be 2 1 3 4 3: ";
  l->print_elements_front_to_back();
  cout << "Size should be 5: " << l->get_size() << '\n';

  cout << "TESTING FRONT, BACK, INDEX_OF:\n";
  cout << "Should be 2: " << l->front() << '\n';
  cout << "Should be 3: " << l->back() << '\n';
  cout << "Should be 2: " << l->index_of(3) << '\n';
  cout << "should be 5: " << l->get_size() << '\n';

  cout << "TESTING SUCCESSFUL POP_FRONT AND POP_BACK:\n";
  cout << "Should be 2: " << l->pop_front() << '\n';
  cout << "Should be 3: " << l->pop_back() << '\n';
  cout << "Should be 4: " << l->pop_back() << '\n';
  cout << "Size should be 2: " << l->get_size() << '\n';
  cout << "Should be 1 3: ";
  l->print_elements_front_to_back();
  cout << "Should be 1: " << l->pop_front() << '\n';
  cout << "Should be 3: " << l->pop_front() << '\n';
  cout << "Size should be 0: " << l->get_size() << '\n';

  cout << "TESTING FAILING POP_FRONT AND POP_BACK:\n";
  cout << "Should print 'Error: List is empty': ";
  l->pop_front();
  cout << '\n';
  cout << "Should print 'Error: List is empty': ";
  l->pop_back();
  cout << '\n';

  cout << "TESTING DESTRUCTOR:\n";
  delete l;
  LinkedList* l2 = new LinkedList();
  l2->insert_front(1);
  l2->insert_front(2);
  l2->insert_back(3);
  l2->insert_back(4);
  l2->insert_back(3);
  delete l2;
  cout << "PASSED ALL TESTS!\n";

  return 0;
}
