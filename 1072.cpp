#include <iostream>
#include <sstream>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>
#include <iomanip>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <set>
#include <stack>
#include <cstdio>
#include <cstring>
#include <climits>
#include <cstdlib>
using namespace std;

struct Node {
  int u, d;
  Node(){}
  Node(int u, int d):u(u),d(d){}
  bool operator<(const Node& rhs) const {
    return d > rhs.d;
  }
};

int strToInt(const string& s, int offset) {
  if (s[0] == 'G')
    return stoi(s.substr(1)) + offset;
  else
    return stoi(s);
}

int main() {
  int n, m, k, ds, dist;
  string from, to;
  cin >> n >> m >> k >> ds;
  vector<vector<Node> > graph;
  graph.resize(n + m + 1);
  while (k--) {
    cin >> from >> to >> dist;
    graph[strToInt(from, n)].push_back(Node(strToInt(to, n), dist));
    graph[strToInt(to, n)].push_back(Node(strToInt(from, n), dist));
  }
  double res_min = 0, res_avg = INT_MAX;
  int res_index = -1;
  for (int i = n+1; i <= m+n; i++) {
    vector<int> d(n + m + 1, INT_MAX);
    vector<bool> visited(n + m + 1, false);
    priority_queue<Node> q;
    q.push(Node(i, 0));
    d[i] = 0;

    while (!q.empty()) {
      Node node = q.top(); q.pop();
      if (visited[node.u]) continue;
      visited[node.u] = true;

      for (auto item : graph[node.u]) {
        if (d[node.u] + item.d < d[item.u]) {
          d[item.u] = d[node.u] + item.d;
          q.push(Node(item.u, d[item.u]));
        }
      }
    }

    double sum = 0;
    int min_dis = INT_MAX, max_dis = 0;
    for (int i = 1; i <= n; i++) {
      sum += d[i];
      min_dis = min(min_dis, d[i]);
      max_dis = max(max_dis, d[i]);
    }
    if (max_dis <= ds) {
      double avg = sum / n;
      if ((min_dis > res_min) ||
        ((min_dis == res_min) && (avg < res_avg))) {
        res_index = i - n;
        res_min = min_dis;
        res_avg = avg;
      }
    }
  }
  if (res_index == -1) {
    printf("No Solution\n");
  }
  else {
    printf("G%d\n%.1f %.1f\n", res_index, res_min, res_avg);
  }
  return 0;
}