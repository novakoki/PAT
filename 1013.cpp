#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>
#include <iomanip>
#include <map>
#include <string>
#include <cstdio>
#include <cstring>
using namespace std;


int check = 0;
int components = 1;
vector<bool> visited;
vector<vector<int> > graph;

void dfs(int s) {
  if (visited[s]) return;
  visited[s] = true;
  for (auto it = graph[s].begin(); it != graph[s].end(); it++) {
    if (!visited[*it] && *it != check) dfs(*it);
  }
  for (int i = 1; i < visited.size(); i++) {
    if (!visited[i] && i != check) {
      components++;
      dfs(i);
    }
  }
}

int main() {
  int n, m, k, a, b;
  while (cin >> n >> m >> k) {
    graph.resize(n + 1);
    visited.resize(n + 1);
    while (m--) {
      cin >> a >> b;
      graph[a].push_back(b);
      graph[b].push_back(a);
    }
    while (k--) {
      fill(visited.begin(), visited.end(), false);
      components = 1;
      cin >> check;
      dfs(1);
      cout << components - 1 << endl;
    }
  }
  return 0;
}