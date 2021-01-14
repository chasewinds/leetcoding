#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class UnionFind {
 public:
  vector<int> parent;
  vector<double> weight;

  UnionFind(int n) {
    parent = vector<int>(n);
    weight = vector<double>(n, 1.0);
    for (int i = 0; i < n; i++) {
      parent[i] = i;
    }
  }

  void merge(int x, int y, double value) {
    int rootX = find(x);
    int rootY = find(y);

    if (rootX == rootY) {
      return;
    }

    parent[rootX] = rootY;
    weight[x] = value * weight[y] / weight[x];
  }

  int find(int x) {
    // need to search parent
    if (x != parent[x]) {
      int xOriginParent = parent[x];
      parent[x] = find(parent[x]);
      weight[x] = weight[x] * weight[xOriginParent];
    }
    return parent[x];
  }

  double isConnected(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);
    if (rootX == rootY) {
      return weight[x] / weight[y];
    }
    return -1.0;
  }
};

class Solution {
 public:
  vector<double> calcEquation(vector<vector<string>>& equations,
                              vector<double>& values,
                              vector<vector<string>>& queries) {

    UnionFind* uf = new UnionFind(equations.size() * 2);
    int id = 0;
    unordered_map<string, int> var2i;
    for (int i = 0; i < equations.size(); i++) {
      vector<string> equation = equations[i];
      if (var2i.find(equation[0]) == var2i.end()) {
        var2i[equation[0]] = id;
        id++;
      }
      if (var2i.find(equation[1]) == var2i.end()) {
        var2i[equation[1]] = id;
        id++;
      }
      uf->merge(var2i[equation[0]], var2i[equation[1]], values[i]);
    }

//    UnionFind* uf = new UnionFind(id);
//    for (int i = 0; i < equations.size(); i++) {
//      int xi = var2i[equations[i][0]];
//      int yi = var2i[equations[i][1]];
//      uf->merge(xi, yi, values[i]);
//    }

    vector<double> res;
    for (auto ele : queries) {
      if (var2i.find(ele[0]) == var2i.end() ||
          var2i.find(ele[1]) == var2i.end()) {
        res.push_back(-1.0);
        continue;
      }
      res.push_back(uf->isConnected(var2i[ele[0]], var2i[ele[1]]));
    }

    return res;
  }
};

int main() {
  vector<vector<string>> equations = {{"x1", "x2"}, {"x2", "x3"}, {"x1", "x4"}, {"x2", "x5"}};
  vector<double> values = {3.0, 0.5, 3.4, 5.6};
  vector<vector<string>> queries = {{"x2", "x4"}, {"x1", "x5"}, {"x1", "x3"}, {"x5", "x5"}, {"x5", "x1"}, {"x3", "x4"}, {"x4", "x3"}, {"x6", "x6"}, {"x0", "x0"}};
  auto s = new Solution;
  vector<double> res = s->calcEquation(equations, values, queries);
  for (auto x: res) {
    cout << x << " ";
  }
  cout << endl;
  cout << "except: " << "[1.13333,16.8,1.5,1.0,0.05952,2.26667,0.44118,-1.0,-1.0]" << endl;
  return 0;
}