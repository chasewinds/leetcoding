#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  void mergeSort(vector<int>& list) {
    mergeSortTopDown(list, 0, list.size() - 1);
 }

  void mergeSortTopDown(vector<int>& list, int left, int right) {
    if (left >= right) {
      return;
    }
//    int partition = (left + right) / 2;
    int partition = left + (right - left) / 2;
    mergeSortTopDown(list, left, partition);
    mergeSortTopDown(list, partition + 1, right);
    merge(list, left, right, partition);
  }

  void merge(vector<int>& list, int left, int right, int partition) {
    vector<int> forMerge(right - left + 1);
    int mp = 0;
    int p1 = left;
    int p2 = partition + 1;
    while (p1 <= partition && p2 <= right) {
      if (list[p1] <= list[p2]) {
        forMerge[mp++] = list[p1++];
      } else {
        forMerge[mp++] = list[p2++];
      }
    }


    while (p1 <= partition) {
      forMerge[mp++] = list[p1++];
    }

    while (p2 <= right) {
      forMerge[mp++] = list[p2++];
    }
//    cout << "for merge: ";
//    printList(forMerge);
//    cout << "mp: " << mp << endl;

    for (int i = 0; i < forMerge.size(); i++) {
      list[i + left] = forMerge[i];
    }
//    cout << "after merged: ";
//    printList(list);
  }


  void printList(vector<int> list) {
    for (int x: list) {
      cout << x << ",";
    }
    cout << endl;
  }
};

int main() {

  auto s = new Solution;
  vector<int> list = {1, 5, 3, 2, 8, 7, 6, 4};
  s->mergeSort(list);
  for (int x: list) {
    cout << x << ",";
  }
  return 0;
}