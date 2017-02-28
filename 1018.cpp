#include <iostream>
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

int perfect, minSend = INT_MAX, minBack = INT_MAX;

struct Edge {
  int from, to, time;

  Edge(int f, int t, int ti):from(f), to(t), time(ti) {}
  Edge(){}
};

struct Node {
  int u, time;
  Node(int u, int t):u(u), time(t) {}
  Node() {}

  bool operator< (const Node& rhs) const {
    return time > rhs.time;
  }
};

vector<vector<Edge> > graph;
vector<vector<int> > path;
vector<int> dist;
vector<int> collect;
vector<bool> visited;
vector<int> temppath;
vector<int> respath;

void dijkstra(int s) {
  fill(dist.begin(), dist.end(), INT_MAX);
  fill(visited.begin(), visited.end(), false);
  priority_queue<Node> q;
  dist[s] = 0;
  q.push(Node(s, 0));

  while (!q.empty()) {
    Node node = q.top(); q.pop();
    if (visited[node.u]) continue;
    visited[node.u] = true;
    for (auto e = graph[node.u].begin(); e != graph[node.u].end(); e++) {
      if (dist[e->to] > dist[node.u] + e->time) {
        dist[e->to] = dist[node.u] + e->time;
        path[e->to].clear();
        path[e->to].push_back(node.u);
        q.push(Node(e->to, dist[e->to]));
      }
      else if (dist[e->to] == dist[node.u] + e->time) {
        path[e->to].push_back(node.u);
      }
    }
  }
}

void dfs(int d) {
  if (d == 0) {
    //temppath.push_back(d);
    int send = 0, back = 0;
    for (auto it = temppath.rbegin(); it != temppath.rend(); it++) {
      if (collect[*it] > perfect) {
        back += collect[*it] - perfect;
      }
      else if (collect[*it] < perfect) {
        if (back + collect[*it] < perfect) {
          send += perfect - collect[*it] - back;
          back = 0;
        }
        else {
          back -= perfect - collect[*it];
        }
      }
    }
    if ((send < minSend) ||
      (send == minSend && back < minBack)) {
      minSend = send;
      minBack = back;
      respath = temppath;
    }
    //temppath.pop_back();
    return;
  }
  temppath.push_back(d);
  for (auto it = path[d].begin(); it != path[d].end(); it++)
    dfs(*it);
  temppath.pop_back();
}

int main() {
  int cmax, n, sp, m;
  int from, to, time;
  cin >> cmax >> n >> sp >> m;
  
  perfect = cmax / 2;
  graph.resize(n + 1);
  path.resize(n + 1);
  dist.resize(n + 1);
  collect.resize(n + 1);
  visited.resize(n + 1);
    
  for (int i = 1; i <= n; i++)
    cin >> collect[i];
  while (m--) {
    cin >> from >> to >> time;
    graph[from].push_back(Edge(from, to, time));
    graph[to].push_back(Edge(to, from, time));
  }
  dijkstra(0);
  dfs(sp);
  cout << minSend << " 0";
  for (auto it = respath.rbegin(); it != respath.rend(); it++) {
    cout << "->" << *it;
  }
  cout << " " << minBack << endl;
  return 0;
}