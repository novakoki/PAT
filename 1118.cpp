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

vector<int> p(10001, 0);

int find(int x) {
  int t = x;
  while (p[t] != t)
    t = p[t];
  p[x] = t;
  return t;
}

int main() {
  /*freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);*/

  for (int i = 0; i < 10001; i++)
    p[i] = i;

  int n, k, b, trees = 0;
  unordered_set<int> s, t;
  scanf("%d", &n);
  while (n--) {
    scanf("%d %d", &k, &b);
    s.insert(b);
    int root = find(b);
    for (int i = 1; i < k; i++) {
      scanf("%d", &b);
      s.insert(b);
      p[find(b)] = root;
    }
  }

  for (auto item : s)
    t.insert(find(item));

  printf("%d %d\n", t.size(), s.size());

  scanf("%d", &n);
  while (n--) {
    scanf("%d %d", &k, &b);
    if (find(k) == find(b))
      printf("Yes\n");
    else
      printf("No\n");
  }
  return 0;
}