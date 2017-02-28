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

int strToInt(char name[5]) {
  return ((name[0] - 'A') * 26 * 26 +
    (name[1] - 'A') * 26 +
    (name[2] - 'A')) * 10 +
    (name[3] - '0');
}

vector<list<int> > ms(26 * 26 * 26 * 10 + 10);

int main() {
  int N, K;
  scanf("%d %d", &N, &K);
  int cno, sn, id;
  char name[5];
  while (K--) {
    scanf("%d %d", &cno, &sn);
    while (sn--) {
      scanf("%s", name);
      id = strToInt(name);
      if (ms[id].empty()) {
        ms[id].push_back(cno);
      }
      else ms[id].insert(lower_bound(ms[id].begin(), ms[id].end(), cno), cno);
    }
  }
  while (N--) {
    scanf("%s", name);
    id = strToInt(name);
    printf("%s %d", name, ms[id].size());
    //sort(ms[name].begin(), ms[name].end());
    for (auto it = ms[id].begin(); it != ms[id].end(); it++)
      printf(" %d", *it);
    printf("\n");
  }
  return 0;
}