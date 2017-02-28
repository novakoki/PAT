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
using namespace std;

bool comp(const string& a, const string& b) {
  return a + b < b + a;
}

int main() {
  int n;
  cin >> n;
  vector<string> v;
  v.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  sort(v.begin(), v.end(), comp);
  string res = "";
  for (auto it = v.begin(); it != v.end(); it++)
    res = res + *it;
  int j = 0;
  while (res[j] == '0') j++;
  if (res.substr(j).empty()) cout << 0;
  else cout << res.substr(j);
  return 0;
}