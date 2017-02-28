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

vector<int> pre, in, post;
bool uniq = true;

void inorder(int prel, int preh, int postl, int posth) {
  // printf("%d %d %d %d\n", prel, preh, postl, posth);
  if (prel == preh) {
    in.push_back(pre[prel]);
    return;
  }
  int root = pre[prel];
  int i = prel + 1, j = postl;
  while (j <= posth && pre[i] != post[j]) {
    j++;
  }
  inorder(i, i + j - postl, postl, j);
  in.push_back(root);
  if (j + 1 == posth)
    uniq = false;
  else
    inorder(i + j - postl + 1, preh, j + 1, posth - 1);
}

int main() {
  /*freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);*/

  int n;
  scanf("%d", &n);
  pre.resize(n); post.resize(n);

  for (int i = 0; i < n; i++)
    scanf("%d", &pre[i]);
  for (int i = 0; i < n; i++)
    scanf("%d", &post[i]);
  inorder(0, n-1, 0, n-1);
  
  if (uniq)
    printf("Yes\n");
  else
    printf("No\n");

  for (int i = 0; i < in.size(); i++) {
    if (i != 0)
      printf(" ");
    printf("%d", in[i]);
  }
  printf("\n");

  return 0;
}