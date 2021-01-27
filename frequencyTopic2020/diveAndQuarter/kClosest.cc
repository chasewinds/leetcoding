#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;


// best way is part quick select
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int K) {
        vector<pair<double, vector<int>>> input = vector<pair<double, vector<int>>>(points.size());
        for (int i = 0; i < points.size(); i++) {
            double dis = sqrt(pow(points[i][0], 2) + pow(points[i][1], 2));
            input[i] = {dis, points[i]};
        }
        quickSelect(input, 0, points.size() - 1, K);
        vector<vector<int>> res;
        for (int i = 0; i < K; i++) {
            res.push_back(input[i].second);
        }
        return res;
    }

    void quickSelect(vector<pair<double, vector<int>>> &input, int l, int r, int k) {
        if (l > r) {
            return;
        }
        int pivotIdx = rand() % (r - l + 1) + l;
        int pivot = partition(input, l, r, pivotIdx);
        if (pivot == k) {
            return;
        }
        if (pivot - l + 1 > k) {
            quickSelect(input, l, pivot - 1, k);
        } else if (pivot - l + 1 < k) { // important! 这里一定要加判断，不是前两个判断完了就一定 pivot - l + 1 < k
            quickSelect(input, pivot + 1, r, k - (pivot - l + 1));
        }
    }

    int partition(vector<pair<double, vector<int>>> &a, int l, int r, int pivot) {
        double pivotValue = a[pivot].first;
        swap(a[r], a[pivot]);
        int storeIdx = l;
        for (int i = l; i < r; i++) {
            if (a[i].first <= pivotValue) {
                swap(a[storeIdx], a[i]);
                storeIdx++;
            }
        }
        swap(a[storeIdx], a[r]);
        return storeIdx;
    }
};


/*
// runtime 79.60% memo 13.66% by priority queue
class Solution {
public:
    vector <vector<int>> kClosest(vector <vector<int>> &points, int K) {
        if (points.empty()) {
            return {};
        }
        priority_queue < pair < double, vector < int>>> q;
        for (auto e : points) {
            double dis = sqrt(pow(e[0], 2) + pow(e[1], 2));
            q.push({dis, e});
        }
        while (q.size() > K) {
            q.pop();
        }
        vector <vector<int>> res;
        while (q.size() > 0) {
            res.push_back(q.top().second);
            q.pop();
        }
        return res;
    }
};
*/