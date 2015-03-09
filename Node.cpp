#include "Node.h"

Node::Node() {
  prev = NULL;
  next = NULL;
}

Node::Node(int value) {
  prev = NULL:
  next = NULL;
  this.value = value;
}

Node::~Node() {
}

void Node::set_value(int value) {
  this.value = value;
}

void Node::set_prev(Node* node) {
  prev = node;
}

void Node::set_next(Node* node) {
  next = node;
}

int Node::value() {
  return value;
}

Node* Node::prev() {
  return prev;
}

Node* Node::next() {
  return next;
}
