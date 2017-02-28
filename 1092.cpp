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

  
  string s, e;
  while (cin >> s >> e) {
    unordered_map<char, int> fs, fe;
    for (auto c : e) {
      if (fe.find(c) != fe.end())
        fe[c]++;
      else
        fe[c] = 1;
    }

    for (auto c : s) {
      if (fs.find(c) != fs.end())
        fs[c]++;
      else
        fs[c] = 1;
    }
    int miss = 0, extra = 0;
    for (auto c : fe) {
      if (fs.find(c.first) == fs.end())
        miss += c.second;
      else if (fs[c.first] < c.second)
        miss += c.second - fs[c.first];
    }

    for (auto c : fs) {
      if (fe.find(c.first) == fe.end())
        extra += c.second;
      else if (c.second > fe[c.first])
        extra += c.second - fe[c.first];
    }

    if (miss == 0)
      printf("Yes %d\n", extra);
    else
      printf("No %d\n", miss);
  }
  return 0;
}