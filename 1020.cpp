#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <iomanip>
#include <map>
#include <string>
#include <cstdio>
using namespace std;

int post[31];
int in[31];
int lch[31];
int rch[31];

int build(int inlow, int inhigh, int postlow, int posthigh) {
  //cout << inlow << ' ' << inhigh << ' ' << postlow << ' ' << posthigh << endl;
  if (inlow > inhigh) return 0;
  int root = post[posthigh];
  int rootIn = 0;
  while (in[rootIn] != root) rootIn++;
  int dividePost = postlow + rootIn - inlow;
  lch[root] = build(inlow, rootIn - 1, postlow, dividePost - 1);
  rch[root] = build(rootIn + 1, inhigh, dividePost, posthigh - 1);
  return root;
}

void printLevel(int root) {
  queue<int> q;
  vector<int> v;
  q.push(root);

  while (!q.empty()) {
    int n = q.front(); q.pop();
    v.push_back(n);
    if (lch[n] != 0) q.push(lch[n]);
    if (rch[n] != 0) q.push(rch[n]);
  }

  for (auto it = v.begin(); it != v.end(); it++) {
    if (it == v.begin()) cout << *it;
    else cout << ' ' << *it;
  }
  cout << endl;
}

int main() {
  int n;
  while (cin >> n) {
    for (int i = 0; i < n; i++) cin >> post[i];
    for (int i = 0; i < n; i++) cin >> in[i];
    int root = build(0, n-1, 0, n-1);
    /*for (int i = 0; i < n; i++) cout << lch[i] << ' ';
    cout << endl;
    for (int i = 0; i < n; i++) cout << rch[i] << ' ';
    cout << endl;*/
    printLevel(root);
  }
  return 0;
}