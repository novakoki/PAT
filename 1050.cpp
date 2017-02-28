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
  string s, sub;
  getline(cin, s);
  vector<bool> m(128, false);
  getline(cin, sub);
  for (auto item : sub) {
    m[item - 0] = true;
  }
  for (auto item : s) {
    if (!m[item - 0]) printf("%c", item);
  }
  return 0;
}