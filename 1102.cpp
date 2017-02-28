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
using namespace std;

bool flag = false;

void inorder(int root, const vector<int>& lch, const vector<int>& rch) {
  if (root == -1)
    return;
  inorder(rch[root], lch, rch);
  if (flag)
    printf(" ");
  printf("%d", root);
  flag = true;
  inorder(lch[root], lch, rch);
}

int main() {
#ifdef _DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int n;
  scanf("%d\n", &n);
  vector<int> lch(n, -1), rch(n, -1), parent(n, -1);
  char l, r;
  for (int i = 0; i < n; i++) {
    scanf("%c %c\n", &l, &r);
    if (l != '-') {
      lch[i] = l - '0';
      parent[l - '0'] = i;
    }
    if (r != '-') {
      rch[i] = r - '0';
      parent[r - '0'] = i;
    }
  }
  int root = 0;
  for (int i = 0; i < n; i++) {
    if (parent[i] == -1) {
      root = i;
      break;
    }
  }
  queue<int> q;
  q.push(root);
  while (!q.empty()) {
    int t = q.front(); q.pop();
    if (t != root)
      printf(" ");
    printf("%d", t);
    if (rch[t] != -1)
      q.push(rch[t]);
    if (lch[t] != -1)
      q.push(lch[t]);
  }
  printf("\n");
  inorder(root, lch, rch);
  return 0;
}