#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <functional>
using namespace std;

typedef pair<int, int> pii;

int main() {
  const int inf = 999999;
  const int maxn = 501;
  int N, M, C1, C2;
  int c1, c2, w;
  priority_queue<pii, vector<pii>, greater<pii> > q;
  while (cin >> N >> M >> C1 >> C2) {
    int same[maxn];
    int sum[maxn];
    int hands[maxn];
    vector<pii> graph[maxn];
    int d[maxn];
    //vector<int> p[maxn];
    bool done[maxn];
    for (int i = 0; i < N; i++)
      cin >> hands[i];
    for (int i = 0; i < M; i++) {
      cin >> c1 >> c2 >> w;
      graph[c1].push_back(make_pair(w, c2));
      graph[c2].push_back(make_pair(w, c1));
    }
    memset(done, false, sizeof(done));
    memset(d, inf, sizeof(d));
    memset(same, 0, sizeof(same));
    memset(sum, 0, sizeof(sum));
    d[C1] = 0;
    same[C1] = 1;
    sum[C1] = hands[C1];
    q.push(make_pair(0, C1));
    while (!q.empty()) {
      pii x = q.top();
      q.pop();
      int u = x.second;
      if (done[u]) continue;
      done[u] = true;
      for (int i = 0; i < graph[u].size(); i++) {
        pii e = graph[u][i];
        if (d[e.second] > d[u] + e.first) {
          d[e.second] = d[u] + e.first;
          same[e.second] = same[u];
          sum[e.second] = sum[u] + hands[e.second];
          q.push(make_pair(d[e.second], e.second));
        }
        else if (d[e.second] == d[u] + e.first) {
          same[e.second] += same[u];
          sum[e.second] = max(sum[e.second], sum[u] + hands[e.second]);
          q.push(make_pair(d[e.second], e.second));
        }
      }
    }
    cout << same[C2] << ' ' << sum[C2] << endl;
  }
  return 0;
}