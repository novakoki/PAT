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
using namespace std;

int main() {
  int n, m;
  while (cin >> n >> m) {
    vector<vector<int> > v;
    v.resize(n+1);
    vector<int> leaf;
    vector<int> d(n+1, 0);
    int r, k;
    while (m--) {
      cin >> r >> k;
      v[r].resize(k);
      for (int i = 0; i < k; i++)
        cin >> v[r][i];
    }
    queue<int> q;
    q.push(1);
    while (!q.empty()) {
      int node = q.front(); q.pop();
      if (leaf.size() < d[node] + 1)
        leaf.push_back(0);
      if (v[node].empty()) leaf[d[node]]++;
      else {
        for (auto it = v[node].begin(); it != v[node].end(); it++) {
          d[*it] = d[node] + 1;
          q.push(*it);
        }
      }
    }
    for (auto it = leaf.begin(); it != leaf.end(); it++) {
      if (it == leaf.begin()) {
        cout << *it;
      }
      else {
        cout << ' ' << *it;
      }
    }
    cout << endl;
  }
  return 0;
}