#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <iomanip>
#include <map>
#include <string>
#include <cstdio>
using namespace std;

int bfs(int s, vector<bool>& visit, vector<int>& d, const vector<vector<int> >& v) {
  if (v[s].empty()) {
    visit[s] = true;
    return 0;
  }
  queue<int> q;
  q.push(s);
  int longest = 0;
  while (!q.empty()) {
    int n = q.front(); q.pop();
    if (visit[n]) continue;
    visit[n] = true;
    for (auto it = v[n].begin(); it != v[n].end(); it++) {
      if (visit[*it]) continue;
      d[*it] = d[n] + 1;
      longest = max(d[*it], longest);
      q.push(*it);
    }
  }
  return longest;
}

int main() {
  int n;
  int a, b;
  while (cin >> n) {
    vector<int> e;
    vector<vector<int> > v(n+1, e);
    for (int i = 0; i < n-1; i++) {
      cin >> a >> b;
      v[a].push_back(b);
      v[b].push_back(a);
    }
    int highest = 0;
    vector<int> res;
    vector<bool> visit(n + 1, false);
    vector<int> d(n + 1, 0);
    for (int i = 1; i < n+1; i++) {
      fill(visit.begin(), visit.end(), false);
      fill(d.begin(), d.end(), 0);
      int l = bfs(i, visit, d, v);
      int com_sum = 1;
      for (int i = 1; i < visit.size(); i++) {
        if (!visit[i]) {
          bfs(i, visit, d, v);
          com_sum++;
        }
      }
      if (com_sum > 1) {
        cout << "Error: " << com_sum << " components" << endl;
        break;
      }
      if (l > highest) {
        highest = l;
        res.clear();
        res.push_back(i);
      }
      else if (l == highest) {
        res.push_back(i);
      }
    }
    for (auto it = res.begin(); it != res.end(); it++)
      cout << *it << endl;
  }
  return 0;
}