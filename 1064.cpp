#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn = 1002;
int tree[maxn];
int nodes[maxn];
int n, pos;

void inorder(int root) {
  if (root > n) return;
  inorder(2 * root);
  tree[root] = nodes[pos++];
  inorder(2 * root + 1);
}

int main() {
  while (cin >> n) {
    for (int i = 0; i < n; i++)
      cin >> nodes[i];
    sort(nodes, nodes + n);
    inorder(1);
    cout << tree[1];
    for (int i = 2; i <= n; i++)
      cout << ' ' << tree[i];
  }
  return 0;
}