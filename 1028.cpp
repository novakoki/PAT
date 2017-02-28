#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>
#include <iomanip>
#include <map>
#include <string>
#include <cstdio>
#include <cstring>
using namespace std;

struct Rank {
  int id;
  char name[10];
  int score;
};

bool comps(Rank& a, Rank& b) {
  if (a.score != b.score)
    return a.score < b.score;
  else return a.id < b.id;
}

bool compn(Rank& a, Rank& b) {
  if (strcmp(a.name, b.name) != 0)
    return strcmp(a.name, b.name) < 0;
  else return a.id < b.id;
}

bool compi(Rank& a, Rank& b) {
  return a.id < b.id;
}

int main() {
  int n, k, score, id;
  char name[10];
  while (cin >> n >> k) {
    Rank* v = new Rank[n];
    for (int i = 0; i < n; i++) {
      scanf("%d %s %d", &v[i].id, &v[i].name, &v[i].score);
    }
    switch (k) {
      case 1: sort(v, v + n, compi); break;
      case 2: sort(v, v + n, compn); break;
      case 3: sort(v, v + n, comps); break;
      default: break;
    }
    for (auto it = v; it != v + n; it++)
      printf("%06d %s %d\n", it->id, it->name, it->score);
  }
  return 0;
}