#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <cstdio>
#include <algorithm>
using namespace std;

int main () {
  int n, m;
  scanf("%d %d", &n, &m);
  vector<bool> tmp(n+1, false);
  vector<vector<bool> > graph(n+1, tmp);
  
  int u, v;
  while (m--) {
    scanf("%d %d", &u, &v);
    graph[u][v] = true;
    graph[v][u] = true;
  }
  int k;
  scanf("%d", &k);
  while (k--) {
    scanf("%d", &m);
    vector<bool> visited(n+1, false);
    scanf("%d" ,&u);m--;
    visited[u] = true;
    int start = u;
    bool hami = true;

    while (m--) {
      scanf("%d", &v);
      if (graph[u][v]) {
        if (m != 0 && visited[v])
          hami = false;
        u = v;
        visited[u] = true;
      }
      else
        hami = false;
    }
    if (start != u)
      hami = false;
    for (int i = 1; i <= n; i++) {
      if (!visited[i]) {
        hami = false;
        break;
      }
    }
    if (hami)
      printf("YES\n");
    else
      printf("NO\n");
  }
  return 0;
}