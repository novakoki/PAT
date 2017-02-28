#include <iostream>
#include <sstream>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>
#include <iomanip>
#include <map>
#include <unordered_map>
#include <string>
#include <cstdio>
#include <cstring>
#include <climits>
using namespace std;

map<string, map<string, int> > graph;
map<string, bool> visited;

void dfs(string s, string& head, int& head_weight, int& cluster_number, int& cluster_weight) {
  if (visited[s]) return;
  visited[s] = true;
  int total = 0;
  for (auto it = graph[s].begin(); it != graph[s].end(); it++)
    total += it->second;
  if (total > head_weight) {
    head = s;
    head_weight = total;
  }
  cluster_number++;
  cluster_weight += total;
  for (auto it = graph[s].begin(); it != graph[s].end(); it++)
    dfs(it->first, head, head_weight, cluster_number, cluster_weight);
}

int main() {
  int N, K;
  cin >> N >> K;
  string from, to; int weight;
  map<string, int> res;
  while (N--) {
    cin >> from >> to >> weight;
    visited[from] = visited[to] = false;
    if (graph[from].find(to) == graph[from].end()) {
      graph[from][to] = weight;
    }
    else graph[from][to] += weight;
    if (graph[to].find(from) == graph[to].end()) {
      graph[to][from] = weight;
    }
    else graph[to][from] += weight;
  }
  for (auto it = visited.begin(); it != visited.end(); it++) {
    if (!it->second) {
      int cluster_weight = 0, head_weight = 0, cluster_number = 0;
      string head = "";
      dfs(it->first, head, head_weight, cluster_number, cluster_weight);
      //cout << head << ' ' << cluster_weight << endl;
      if (cluster_weight > 2*K && cluster_number > 2)
        res[head] = cluster_number;
    }
  }
  cout << res.size() << endl;
  for (auto it = res.begin(); it != res.end(); it++) {
    cout << it->first << ' ' << it->second << endl;
  }
  return 0;
}