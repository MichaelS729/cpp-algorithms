#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_
#include "Node.h"

class LinkedList {
 private:
    int size;
    Node *head;
    Node *tail;
 public:
    LinkedList();
    ~LinkedList();

    int get_size();
    int index_of(int value);
    void insert_front(int value);
    void insert_back(int value);
    int front();
    int back();
    int pop_front();
    int pop_back();

    void print_elements_front_to_back();
};

#endif  // LINKEDLIST_H_
