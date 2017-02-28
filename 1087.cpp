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

int str_to_int(char* s) {
  return (s[0] - 'A') * 26 * 26 +
    (s[1] - 'A') * 26 +
    s[2] - 'A';
}

const int capacity = 26 * 26 * 26;
char Rome[3] = { 'R', 'O', 'M' };
const int dest = str_to_int(Rome);

struct Node {
  int u, cost;

  Node (){}
  Node (int u, int c):u(u), cost(c){}

  bool operator< (const Node& rhs) const {
    return cost > rhs.cost;
  }
};

char start[4];
int s = 0;
vector<int> happiness(capacity, 0);
vector<vector<Node> > graph;
vector<bool> visited(capacity, false);
vector<int> dist(capacity, INT_MAX);
vector<vector<int> > p;
vector<int> path, temppath;
int total_passed = 0, total_happ = 0, total_paths = 0;

void dfs(int d) {
  temppath.push_back(d);
  if (d == s) {
    int passed = -1, happ = 0;
    for (auto it = temppath.rbegin(); it != temppath.rend(); it++) {
      passed++;
      happ += happiness[*it];
    }
    if (total_happ < happ ||
      (total_happ == happ && passed < total_passed)) {
      total_happ = happ;
      total_passed = passed;
      path = temppath;
    }
    temppath.pop_back();
    total_paths++;
    return;
  }
  for (auto item : p[d]) {
    dfs(item);
  }
  temppath.pop_back();
}



int main() {
  /*freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);*/
  
  graph.resize(capacity);

  int n, k, happy, cost;
  scanf("%d%d", &n, &k);
  char city1[4], city2[4];
  scanf("%s", start);
  s = str_to_int(start);
  for (int i = 1; i < n; i++) {
    scanf("%s %d", city1, &happy);
    happiness[str_to_int(city1)] = happy;
  }
  int c1 = 0, c2 = 0;
  for (int i = 0; i < k; i++) {
    scanf("%s %s %d", city1, city2, &cost);
    c1 = str_to_int(city1);
    c2 = str_to_int(city2);
    graph[c1].push_back(Node(c2, cost));
    graph[c2].push_back(Node(c1, cost));
  }
  
  p.resize(capacity);
  priority_queue<Node> q;
  dist[s] = 0;
  q.push(Node(s, 0));

  while (!q.empty()) {
    auto t = q.top(); q.pop();
    if (visited[t.u]) continue;
    visited[t.u] = true;

    for (auto item : graph[t.u]) {
      if (dist[t.u] + item.cost < dist[item.u]) {
        dist[item.u] = dist[t.u] + item.cost;
        p[item.u].clear();
        p[item.u].push_back(t.u);
        q.push(Node(item.u, dist[item.u]));
      }
      else if (dist[t.u] + item.cost == dist[item.u])
        p[item.u].push_back(t.u);
    }
  }

  dfs(dest);
  printf("%d %d %d %d\n", total_paths, dist[dest], total_happ, total_happ / total_passed);
  for (auto it = path.rbegin(); it != path.rend(); it++) {
    if (it != path.rbegin())
      printf("->");
    printf("%c%c%c", 'A' + *it / 26 / 26, 'A' + *it / 26 % 26, 'A' + *it % 26);
  }
  return 0;
}