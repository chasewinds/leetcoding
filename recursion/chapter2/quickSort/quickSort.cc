#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  void quickSort(vector<int>& list) {
    if (list.empty()) {
      return;
    }
    int l = list.size() - 1;
    quickSortByRange(list, 0, l);
  }

  void quickSortByRange(vector<int>& list, int start, int end) {
    if (start >= end) {
      return;
    }
    int pidx = partition(list, start, end);
    quickSortByRange(list, start, pidx - 1);
    quickSortByRange(list, pidx + 1, end);
  }

  int partition(vector<int>& list, int start, int end) {
    int pivot = list[end];
    int pi = start;
    for (int i = start; i < end; i++) {
      if (list[i] < pivot) {
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

int main() {
  auto s = new Solution;
  vector<int> unsorted = {1, 5, 3, 2, 8, 7, 6 ,4};
  s->quickSort(unsorted);
  for (int x : unsorted) {
    cout << x;
  }
  cout << endl;
  return 0;
}