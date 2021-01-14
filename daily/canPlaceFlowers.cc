#include <iostream>
#include <vector>

using namespace std;

/*
// back track can only pass 84 / 124 test case, TLE err.
class Solution {
 public:
  bool canPlaceFlowers(vector<int>& flowewrbed, int n) {
    if (flowewrbed.empty()) {
      return false;
    }

    return backTrack(flowewrbed, 0, 0, n);
  }

  bool backTrack(vector<int>& place, int idx, int curN, int targetN) {
//    cout << "curN: " << curN << " targetN: " << targetN << endl;
    if (curN == targetN) {
      return true;
    }

    for (int i = idx; i < place.size(); i++) {
      if (place[i] != 1) {
        int ahead = 0;
        int next = place.size() - 1;
        if (i != 0) {
          ahead = i - 1;
        }
        if (i != place.size() - 1) {
          next = i + 1;
        }
        if (place[ahead] != 1 && place[next] != 1) {
//          cout << "i: " << i << " place[i]: " << place[i] << " place[i - 1]: "
<< place[i - 1] << " place[i + 1]: " << place[i + 1] << endl; place[i] = 1; if
(backTrack(place, i + 1, curN + 1, targetN)) { return true;
          }
          place[i] = 0;
        }
      }
    }

    return false;
  }
};
*/

class Solution {
 public:
  bool canPlaceFlowers(vector<int>& flowerbed, int n) {
    if (flowerbed.empty()) {
      return false;
    }

    if (flowerbed.size() == 1) {
      return (flowerbed[0] == 0 && n == 1) || n == 0;
    }

    int total = 0;
    int prev = -1;
    int i = 0;
    while (i < flowerbed.size()) {
      if (flowerbed[i] == 1) {
        if (prev == -1) {
          total += i / 2;
        } else {
          if (i - prev >= 3) {
            total += (i - prev - 2) / 2;
          }
        }
        prev = i;
      }
      i++;
    }

    if (prev < 0) {
      total += (flowerbed.size() + 1) / 2;
    } else {
      total += (flowerbed.size() - prev - 1) / 2;
    }

    return total >= n;
  }
};

int main() {
  auto s = new Solution;
  vector<int> inputFlowers = {0};
  cout << s->canPlaceFlowers(inputFlowers, 0);

  //  vector<int> bigInput =
  //  {1,0,1,0,1,0,1,0,0,1,0,1,0,1,0,0,1,0,1,0,1,0,0,0,1,0,0,0,1,0,1,0,1,0,0,0,1,0,1,0,1,0,0,1,0,1,0,0,1,0,0,0,0,1,0,1,0,1,0,1,0,0,1,0,0,0,0,0,0,1,0,0,1,0,1,0,1,0,0,0,0,0,1,0,0,1,0,0,1,0,0,1,0,0,0,0,1,0,0,1,0,0,1,0,0,0,1,0,1,0,1,0,0,1,0,1,0,0,1,0,1,0,0,0,0,0,1,0,1,0,1,0,1,0,1,0,0,1,0,0,0,0,1,0,0,0,0,0,1,0,0,1,0,0,0,1,0,1,0,0,0,0,0,1,0,1,0,1,0,0,0,1,0,0,1,0,0,1,0,0,1,0,1,0,0,0,1,0,0,0,0,1,0,0,1,0,0,1,0,1,0,1,0,0,1,0,1,0,1,0,0,0,1,0,1,0,1,0,1,0,1,0,0,0,1,0,1,0,0,0,0,0,0,1,0,0,0,1,0,1,0,0,0,1,0,0,0,1,0,1,0,0,1,0,0,1,0,1,0,0,0,1,0,1,0,1,0,1,0,0,0,0,0,1,0,0,1,0,0,1,0,0,1,0,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,0,0,0,1,0,0,1,0,1,0,1,0,1,0,0,1,0,1,0,0,0,1,0,1,0,1,0,1,0,0,0,1,0,1,0,0,0,0,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,1,0,1,0,0,0,0,0,0,1,0,1,0,1,0,1,0,0,0,1,0,1,0,0,1,0,1,0,1,0,0,1,0,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,0,0,0,1,0,0,0,1,0,1,0,0,1,0,0,0,0,0,1,0,0,0,1,0,1,0,0,1,0,0,1,0,0,0,0,0,0,1,0,1,0,0,0,1,0,1,0,1,0,0,1,0,0,0,0,1,0,1,0,0,0,1,0,0,0,0,1,0,0,0,1,0,1,0,0,1,0,0,1,0,1,0,1,0,1,0,0,0,0,1,0,1,0,1,0,0,0,0,0,1,0,0,0,1,0,1,0,1,0,0,0,1,0,1,0,1,0,1,0,0,1,0,0,1,0,1,0,0,1,0,0,0,1,0,1,0,0,1,0,0,0,1,0,1,0,0,1,0,1,0,0,1,0,0,0,1,0,0,0,1,0,1,0,1,0,1,0,0,1,0,0,0,0,1,0,1,0,1,0,0,0,1,0,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,0,0,0,1,0,1,0,0,0,0,1,0,1,0,1,0,0,0,0,1,0,1,0,0,0,1,0,0,1,0,1,0,0,0,0,0,0,1,0,1,0,1,0,1,0,1,0,0,0,1,0,0,1,0,0,0,0,1,0,0,1,0,0,1,0,1,0,0,1,0,0,0,1,0,1,0,0,0,0,0,0,1,0,1,0,0,0,1,0,0,1,0,1,0,0,0,0,1,0,0,1,0,0,0,1,0,1,0,1,0,1,0,1,0,1,0,0,1,0,1,0,1,0,0,0,1,0,1,0,1,0,1,0,0,1,0};
  //  cout << s->canPlaceFlowers(bigInput, 223);

  return 0;
}