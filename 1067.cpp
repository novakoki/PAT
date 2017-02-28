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
  int n;
  cin >> n;
  vector<int> v(n, 0);
  vector<int> m(n, 0);
  int res = 0, index = 0;
  for (int i = 0; i < n; i++) {
    cin >> v[i];
    m[v[i]] = i;
  }
  while (true) {
    if (m[0] != 0) {
      swap(v[m[0]], v[m[m[0]]]);
      swap(m[0], m[m[0]]);
      res++;
    }
    else {
      bool finish = true;
      for (int i = index; i < v.size(); i++) {
        if (v[i] != i) {
          swap(m[0], m[v[i]]);
          swap(v[i], v[0]);
          res++;
          finish = false;
          index = i;
          break;
        }
      }
      if (finish) break;
    }
  }
  cout << res;
  return 0;
}