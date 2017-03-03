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

struct Node {
  int val, depth;
  Node *left, *right;
  Node(int val, int depth, Node* left = NULL, Node* right = NULL)
    :val(val), depth(depth), left(left), right(right) {}
};

vector<Node*> tree;
int deepest = 0;

Node* insert(Node* root, int val, int depth) {
  if (root == NULL) {
    root = new Node(val, depth);
    deepest = max(depth, deepest);
    tree.push_back(root);
  }
  else if (val <= root->val)
    root->left = insert(root->left, val, depth+1);
  else if (val > root->val)
    root->right = insert(root->right, val, depth+1);
  return root;
}

int main() {
#ifdef _DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int n, val; 
  scanf("%d", &n);
  Node* root = NULL;

  while (n--) {
    scanf("%d", &val);
    root = insert(root, val, 1);
  }
  int n1 = 0, n2 = 0;
  for (auto node : tree) {
    if (node->depth == deepest)
      n1++;
    if (node->depth == deepest - 1)
      n2++;
  }
  printf("%d + %d = %d\n", n1, n2, n1 + n2);
  return 0;
}