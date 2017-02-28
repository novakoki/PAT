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

int main() {
  int k;
  cin >> k;
  int n = 54;
  vector<int> v(55, 0);
  vector<int> res(55, 0);
  for (int i = 1; i <= 54; i++) {
    res[i] = i;
    cin >> v[i];
  }
  while (k--) {
    vector<int> tmp(res);
    for (int i = 1; i <= 54; i++) res[v[i]] = tmp[i];
  }
  for (int i = 1; i <= 54; i++) {
    if (i != 1)
      cout << ' ';
    if (res[i] >= 1 && res[i] <= 13) cout << 'S' << res[i];
    else if (res[i] <= 26) cout << 'H' << res[i] - 13;
    else if (res[i] <= 39) cout << 'C' << res[i] - 26;
    else if (res[i] <= 52) cout << 'D' << res[i] - 39;
    else cout << 'J' << res[i] - 52;
  }
  return 0;
}