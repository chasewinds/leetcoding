#include <iostream>
#include <vector>

using namespace std;

template <class T>

class Solution {
 public:
  void quickSort(vector<T>& list, bool (*less)(const void *, const void *)) {
    if (list.empty()) {
      return;
    }
    int l = list.size() - 1;
    quickSortByRange(list, 0, l, less);
  }

  void quickSortByRange(vector<T>& list, int start, int end, bool (*less)(const void *, const void *)) {
    if (start >= end) {
      return;
    }
    int pidx = partition(list, start, end, less);
    quickSortByRange(list, start, pidx - 1, less);
    quickSortByRange(list, pidx + 1, end, less);
  }

  int partition(vector<T>& list, int start, int end, bool (*less)(const void *, const void *)) {
    int pivot = list[end];
    int pi = start;
    for (int i = start; i < end; i++) {
      if (less(&list[i], &pivot)) {
        swap(list[pi], list[i]);
        pi++;
      }
    }
    swap(list[pi], list[end]);
    return pi;
  }

  void printList(vector<int> list) {
    for (int x: list) {
      cout << x;
    }
    cout << endl;
  }
};

bool myLess(const void * x, const void * y) {
  int *p1, *p2;
  p1 = (int *) x;
  p2 = (int *) y;
  return *p1 < *p2;
}

int main() {
  auto s = new Solution<int>;
  vector<int> unsorted = {1, 5, 3, 2, 8, 7, 6 ,4};

  s->quickSort(unsorted, myLess);
  for (int x : unsorted) {
    cout << x;
  }
  cout << endl;
  return 0;
}
