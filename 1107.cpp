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

vector<int> uf;

int find(int n) {
  int root = uf[n];
  while (root != uf[root]) {
    root = uf[root];
  }
  uf[n] = root;
  return root;
}

int main() {
#ifdef _DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int n, k, hj;
  vector<int> hobby(1001, -1);
  scanf("%d", &n);
  uf.resize(n + 1);
  for (int i = 1; i <= n; i++)
    uf[i] = i;
  for (int i = 1; i <= n; i++) {
    scanf("%d: ", &k);
    while (k--) {
      scanf("%d", &hj);
      if (hobby[hj] == -1)
        hobby[hj] = i;
      else {
        uf[find(i)] = hobby[hj];
      }
    }
  }
  unordered_map<int, int> m;
  int root = 0;
  for (int i = 1; i <= n; i++) {
    root = find(i);
    if (m.find(root) != m.end())
      m[root]++;
    else
      m[root] = 1;
  }
  printf("%d\n", m.size());
  vector<int> res(m.size(), 0);
  int cnt = 0;
  for (auto item : m) {
    res[cnt++] = item.second;
  }
  sort(res.rbegin(), res.rend());
  for (int i = 0; i < res.size(); i++) {
    if (i != 0)
      printf(" ");
    printf("%d", res[i]);
  }
  printf("\n");
  return 0;
}