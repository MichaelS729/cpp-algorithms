#include <iostream>
#include <cstddef>
#include <cmath>
#include "MinHeap.h"

using std::cout;

MinHeap::MinHeap(int initial_capacity) {
  capacity = initial_capacity;
  heap = new int[initial_capacity];
  curr_index = -1;
}

MinHeap::MinHeap(int* arr, int length) {
  capacity = length;
  heap = new int[length];
  curr_index = length - 1;
  for (int i = 0; i < length; i++) {
    heap[i] = arr[i];
  }
  for (int i = curr_index; i >= 0; i--) {
    bubble_down(heap[i], i);
  }
}

MinHeap::~MinHeap() {
  delete[] heap;
}

int MinHeap::size() {
  return curr_index + 1;
}

void MinHeap::resize() {
  int new_capacity = capacity * 2;
  int* new_heap = new int[new_capacity];
  for (int i = 0; i < capacity; i++) {
    new_heap[i] = heap[i];
  }
  delete[] heap;

  capacity = new_capacity;
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
  bubble_up(val, curr_index);
}

void MinHeap::bubble_up(int val, int i) {
  int parent = (i - 1) / 2;
  while (i > 0 && val < heap[parent]) {
    heap[i] = heap[parent];
    i = parent;
    parent = (parent - 1) / 2;
  }
  heap[i] = val;
}

int MinHeap::remove_min() {
  int mn = min();
  if (curr_index >= 0) {
    bubble_down(heap[curr_index--], 0);
  }
  return mn;
}

void MinHeap::bubble_down(int val, int i) {
  int left = 2 * i + 1;
  int right = 2 * i + 2;

  int next;
  if (right > curr_index || heap[left] < heap[right]) {
    next = left;
  } else {
    next = right;
  }

  while (next <= curr_index && val > heap[next]) {
    heap[i] = heap[next];

    i = next;
    left = 2 * i + 1;
    right = 2 * i + 2;
    if (right > curr_index || heap[left] < heap[right]) {
      next = left;
    } else {
      next = right;
    }
  }
  heap[i] = val;
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
  cout << "\n";
  delete mh;

  int length = 7;
  int* arr = new int[length];
  arr[0] = 3;
  arr[1] = 7;
  arr[2] = -1;
  arr[3] = 9;
  arr[4] = 8;
  arr[5] = 1;
  arr[6] = 8;
  mh = new MinHeap(arr, length);
  mh->print_heap();
  delete mh;
  delete[] arr;
}
