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

int main() {
#ifdef _DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int n;
  scanf("%d\n", &n);
  vector<int> lch(n, -1), rch(n, -1), parent(n, -1);
  string l, r;
  for (int i = 0; i < n; i++) {
    cin >> l >> r;
    if (l[0] != '-') {
      lch[i] = stoi(l);
      parent[stoi(l)] = i;
    }
    if (r[0] != '-') {
      rch[i] = stoi(r);
      parent[stoi(r)] = i;
    }
  }
  int root = 0;
  for (int i = 0; i < n; i++) {
    if (parent[i] == -1) {
      root = i;
      break;
    }
  }
  int index = 0, last = root;
  
  queue<int> q;
  q.push(root);
  while (!q.empty()) {
    int t = q.front(); q.pop();
    if (t == -1) {
      break;
    }
    last = t;
    index++;
    q.push(lch[t]);
    q.push(rch[t]);
  }

  if (index == n)
    printf("YES %d\n", last);
  else
    printf("NO %d\n", root);
  return 0;
}