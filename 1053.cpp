include <iostream>
#include <sstream>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>
#include <iomanip>
#include <map>
#include <unordered_map>
#include <string>
#include <set>
#include <stack>
#include <cstdio>
#include <cstring>
#include <climits>
using namespace std;

//bool operator<(const list<int>& a, const list<int>& b) {
//  int k = min(a.size(), b.size());
//  auto it0 = a.begin(), it1 = b.begin();
//  int count = 0;
//  for (; count < k; it0++, it1++, count++) {
//    if (*it0 != *it1) {
//      printf("%d %d ", *it0, *it1);
//      return *it0 > *it1;
//    }
//  }
//  return true;
//}

int main() {
  int N, M, S;
  scanf("%d %d %d", &N, &M, &S);
  vector<vector<int> > graph;
  vector<int> weight;
  vector<int> leaves;
  graph.resize(N);
  weight.resize(N);
  for (int i = 0; i < N; i++) {
    scanf("%d", &weight[i]);
  }
  int root, K, ch;
  for (int i = 0; i < M; i++) {
    scanf("%d %d", &root, &K);
    while (K--) {
      scanf("%d", &ch);
      graph[root].push_back(ch);
    }
  }
  vector<int> d(N, 0), p(N, 0);
  queue<int> q;
  q.push(0);
  d[0] = weight[0];
  while (!q.empty()) {
    int root = q.front(); q.pop();
    for (auto child : graph[root]) {
      d[child] = d[root] + weight[child];
      if (d[child] > S) continue;
      p[child] = root;
      q.push(child);
    }
    if (graph[root].empty()) leaves.push_back(root);
  }
  vector<list<int> > res;
  for (auto leaf : leaves) {
    if (d[leaf] == S) {
      list<int> s;
      int i = leaf;
      while (p[i] != i) {
        s.push_front(weight[i]);
        i = p[i];
      }
      s.push_front(weight[0]);
      res.push_back(s);
    }
  }
  sort(res.rbegin(), res.rend());
  for (auto item : res) {
    for (auto it = item.begin(); it != item.end(); it++) {
      if (it != item.begin()) printf(" ");
      printf("%d", *it);
    }
    printf("\n");
  }
  return 0;
}