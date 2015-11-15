#include <iostream>
using std::cout;

int binary_search(int arr[], int val, int left, int right) {
  if (left > right) {
    return -1;
  }

  int mid = (left + right) / 2;
  if (val < arr[mid]) {
    return binary_search(arr, val, left, mid-1);
  } else if (val > arr[mid]) {
    return binary_search(arr, val, mid+1, right);
  } else {
    return mid;
  }
}

int binary_search_iter(int arr[], int val, int left, int right) {
  while (left <= right) {
    int mid = (left + right) / 2;
    if (val < arr[mid]) {
      right = mid - 1;
    } else if (val > arr[mid]) {
      left = mid + 1;
    } else {
      return mid;
    }
  }
  return -1;
}

int main() {
  int arr[] = {1, 3, 5, 7, 9, 11, 15};
  int arr_length = 7;
  cout << "Should return 2: " << binary_search(arr, 5, 0, arr_length) << '\n';
  cout << "Should return 2: " << binary_search_iter(arr, 5, 0, arr_length) << '\n';
  cout << "Should return -1: " << binary_search(arr, 6, 0, arr_length) << '\n';
  cout << "Should return -1: " << binary_search_iter(arr, 6, 0, arr_length) << '\n';
  cout << "Should return 6: " << binary_search(arr, 15, 0, arr_length) << '\n';
  cout << "Should return 6: " << binary_search_iter(arr, 15, 0, arr_length) << '\n';
  return 0;
}
