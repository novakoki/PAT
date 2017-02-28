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

int main() {
  /*freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);*/
  int n;
  scanf("%d\n", &n);
  vector<string> v;
  v.resize(n);
  int length = INT_MAX;
  for (int i = 0; i < n; i++) {
    getline(cin, v[i]);
    reverse(v[i].begin(), v[i].end());
    length = min(length, (int)v[i].length());
  }
  stack<char> s;
  for (int i = 0; i < length; i++) {
    bool equal = true;
    char c = v[0][i];
    for (int j = 1; j < n; j++) {
      if (v[j][i] != c) {
        equal = false;
        break;
      }
    }
    if (equal)
      s.push(c);
    else break;
  }
  if (s.empty())
    cout << "nai";
  else {
    while (!s.empty()) {
      cout << s.top();
      s.pop();
    }
  }
  return 0;
}