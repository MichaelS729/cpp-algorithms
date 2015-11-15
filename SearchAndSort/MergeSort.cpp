#include <iostream>
using std::cout;

void merge(int arr[], int length, int start, int mid, int end) {
  int helper[length];
  int i;
  for (i = start; i <= end; i++) {
    helper[i] = arr[i];
  }

  int curr = start;
  int left = start;
  int right = mid + 1;

  while (left <= mid && right <= end) {
    if (helper[left] <= helper[right]) {
      arr[curr++] = helper[left++];
    } else {
      arr[curr++] = helper[right++];
    }
  }

  while (left <= mid) {
    arr[curr++] = helper[left++];
  }
}

void mergesort(int arr[], int length, int start, int end) {
  if (start < end) {
    int mid = (start + end) / 2;
    mergesort(arr, length, start, mid);
    mergesort(arr, length, mid + 1, end);
    merge(arr, length, start, mid, end);
  }
}

void mergesort(int arr[], int length) {
  mergesort(arr, length, 0, length-1);
}

int main() {
  int length1 = 10;
  int arr1[] = {2, 3, 8, 8, 7, 7, 7, 8, 9, 10};
  int length2 = 9;
  int arr2[] = {2, 3, 5, 5, 6, 7, 9, 8, 9};
  int length3 = 1;
  int arr3[] = {2};
  int lengthEmpty = 0;
  int empty[0];

  int i;
  mergesort(arr1, length1);
  for (i = 0; i < length1; i++) {
    cout << arr1[i] << ' ';
  }
  cout << '\n';

  mergesort(arr2, length2);
  for (i = 0; i < length2; i++) {
    cout << arr2[i] << ' ';
  }
  cout << '\n';

  mergesort(arr3, length3);
  for (i = 0; i < length3; i++) {
    cout << arr3[i] << ' ';
  }
  cout << '\n';

  mergesort(empty, lengthEmpty);
  for (i = 0; i < lengthEmpty; i++) {
    cout << empty[i] << ' ';
  }
  cout << '\n';

  return 0;
}
