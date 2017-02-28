#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <algorithm>
using namespace std;

struct Node {
  int val;
  Node *left, *right;

  Node(int n):val(n), left(NULL), right(NULL){}

  Node(int n, Node* left, Node* right):val(n), left(left), right(right){}
};

Node* connect34(
  Node* t1, Node* a, Node* t2,
  Node* b,
  Node* t3, Node* c, Node* t4){
    a->left = t1; a->right = t2;
    c->left = t3; c->right = t4;
    b->left = a; b->right = c;
    return b;
}

int getHeight(Node* root) {
  return root == NULL ? 0 : max(getHeight(root->left), getHeight(root->right))+1;
}

Node* insert(Node* root, int val) {
  if (root == NULL) {
    root = new Node(val);
  }
  else if (val < root->val) {
    root->left = insert(root->left, val);
    if (getHeight(root->left) - getHeight(root->right) == 2) {
      if (val < root->left->val)
        root = connect34(root->left->left->left, root->left->left, root->left->left->right,
          root->left,
          root->left->right, root, root->right);
      else
        root = connect34(root->left->left, root->left, root->left->right->left,
          root->left->right,
          root->left->right->right, root, root->right);
    }
  } else if (val > root->val) {
    root->right = insert(root->right, val);
    if (getHeight(root->left) - getHeight(root->right) == -2) {
      if (val > root->right->val)
        root = connect34(root->left, root, root->right->left,
          root->right,
          root->right->right->left, root->right->right, root->right->right->right);
      else
        root = connect34(root->left, root, root->right->left->left,
          root->right->left,
          root->right->left->right, root->right, root->right->right);
    }
  }
  return root;
}

void find_max(Node* root, int start, int& index) {
  if (root->left != NULL) {
    index = max(2*start, index);
    find_max(root->left, 2*start, index);
  }
  if (root->right != NULL) {
    index = max(2*start+1, index);
    find_max(root->right, 2*start+1, index);
  }
}

int main () {
#ifdef _DEBUG
  freopen("input.txt", "r", stdin);
#endif
  int n, val;
  while (scanf("%d", &n) != EOF) {
    Node* root = NULL;
    for (int i = 0; i < n; i++) {
      scanf("%d", &val);
      root = insert(root, val);
    }
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
      Node* t = q.front(); q.pop();
      if (t != root)
        printf(" ");
      printf("%d", t->val);
      if (t->left != NULL) {
        q.push(t->left);      
      }
      if (t->right != NULL) {
        q.push(t->right);
      }
    }
    printf("\n");
    int index = 1;
    find_max(root, 1, index);
    if (index == n)
      printf("YES\n");
    else
      printf("NO\n");
  }
  return 0;
}