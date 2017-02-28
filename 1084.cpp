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

char toUpper(const char c) {
  if ('a' <= c && c <= 'z')
    return c + 'A' - 'a';
  else return c;
}

char toLower(const char c) {
  if ('A' <= c && c <= 'Z')
    return c + 'a' - 'A';
  else return c;
}

int main() {
  /*freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);*/
  string origin, typed;
  cin >> origin >> typed;
  unordered_map<char, bool> m;
  for (auto item : typed) {
    m[item] = true;
  }
  for (auto item : origin) {
    if (m.find(item) == m.end()) {
      cout << toUpper(item);
      m[toLower(item)] = true;
      m[toUpper(item)] = true;
    }
  }
  return 0;
}