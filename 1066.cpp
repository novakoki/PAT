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
  Node *left, *right;

  Node(int val, Node* left = NULL, Node* right = NULL)
    : val(val), left(left), right(right) {}
};

int getHeight(Node* root) {
  return root == NULL ? 0
    : max(getHeight(root->left),
      getHeight(root->right)) + 1;
}

Node* rotateLeft(Node* root) {
  Node *g = root, *p = root->right;
  g->right = p->left;
  p->left = g;
  return p;
}

Node* rotateRight(Node* root) {
  Node *g = root, *p = root->left;
  g->left = p->right;
  p->right = g;
  return p;
}

Node* rotateLeftRight(Node* root) {
  root->left = rotateLeft(root->left);
  return rotateRight(root);
}

Node* rotateRightLeft(Node* root) {
  root->right = rotateRight(root->right);
  return rotateLeft(root);
}

Node* connect34(
  Node* t1, Node* a, Node* t2,
  Node* b,
  Node* t3, Node* c, Node* t4) {
  a->left = t1; a->right = t2;
  c->left = t3; c->right = t4;
  b->left = a; b->right = c;
  return b;
}

Node* insert(Node* root, int val) {
  if (root == NULL) {
    root = new Node(val);
  }
  else if (val < root->val) {
    root->left = insert(root->left, val);
    if (getHeight(root->left) - getHeight(root->right) > 1)
      root = val < root->left->val ? 
        connect34(
          root->left->left->left, root->left->left, root->left->left->right,
          root->left,
          root->left->right, root, root->right) : 
        connect34(
          root->left->left, root->left, root->left->right->left,
          root->left->right,
          root->left->right->right, root, root->right);
  }
  else if (val > root->val) {
    root->right = insert(root->right, val);
    if (getHeight(root->right) - getHeight(root->left) > 1)
      root = val > root->right->val ?
        connect34(root->left, root, root->right->left,
          root->right,
          root->right->right->left, root->right->right, root->right->right->right) :
        connect34(root->left, root, root->right->left->left,
          root->right->left,
          root->right->left->right, root->right, root->right->right);
  }

  return root;
}

int main() {
  /*freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);*/
  int n, val;
  Node* root = NULL;
  scanf("%d", &n);
  while (n--) {
    scanf("%d", &val);
    root = insert(root, val);
  }
  printf("%d\n", root->val);
  return 0;
}