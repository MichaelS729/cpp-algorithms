#ifndef NODE_H_
#define NODE_H_

class Node {
 private:
    Node *prev;
    Node *next;
    int value;

 public:
    Node();
    explicit Node(int value);
    ~Node();

    void set_value(int value);
    void set_prev(Node *node);
    void set_next(Node *node);

    int get_value();
    Node *get_prev();
    Node *get_next();
};

#endif  // NODE_H_
