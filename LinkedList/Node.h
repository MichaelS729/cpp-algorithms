#ifndef NODE_H_
#define NODE_H_

struct Node {
  int value;
  struct Node* prev;
  struct Node* next;
};

#endif  // NODE_H_
