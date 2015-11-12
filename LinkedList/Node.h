#ifndef NODE_H_
#define NODE_H_

template<class T>
struct Node {
  T value;
  struct Node* prev;
  struct Node* next;
};

#endif  // NODE_H_
