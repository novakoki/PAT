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
  int n, m;
  cin >> n;
  vector<int> visited(10000, 0);
  vector<int> v;
  list<int> l;
  while (n--) {
    cin >> m;
    v.push_back(m);
    visited[m]++;
  }
  bool none = true;
  for (auto item : v) {
    if (visited[item] == 1) {
      none = false;
      cout << item;
      break;
    }
  }
  if (none) cout << "None";
  return 0;
}