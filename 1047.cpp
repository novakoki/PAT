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

int strToInt(char s[5]) {
  return ((s[0] - 'A') * 26 * 26 +
    (s[1] - 'A') * 26 +
    (s[2] - 'A')) * 10 +
    (s[3] - '0');
}

int main() {
  int N, K, c, cno;
  scanf("%d %d", &N, &K);
  vector<vector<int> > v;
  v.resize(K+1);
  char name[5];
  while (N--) {
    scanf("%s %d", name, &c);
    while (c--) {
      scanf("%d", &cno);
      v[cno].push_back(strToInt(name));
    }
  }
  for (int i = 1; i <= K; i++) {
    sort(v[i].begin(), v[i].end());
    printf("%d %d\n", i, v[i].size());
    for (auto item : v[i])
      printf("%c%c%c%d\n", (item / 10) / 26 / 26 + 'A', (item / 10) / 26 % 26 + 'A', (item / 10) % 26 + 'A', item % 10);
  }
  return 0;
}