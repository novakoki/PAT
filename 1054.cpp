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
#include <stack>
using namespace std;

int main() {
  int M, N;
  cin >> M >> N;
  int s;
  unordered_map<int, int> m;
  for (int i = 0; i < M; i++) {
    for (int j = 0; j < N; j++) {
      scanf("%d", &s);
      if (m.find(s) != m.end()) m[s]++;
      else m[s] = 1;
    }
  }
  auto res = m.begin();
  for (auto it = m.begin(); it != m.end(); it++) {
    if (it->second > res->second) {
      res = it;
    }
  }
  cout << res->first;
  return 0;
}