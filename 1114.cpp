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

vector<int> uf(10000, 0);

int find(int a) {
  int root = a;
  while (uf[root] != root)
    root = uf[root];
  uf[a] = root;
  return root;
}

void _union(int a, int b) {
  int r1 = find(a), r2 = find(b);
  if (r1 < r2)
    uf[r2] = r1;
  else
    uf[r1] = r2;
}

struct estate {
  int id, m, m_e, area;
  double avg_set, avg_area;
  estate() {
    m = m_e = area = 0;
  }

  bool operator< (const estate& e) {
    if (e.avg_area == avg_area)
      return id < e.id;
    return avg_area > e.avg_area;
  }
};

int main() {
#ifdef _DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int n, id, fa, mo, k, chd, m, area;
  scanf("%d", &n);
  for (int i = 0; i < 10000; i++)
    uf[i] = i;
  vector<estate> estates;
  estates.resize(10000);
  unordered_set<int> ids, roots;
  while (n--) {
    scanf("%d%d%d%d", &id, &fa, &mo, &k);
    if (fa != -1) {
      _union(id, fa);
      ids.insert(fa);
    }
    if (mo != -1) {
      _union(id, mo);
      ids.insert(mo);
    }
    while (k--) {
      scanf("%d", &chd);
      _union(id, chd);
      ids.insert(chd);
    }
    scanf("%d%d", &estates[id].m_e, &estates[id].area);
    ids.insert(id);
  }
  vector<estate> family;
  family.resize(10000);
  for (auto item : ids) {
    int root = find(item);
    roots.insert(root);
    family[root].m++;
    family[root].m_e += estates[item].m_e;
    family[root].area += estates[item].area;
  }
  vector<estate> res;
  for (auto root : roots) {
    family[root].id = root;
    family[root].avg_set = (double)family[root].m_e / family[root].m;
    family[root].avg_area = (double)family[root].area / family[root].m;
    res.push_back(family[root]);
  }
  sort(res.begin(), res.end());
  printf("%d\n", res.size());
  for (auto item : res)
    printf("%04d %d %.3lf %.3lf\n", item.id, item.m, item.avg_set, item.avg_area);
  return 0;
}