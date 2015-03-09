#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_
#include "Node.h"

class LinkedList {
 private:
    Node *head;
    Node *tail;
 public:
    LinkedList();
    ~LinkedList();

    void insert_front(int value);
    void insert_back(int value);
    int front();
    int back();
    int pop_front();
    int pop_back();
};

#endif  // LINKEDLIST_H_
