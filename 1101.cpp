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
  vector<int> v(n, 0);
  priority_queue<int> q;
  priority_queue<int, vector<int>, greater<int> > p;
  for (int i = 0; i < n; i++) {
    scanf("%d", &v[i]);
    p.push(v[i]);
  }
  vector<int> res;
  for (int i = 0; i < n; i++) {
    if (v[i] == p.top()) {
      if (q.empty() || v[i] > q.top()) {
        res.push_back(v[i]);
      }
    }
    p.pop(); q.push(v[i]);
  }
  
  printf("%d\n", res.size());
  for (int i = 0; i < res.size(); i++) {
    if (i != 0)
      printf(" ");
    printf("%d", res[i]);
  }
  printf("\n");
  return 0;
}