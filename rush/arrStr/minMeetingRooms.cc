#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int minMeetingRooms(vector<vector<int>> &intervals) {
        sort(intervals.begin(), intervals.end());
        // 要定义元素为vector<int> 的最小堆，得这么写：
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> roomQ;
        for (auto x : intervals) {
            swap(x[0], x[1]); // 不想自定义按第二个元素排序的最小堆，只好交换元素位置（priority_queue默认按vector<int>的第一个元素排序）
            if (!roomQ.empty() && roomQ.top()[0] <= x[1]) {
                roomQ.pop();
            }
            roomQ.push(x);
        }
        return roomQ.size();
    }
};