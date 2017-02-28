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

struct Node {
  int val;
  Node *left = NULL, *right = NULL, *parent = NULL;
};

bool first = true;

void postorder(Node* root) {
  if (root == NULL) return;
  postorder(root->left);
  postorder(root->right);
  if (first) {
    printf("%d", root->val);
    first = false;
  }
  else
    printf(" %d", root->val);
}

int main() {
  /*freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);*/
  int n, val;
  cin >> n;
  string operation;
  Node* root = new Node();
  root->parent = root;
  cin >> operation >> val;
  root->val = val;
  Node* p = root;
  vector<bool> visited(n+1, false);
  for (int i = 1; i < 2 * n; i++) {
    cin >> operation;
    if (operation == "Push") {
      cin >> val;
      if (p->left == NULL) {
        p->left = new Node();
        p->left->val = val;
        p->left->parent = p;
        p = p->left;
      }
      else {
        p->right = new Node();
        p->right->val = val;
        p->right->parent = p;
        p = p->right;
      }
    }
    else if (operation == "Pop") {
      while (visited[p->val])
        p = p->parent;
      visited[p->val] = true;
    }
  }
  postorder(root);
  return 0;
}