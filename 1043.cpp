#include <iostream>
#include <sstream>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>
#include <iomanip>
#include <map>
#include <unordered_map>
#include <string>
#include <cstdio>
#include <cstring>
#include <climits>
#include <set>
using namespace std;

vector<int> v, res;
bool mirror = false;

void getpost(int root, int tail) {
  if (root > tail) return;
  int i = root+1, j = tail;
  if (!mirror) {
    while (i <= tail && v[i] < v[root]) i++;
    while (j > root && v[j] >= v[root]) j--;
  }
  else {
    while (i <= tail && v[i] >= v[root]) i++;
    while (j > root && v[j] < v[root]) j--;
  }
  if (i - j != 1) return;
  getpost(root+1, j);
  getpost(i, tail);
  res.push_back(v[root]);
}

int main() {
  int n;
  cin >> n;
  v.resize(n);
  for (int i = 0; i < n; i++) cin >> v[i];
  getpost(0, n - 1);
  if (res.size() != v.size()) {
    res.clear();
    mirror = true;
    getpost(0, n - 1);
  }
  if (res.size() == v.size()) {
    cout << "YES" << endl;
    for (auto it = res.begin(); it != res.end(); it++) {
      if (it == res.begin()) cout << *it;
      else cout << ' ' << *it;
    }
  }
  else cout << "NO" << endl;
  return 0;
}