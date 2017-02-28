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
#include <memory>
#include <valarray>
#include <numeric>
#include <functional>
using namespace std;

int main() {
#ifdef _DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int n, k, id;
  double p, r;
  scanf("%d %lf %lf", &n, &p, &r);
  vector<vector<int> > graph;
  graph.resize(n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &k);
    while (k--) {
      scanf("%d", &id);
      graph[i].push_back(id);
    }
  }
  vector<int> d(n, 0);
  int m = INT_MAX, number = 0;
  queue<int> q;
  q.push(0);
  while (!q.empty()) {
    int t = q.front(); q.pop();
    if (d[t] > m)
      continue;
    if (graph[t].empty()) {
      if (d[t] < m) {
        number = 1;
        m = d[t];
      }
      else if (d[t] == m) {
        number++;
      }
    }
    else {
      for (auto item : graph[t]) {
        q.push(item);
        d[item] = d[t] + 1;
      }
    }
  }
  printf("%.4lf %d\n", p * pow(1 + r / 100.0, m), number);
  return 0;
}