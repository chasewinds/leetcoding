#include <iostream>
#include <queue>
#include <vector>

using namespace std;

/*
// dfs, if use addition vector<vector<bool>> visited metrix as memo, 45/46 case
will TLE.
// can only modify origin matrix.
class Solution {
 public:
  int numIslands(vector<vector<char>>& grid) {
    if (grid.empty() || grid[0].empty()) {
      return 0;
    }
    int h = grid.size();
    int w = grid[0].size();
    int res = 0;
    for (int i = 0; i < grid.size(); i++) {
      for (int j = 0; j < grid[0].size();j++) {
        if (grid[i][j] == '1') {
          dfs(i, j, grid, h, w);
          res++;
        }
      }
    }
    return res;
  }
  void dfs(int x, int y, vector<vector<char>>& grid, int h, int w) {
    grid[x][y] = '0';
    if (x + 1 < h && grid[x + 1][y] == '1') {
      dfs(x + 1, y, grid, h, w);
    }
    if (y + 1 < w && grid[x][y + 1] == '1') {
      dfs(x, y + 1, grid, h, w);
    }
    if (x - 1 >= 0 && grid[x - 1][y] == '1') {
      dfs(x - 1, y, grid, h, w);
    }
    if (y - 1 >= 0 && grid[x][y - 1] == '1') {
      dfs(x, y - 1, grid, h, w);
    }
  }
};
*/

/*
class Solution {
 public:
  int numIslands(vector<vector<char>>& grid) {
    if (grid.empty() || grid[0].empty()) {
      return 0;
    }
    queue<pair<int, int>> q;
    int res = 0;
    int h = grid.size();
    int w = grid[0].size();
    for (int i = 0; i < grid.size(); i++) {
      for (int j = 0; j < grid[0].size(); j++) {
        if (grid[i][j] == '1') {
          res++;
          q.push({i, j});
          while (!q.empty()) {
            int layerSize = q.size();
            for (int x = 0; x < layerSize; x++) {
              auto top = q.front();
              q.pop();
              if (top.first + 1 < h && grid[top.first + 1][top.second] == '1') {
                q.push({top.first + 1, top.second});
                // 在进队列时候把grid设成1，而不是出队列的时候，才可以ac :)
否则37个case就TLE了 grid[top.first + 1][top.second] = '0';
              }
              if (int x = top.first - 1; x >= 0 && grid[x][top.second] == '1') {
                q.push({x, top.second});
                grid[x][top.second] = '0';
              }
              if (int y = top.second - 1; y >= 0 && grid[top.first][y] == '1') {
                q.push({top.first, y});
                grid[top.first][y] = '0';
              }
              if (int y = top.second + 1; y < w && grid[top.first][y] == '1') {
                q.push({top.first, y});
                grid[top.first][y] = '0';
              }
            }
          }
        }
      }
    }
    return res;
  }
};
*/

// union find solution, runtime 96.94% but memo just 12.06%
class UnionFind {
 private:
  vector<int> parent;
  vector<int> rank;

 public:
  int count;
  UnionFind(vector<vector<char>> grid) {
    count = 0;
    int w = grid[0].size();
    for (int i = 0; i < grid.size(); i++) {
      for (int j = 0; j < grid[0].size(); j++) {
        if (grid[i][j] == '1') {
          parent.push_back(i * w + j);
          count++;
        } else {
          parent.push_back(-1);
        }
        rank.push_back(0);
      }
    }
  }

  int Find(int x) {
    if (x == parent[x]) {
      return x;
    }
    parent[x] = Find(parent[x]);
    return parent[x];
  }

  void Union(int x, int y) {
    int rootX = Find(x);
    int rootY = Find(y);
    if (rootX == rootY) {
      return;
    }
    if (rank[rootX] > rank[rootY]) {
      parent[rootY] = rootX;
    } else if (rank[rootY] > rank[rootX]) {
      parent[rootX] = rootY;
    } else {
      parent[rootY] = rootX;
      rank[rootX]++;
    }
    count--;
  }
};

class Solution {
 public:
  int numIslands(vector<vector<char>>& grid) {
    if (grid.empty() || grid[0].empty()) {
      return 0;
    }

    UnionFind* uf = new UnionFind(grid);
    int idx = 0;
    int h = grid.size();
    int w = grid[0].size();
    for (int i = 0; i < grid.size(); i++) {
      for (int j = 0; j < grid[0].size(); j++) {
        //   cout << "i: " << i << " j: " << j << endl;
        idx++;
        if (grid[i][j] == '1') {
          grid[i][j] = '0';
          int cur = i * w + j;
          if (i - 1 >= 0 && grid[i - 1][j] == '1') {
            uf->Union(cur, w * (i - 1) + j);
          }
          if (i + 1 < h && grid[i + 1][j] == '1') {
            uf->Union(cur, w * (i + 1) + j);
          }
          if (j + 1 < w && grid[i][j + 1] == '1') {
            uf->Union(cur, w * i + j + 1);
          }
          if (j - 1 >= 0 && grid[i][j - 1] == '1') {
            uf->Union(cur, w * i + j - 1);
          }
        }
      }
    }
    return uf->count;
  }
};