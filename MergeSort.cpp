#include <iostream>
using std::cout;

int* merge(int a[], int a_length, int b[], int b_length) {
  int *sorted = new int[a_length + b_length];
  int i, j, k;
  i = j = k = 0;
  while ((i < a_length) && (j < b_length)) {
    if (a[i] <= b[j]) {
      sorted[k] = a[i];
      i++;
    } else {
      sorted[k] = b[j];
      j++;
    }
    k++;
  }
  for (; i < a_length; i++) {
    sorted[k] = a[i];
    k++;
  }
  for (; j < b_length; j++) {
    sorted[k] = b[j];
    k++;
  }
  delete[] a;
  delete[] b;
  return sorted;
}

int* mergesort(int arr[], int length) {
  if (length == 1) {
    int *new_arr = new int[1];
    new_arr[0] = arr[0];
    return new_arr;
  }
  int mid = length / 2;

  int left_length = mid;
  int *left = new int[left_length];
  int right_length = length - mid;
  int *right = new int[right_length];

  int i = 0;
  int j = 0;
  for (; i < mid; i++) {
    left[j] = arr[i];
    j++;
  }
  j = 0;
  for (; i < length; i++) {
    right[j] = arr[i];
    j++;
  }
  int *sorted = merge(mergesort(left, left_length), left_length,
                      mergesort(right, right_length), right_length);
  delete[] left;
  delete[] right;
  return sorted;
}

int main() {
  int length1 = 10;
  int arr1[] = {2, 3, 8, 8, 7, 7, 7, 8, 9, 10};
  int length2 = 9;
  int arr2[] = {2, 3, 5, 5, 6, 7, 9, 8, 9};
  int i;
  int *sorted1 = mergesort(arr1, length1);
  for (i = 0; i < length1; i++) {
    cout << sorted1[i] << ' ';
  }
  cout << '\n';
  int *sorted2 = mergesort(arr2, length2);
  for (i = 0; i < length2; i++) {
    cout << sorted2[i] << ' ';
  }
  cout << '\n';
  delete[] sorted1;
  delete[] sorted2;
  return 0;
}
