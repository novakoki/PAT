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
  int n, m, root, k, id;
  scanf("%d %d", &n, &m);
  vector<vector<int> > graph;
  graph.resize(n+1);
  while (m--) {
    scanf("%d %d", &root, &k);
    while (k--) {
      scanf("%d", &id);
      graph[root].push_back(id);
    }
  }
  vector<int> d(n+1, INT_MAX), cnt(n+1, 0);
  d[1] = 1;
  cnt[1] = 1;
  queue<int> q;
  q.push(1);
  int res_cnt = 1, res_level = 1;
  while (!q.empty()) {
    auto t = q.front(); q.pop();
    for (auto chd : graph[t]) {
      d[chd] = d[t] + 1;
      cnt[d[chd]]++;
      if (cnt[d[chd]] > res_cnt) {
        res_cnt = cnt[d[chd]];
        res_level = d[chd];
      }
      q.push(chd);
    }
  }
  printf("%d %d\n", res_cnt, res_level);
  return 0;
}