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
  int n, k, id;
  double p, r;
  scanf("%d%lf%lf", &n, &p, &r);
  vector<vector<int> > graph;
  vector<int> amount(n, 0);
  graph.resize(n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &k);
    if (k == 0) {
      scanf("%d", &id);
      amount[i] = id;
    }
    else {
      while (k--) {
        scanf("%d", &id);
        graph[i].push_back(id);
      }
    }
  }

  vector<bool> visited(n);
  vector<double> price(n, INT_MAX);
  queue<int> q;
  price[0] = p;
  q.push(0);
  double sum = 0.0;

  while (!q.empty()) {
    int t = q.front(); q.pop();
    if (visited[t]) continue;
    visited[t] = true;
    
    for (auto item : graph[t]) {
      q.push(item);
      price[item] = min(price[item], price[t] * (1 + r / 100));
    }

    if (graph[t].empty())
      sum += price[t] * amount[t];
  }

  printf("%.1lf", sum);
  return 0;
}