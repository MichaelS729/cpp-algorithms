#include <iostream>
#include <cstddef>
#include <cmath>
#include "MinHeap.h"

using std::cout;

void swap(int* arr, int index1, int index2) {
  int tmp = arr[index1];
  arr[index1] = arr[index2];
  arr[index2] = tmp;
}

MinHeap::MinHeap(int initial_capacity) {
  capacity = initial_capacity;
  heap = new int[initial_capacity];
  curr_index = -1;
}

int MinHeap::size() {
  return curr_index + 1;
}

void MinHeap::resize() {
  int new_capacity = capacity * 2;
  int* new_heap = new int[capacity];
  for (int i = 0; i < capacity; i++) {
    new_heap[i] = heap[i];
  }
  delete[] heap;
  heap = new_heap;
}

int MinHeap::min() {
  if (curr_index == -1) {
    cout << "Error: MinHeap is empty.\n";
    return -1;
  }
  return heap[0];
}

void MinHeap::insert(int val) {
  curr_index++;

  if (curr_index == capacity) {
    resize();
  }

  heap[curr_index] = val;
  bubble_up(curr_index);
}

void MinHeap::bubble_up(int i) {
  int parent = (i - 1) / 2;
  while (i > 0 && heap[i] < heap[parent]) {
    swap(heap, i, parent);
    i = parent;
    parent = (parent - 1) / 2;
  }
}

int MinHeap::remove_min() {
  int mn = min();
  swap(heap, 0, curr_index);
  if (curr_index >= 0) {
    curr_index--;
    bubble_down(0);
  }
  return mn;
}

void MinHeap::bubble_down(int i) {
  int left = 2 * i + 1;
  int right = 2 * i + 2;

  int next;
  if (right > curr_index || heap[left] < heap[right]) {
    next = left;
  } else {
    next = right;
  }

  while (next <= curr_index && heap[i] > heap[next]) {
    swap(heap, i, next);

    i = next;
    left = 2 * i + 1;
    right = 2 * i + 2;
    if (right > curr_index || heap[left] < heap[right]) {
      next = left;
    } else {
      next = right;
    }
  }
}

void MinHeap::print_heap() {
  int power = 1;
  for (int i = 0; i < size(); i++) {
    if (pow(2, power) - 1 == i) {
      cout << "\n";
      power++;
    }
    cout << heap[i] << " ";
  }
  cout << "\n";
}

int main() {
  MinHeap* mh = new MinHeap();

  cout << "Inserted values: \n";
  cout << "\n";
  mh->insert(3);
  mh->insert(5);
  mh->insert(4);
  mh->insert(1);
  mh->insert(3);
  mh->insert(8);
  mh->print_heap();
  cout << "size() should be 6: " << mh->size() << "\n";
  cout << "\n";

  cout << "min() should be 1: " << mh->min() << "\n";
  cout << "remove_min() should be 1: " << mh->remove_min() << "\n";

  cout << "\n1 should be gone: \n";
  cout << "\n";
  mh->print_heap();
  cout << "size() should be 5: " << mh->size() << "\n";
  cout << "\n";

  cout << "remove_min() should be 3: " << mh->remove_min() << "\n";
  mh->print_heap();
  cout << "size() should be 4: " << mh->size() << "\n";
  cout << "\n";

  cout << "remove_min() should be 3: " << mh->remove_min() << "\n";
  mh->print_heap();
  cout << "size() should be 3: " << mh->size() << "\n";
  cout << "\n";

  cout << "remove_min() should be 4: " << mh->remove_min() << "\n";
  mh->print_heap();
  cout << "size() should be 2: " << mh->size() << "\n";
  cout << "\n";

  cout << "remove_min() should be 5: " << mh->remove_min() << "\n";
  mh->print_heap();
  cout << "size() should be 1: " << mh->size() << "\n";
  cout << "\n";

  cout << "remove_min() should be 8: " << mh->remove_min() << "\n";
  mh->print_heap();
  cout << "size() should be 0: " << mh->size() << "\n";
  cout << "\n";

  cout << "min() should be error with -1: ";
  cout << mh->min() << "\n";
  cout << "remove_min() should be error with -1: ";
  cout << mh->remove_min() << "\n";

  cout << "size() should be 0: " << mh->size() << "\n";
}
