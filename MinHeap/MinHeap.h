#ifndef MINHEAP_H_
#define MINHEAP_H_

class MinHeap {
  private:
    int num_entries;
    int capacity;
    int curr_index;
    int* heap;
    void bubble_up(int val, int i);
    void bubble_down(int val, int i);
    void resize();

  public:
    MinHeap(int initial_capacity=5);
    MinHeap(int* arr, int length);
    ~MinHeap();
    int size();

    int min();
    void insert(int val);
    int remove_min();
    void print_heap();
};

#endif  // MINHEAP_H_
