#ifndef MINHEAP_H_
#define MINHEAP_H_

class MinHeap {
  private:
    int num_entries;
    int capacity;
    int curr_index;
    int* heap;
    void bubble_up(int i);
    void bubble_down(int i);
    void resize();

  public:
    MinHeap(int initial_capacity=10);
    ~MinHeap();
    int size();

    int min();
    void insert(int val);
    int remove_min();
    void print_heap();
};

#endif  // MINHEAP_H_
