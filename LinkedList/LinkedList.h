#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_
#include "Node.h"

template<class T>
class LinkedList {
 private:
    int size;
    Node<T> *head;
    Node<T> *tail;
 public:
    LinkedList();
    ~LinkedList();

    int get_size();
    int index_of(T value);
    void insert_front(T value);
    void insert_back(T value);
    T front();
    T back();
    T pop_front();
    T pop_back();

    void print_elements_front_to_back();
};

#endif  // LINKEDLIST_H_
