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
  
  int n;
  double p, r;
  scanf("%d %lf %lf", &n, &p, &r);
  vector<vector<int> > graph;
  graph.resize(n);
  int s, root = 0;
  for (int i = 0; i < n; i++) {
    scanf("%d", &s);
    if (s == -1) {
      root = i;
    }
    else {
      graph[s].push_back(i);
    }
  }
  queue<int> q;
  q.push(root);
  vector<int> d(n, 0);
  int deepest = 0, number = 1;
  while (!q.empty()) {
    auto t = q.front(); q.pop();
    for (auto item : graph[t]) {
      q.push(item);
      d[item] = d[t] + 1;
      if (deepest < d[item]) {
        number = 1;
        deepest = d[item];
      }
      else if (deepest == d[item]) {
        number++;
      }
    }
  }
  printf("%.2lf %d", p * pow(1 + r / 100, deepest), number);
  return 0;
}