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

struct Apply {
  int id, ge, gi;
  vector<int> choices;

  bool operator< (const Apply& rhs) const {
    if (ge + gi == rhs.ge + rhs.gi) {
      return ge > rhs.ge;
    }
    else
      return ge + gi > rhs.ge + rhs.gi;
  }

  bool operator== (const Apply& rhs) const {
    return ge == rhs.ge && gi == rhs.gi;
  }
};

bool comp(const Apply& a, const Apply& b) {
  return a.id < b.id;
}

int main() {
  /*freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);*/
  int n, m, k;
  scanf("%d%d%d", &n, &m, &k);
  vector<int> quota(m, 0);
  vector<vector<Apply> > admits;
  admits.resize(m);
  for (int i = 0; i < m; i++)
    scanf("%d", &quota[i]);
  vector<Apply> apps;
  apps.resize(n);
  for (int i = 0; i < n; i++) {
    apps[i].id = i;
    scanf("%d %d", &apps[i].ge, &apps[i].gi);
    apps[i].choices.resize(k);
    for (int j = 0; j < k; j++)
      scanf("%d", &apps[i].choices[j]);
  }
  sort(apps.begin(), apps.end());
  for (auto app : apps) {
    for (auto choice : app.choices) {
      if (admits[choice].size() < quota[choice] ||
        (!admits[choice].empty() && (*admits[choice].rbegin()) == app)) {
        admits[choice].push_back(app);
        break;
      }
    }
  }
  for (auto admit : admits) {
    if (!admit.empty()) {
      sort(admit.begin(), admit.end(), comp);
      for (auto it = admit.begin(); it != admit.end(); it++) {
        if (it != admit.begin())
          printf(" ");
        printf("%d", it->id);
      }
    }
    printf("\n");
  }
  return 0;
}