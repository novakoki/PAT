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

int main() {
  /*freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);*/
  int n, l, m, u, k;
  cin >> n >> l;
  vector<vector<int> > graph;
  graph.resize(n+1);
  for (int i = 1; i <= n; i++) {
    cin >> m;
    while (m--) {
      cin >> u;
      graph[u].push_back(i);
    }
  }
  cin >> k;
  while (k--) {
    vector<bool> visited(n + 1, false);
    vector<int> d(n + 1, INT_MAX);
    queue<int> q;
    int sum = 0, level = 0;
    cin >> u;
    q.push(u);
    d[u] = 0;
    while (!q.empty()) {
      int t = q.front(); q.pop();
      if (d[t] > l) break;
      if (visited[t]) continue;
      visited[t] = true;

      for (auto item : graph[t]) {
        q.push(item);
        d[item] = min(d[item], d[t] + 1);
      }
      if (t != u)
        sum++;
    }
    cout << sum << endl;
  }
  return 0;
}