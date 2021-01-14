#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>

using namespace std;

/*
class Solution {
    public:
        vector<int> findRedundantConnection(vector<vector<int>>& edges) {

            if (edges.size() == 0) {
                return vector<int>{0, 0};
            }

            vector<vector<int>> graph = vector<vector<int>>(edges.size() * 2);
            for (int i = 0; i < edges.size(); i++) {
                int n1 = edges[i][0];
                int n2 = edges[i][1];
                if (!graph[n1].empty()) {
                    graph[n1].push_back(n2);
                } else {
                    graph[n1] = vector<int>{n2};
                }
                if (!graph[n2].empty()) {
                    graph[n2].push_back(n1);
                } else {
                    graph[n2] = vector<int>{n1};
                }
            }

            unordered_map<int, bool> visited;
            stack<int> stk;
            stk.push(edges[0][0]);
            while (!stk.empty()) {
                stack<int> nextLayer;
                while (!stk.empty()) {
                    int top = stk.top();
                    if (auto it = visited.find(top); it != visited.end()) {
                        return vector<int>{it->first}; // todo 
                    }
                    visited.insert({top, true});
                    stk.pop();
                    if (!graph[top].empty()) {
                        for (auto x: graph[top]) {
                            nextLayer.push(x);
                        }
                    }
                }
                stk = nextLayer;
            }

            return vector<int>{0, 0};
        }
};
*/

class Solution {
    public:

        int Find(vector<int>& parents, int x) {
            if (parents[x] != x) {
                parents[x] = Find(parents, parents[x]);
            }
            return parents[x];
        }

        void Union(vector<int>& parents, int x, int y) {
            parents[Find(parents, x)] = Find(parents, y);
        }

        vector<int> findRedundantConnection(vector<vector<int>>& edges) {
            int nodesCount = edges.size();
            vector<int> parents = vector<int>(nodesCount + 1);
            for (int i = 0; i < parents.size(); i++) {
                parents[i] = i;
            }

            for (int i = 0; i < edges.size(); i++) {
                if (Find(parents, edges[i][0]) == Find(parents, edges[i][1])) {
                    return edges[i];
                }
                Union(parents, edges[i][0], edges[i][1]);
            }

            return vector<int>();
        }
};

int main() {
    auto s = new Solution;
    vector<vector<int>> edges = {{1, 2}, {1, 3}, {2, 3}};
    vector<int> res = s->findRedundantConnection(edges);
    cout << res[0] << endl;
    cout << res[1] << endl;
}