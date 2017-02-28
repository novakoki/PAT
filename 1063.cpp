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
#include <set>
#include <stack>
#include <cstdio>
#include <cstring>
#include <climits>
using namespace std;

int main() {
  int N, M, K;
  scanf("%d", &N);
  vector<set<int> > v;
  v.resize(N);
  int n;
  for (int i = 0; i < N; i++) {
    scanf("%d", &M);
    for (int j = 0; j < M; j++) {
      scanf("%d", &n);
      v[i].insert(n);
    }
  }
  scanf("%d", &K);
  int a, b;
  while (K--) {
    scanf("%d %d", &a, &b);
    int common = 0, total = v[a-1].size();
    for (auto item : v[b-1]) {
      if (v[a - 1].find(item) != v[a - 1].end())
        common++;
      else total++;
    }
    //cout << common << ' ' << total << endl;
    printf("%.1f%%\n", common * 100 / (float)total);
  }
  return 0;
}