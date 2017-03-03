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
#include <memory>
#include <valarray>
#include <numeric>
#include <functional>
using namespace std;

int main() {
#ifdef _DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int k;
  cin >> k;
  string s, origin, stuck;
  unordered_set<char> unstucked, stucked;
  cin >> s;
  for (int i = 0; i < s.length();) {
    int cnt = 1;
    while (i + cnt < s.length() && s[i + cnt] == s[i])
      cnt++;
    if (cnt % k != 0)
      unstucked.insert(s[i]);
    i += cnt;
  }
  for (int i = 0; i < s.length();) {
    if (unstucked.find(s[i]) != unstucked.end()) {
      origin += s[i++];
    }
    else {
      int cnt = 1;
      while (i + cnt < s.length() && s[i + cnt] == s[i])
        cnt++;
      origin += string(cnt / k, s[i]);
      if (stucked.find(s[i]) == stucked.end()) {
        stuck += s[i];
        stucked.insert(s[i]);
      }
      i += cnt;
    }
  }
  cout << stuck << endl;
  cout << origin << endl;
  return 0;
}