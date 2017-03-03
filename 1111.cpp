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

struct Node {
  int u, length, time;
  Node(int u, int l, int t):u(u), length(l), time(t) {}
  Node() {}
};

vector<vector<Node> > graph;

struct less_dist {
  bool operator() (const Node& a, const Node& b) {
    if (a.length == b.length)
      return a.time > b.time;
    return a.length > b.length;
  }
};

void dfs_short(int s, int d, const vector<int>& path, list<int>& res) {
  if (d == s) return;
  res.push_front(d);
  dfs_short(s, path[d], path, res);
}

void dj_short(int s, int d, int n, int& res, list<int>& res_list) {
  vector<bool> visited(n, false);
  vector<int> dist(n, INT_MAX), time(n, INT_MAX), path(n, 0);
  priority_queue<Node, vector<Node>, less_dist> q;
  q.push(Node(s, 0, 0));
  dist[s] = 0;
  time[s] = 0;

  while (!q.empty()) {
    auto cur = q.top(); q.pop();
    if (visited[cur.u]) continue;
    visited[cur.u] = true;

    for (auto to : graph[cur.u]) {
      if (dist[to.u] > dist[cur.u] + to.length ||
        (dist[to.u] == dist[cur.u] + to.length && time[to.u] > time[cur.u] + to.time)) {
        dist[to.u] = dist[cur.u] + to.length;
        time[to.u] = time[cur.u] + to.time;
        path[to.u] = cur.u;
        q.push(Node(to.u, dist[to.u], time[to.u]));
      }
    }
  }

  res = dist[d];
  dfs_short(s, d, path, res_list);
}

struct less_time {
  bool operator() (const Node& a, const Node& b) {
    return a.time > b.time;
  }
};

void dfs_fast(int s, int d, const vector<vector<int> >& path, list<int>& res, list<int>& tmp) {
  if (d == s) {
    if (res.empty() || tmp.size() < res.size()) {
      res = tmp;
    }
    return;
  }
  tmp.push_front(d);
  for (auto from : path[d])
    dfs_fast(s, from, path, res, tmp);
  tmp.pop_front();
}

void dj_fast(int s, int d, int n, int& res,
  list<int>& res_list) {
  vector<bool> visited(n, false);
  vector<int> time(n, INT_MAX);
  vector<vector<int> > path;
  path.resize(n);
  priority_queue<Node, vector<Node>, less_time> q;
  q.push(Node(s, 0, 0));
  time[s] = 0;

  while (!q.empty()) {
    auto cur = q.top(); q.pop();
    if (visited[cur.u]) continue;
    visited[cur.u] = true;

    for (auto to : graph[cur.u]) {
      if (time[to.u] > time[cur.u] + to.time) {
        time[to.u] = time[cur.u] + to.time;
        path[to.u].clear();
        path[to.u].push_back(cur.u);
        q.push(Node(to.u, 0, time[to.u]));
      }
      else if (time[to.u] == time[cur.u] + to.time) {
        path[to.u].push_back(cur.u);
        q.push(Node(to.u, 0, time[to.u]));
      }
    }
  }

  res = time[d];
  list<int> tmp_list;
  dfs_fast(s, d, path, res_list, tmp_list);
}

bool equal(const list<int>& a, const list<int>& b) {
  if (a.size() != b.size())
    return false;
  auto i = a.begin(), j = b.begin();
  while (i != a.end()) {
    if (*i != *j)
      return false;
    i++; j++;
  }
  return true;
}

void print(const int s, const list<int>& path) {
  printf("%d", s);
  for (auto item : path)
    printf(" -> %d", item);
  printf("\n");
}

int main() {
#ifdef _DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int n, m, v1, v2, one_way, length, time, source, dest;
  scanf("%d %d", &n, &m);
  graph.resize(n);
  while (m--) {
    scanf("%d %d %d %d %d", &v1, &v2, &one_way, &length, &time);
    graph[v1].push_back(Node(v2, length, time));
    if (one_way == 0)
      graph[v2].push_back(Node(v1, length, time));
  }
  scanf("%d %d", &source, &dest);
  list<int> dist_path, time_path;
  int res_dist = 0, res_time = 0;
  dj_short(source, dest, n, res_dist, dist_path);
  dj_fast(source, dest, n, res_time, time_path);
  if (equal(dist_path, time_path)) {
    printf("Distance = %d; Time = %d: ", res_dist, res_time);
    print(source, dist_path);
  }
  else {
    printf("Distance = %d: ", res_dist);
    print(source, dist_path);
    printf("Time = %d: ", res_time);
    print(source, time_path);
  }
  return 0;
}