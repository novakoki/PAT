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

void inorder(int root, const vector<int>& lch, const vector<int>& rch, vector<int>& in, const vector<int>& data, int& index) {
  if (root == -1)
    return;
  inorder(lch[root], lch, rch, in, data, index);
  in[root] = data[index++];
  inorder(rch[root], lch, rch, in, data, index);
}

int main() {
#ifdef _DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int n;
  scanf("%d", &n);
  vector<int> lch(n, -1), rch(n, -1);

  for (int i = 0; i < n; i++)
    scanf("%d %d", &lch[i], &rch[i]);

  vector<int> data(n, 0), in(n, 0);
  for (int i = 0; i < n; i++)
    scanf("%d", &data[i]);
  sort(data.begin(), data.end());
  int index = 0;
  inorder(0, lch, rch, in, data, index);

  queue<int> q;
  q.push(0);
  while (!q.empty()) {
    int t = q.front(); q.pop();
    if (t != 0)
      printf(" ");
    printf("%d", in[t]);
    if (lch[t] != -1)
      q.push(lch[t]);
    if (rch[t] != -1)
      q.push(rch[t]);
  }
  return 0;
}