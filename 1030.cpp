#include <iostream>
#include <sstream>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>
#include <iomanip>
#include <map>
#include <string>
#include <cstdio>
#include <cstring>
#include <climits>
using namespace std;

struct Node {
  int u, dist, cost;

  bool operator< (const Node& rhs) const {
    if (dist != rhs.dist) return dist > rhs.dist;
    else return cost > rhs.cost;
  }

  Node() {}
  Node(int u, int d, int c):u(u), dist(d), cost(c) {}
};

void print(int s, int d, const vector<int>& path) {
  if (d == s) {
    cout << s;
    return;
  }
  print(s, path[d], path);
  cout << ' ' << d;
}

int main() {
  int N, M, S, D;
  cin >> N >> M >> S >> D;
  vector<vector<Node> > graph;
  vector<int> path;
  vector<int> dist(N, INT_MAX);
  vector<int> cost(N, INT_MAX);
  vector<bool> visit(N, false);
  graph.resize(N);
  path.resize(N);
  int from, to, d, c;
  for (int i = 0; i < M; i++) {
    cin >> from >> to >> d >> c;
    graph[from].push_back(Node(to, d, c));
    graph[to].push_back(Node(from, d, c));
  }
  priority_queue<Node> q;
  q.push(Node(S, 0, 0));
  dist[S] = 0;
  cost[S] = 0;
  while (!q.empty()) {
    Node node = q.top(); q.pop();
    if (visit[node.u]) continue;
    visit[node.u] = true;
    for (auto it = graph[node.u].begin(); it != graph[node.u].end(); it++) {
      if ((dist[it->u] > dist[node.u] + it->dist) ||
        ((dist[it->u] == dist[node.u] + it->dist) && (cost[it->u] > cost[node.u] + it->cost))) {
        dist[it->u] = dist[node.u] + it->dist;
        cost[it->u] = cost[node.u] + it->cost;
        path[it->u] = node.u;
        q.push(Node(it->u, dist[it->u], cost[it->u]));
      }
    }
  }
  print(S, D, path);
  cout << ' ' << dist[D] << ' ' << cost[D] << endl;
  return 0;
}