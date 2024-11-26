#include <iostream>
using namespace std;

typedef struct coord {
  int x;
  int y;
} coord;

void swap(coord &a, coord &b) {
  coord temp = a;
  a = b;
  b = temp;
}

void insertion_sort(coord arr[], int start, int end) {
  for (int i = start + 1; i <= end; i++) {
    coord key = arr[i];
    int j = i - 1;
    while (j >= start && (arr[j].y > key.y || (arr[j].y == key.y && arr[j].x > key.x))) {
      arr[j + 1] = arr[j];
      j--;
    }
    arr[j + 1] = key;
  }
}

void quick_sort(coord arr[], int start, int end) {
  if (start >= end)
    return;

  if (end - start + 1 <= 15) {
    insertion_sort(arr, start, end);
    return;
  }

  int mid = (start + end) / 2;

  if ((arr[start].y > arr[mid].y) || (arr[start].y == arr[mid].y && arr[start].x > arr[mid].x)) {
    swap(arr[start], arr[mid]);
  }
  if ((arr[start].y > arr[end].y) || (arr[start].y == arr[end].y && arr[start].x > arr[end].x)) {
    swap(arr[start], arr[end]);
  }
  if ((arr[mid].y > arr[end].y) || (arr[mid].y == arr[end].y && arr[mid].x > arr[end].x)) {
    swap(arr[mid], arr[end]);
  }

  swap(arr[start], arr[mid]);
  coord pivot = arr[start];

  int left = start + 1;
  int right = end;

  while (left <= right) {
    while (left <= end && (arr[left].y < pivot.y || (arr[left].y == pivot.y && arr[left].x < pivot.x))) {
      left++;
    }
    while (right >= start && (arr[right].y > pivot.y || (arr[right].y == pivot.y && arr[right].x > pivot.x))) {
      right--;
    }
    if (left <= right) {
      swap(arr[left], arr[right]);
      left++;
      right--;
    }
  }

  swap(arr[start], arr[right]);

  quick_sort(arr, start, right - 1);
  quick_sort(arr, right + 1, end);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  coord *arr = new coord[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i].x >> arr[i].y;
  }

  quick_sort(arr, 0, n - 1);

  for (int i = 0; i < n; i++) {
    cout << arr[i].x << " " << arr[i].y << "\n";
  }
  delete[] arr;
}