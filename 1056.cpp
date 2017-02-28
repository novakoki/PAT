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

struct Node {
  int level, index, rank, weight;
};

int main() {
  int ng, np;
  cin >> ng >> np;
  vector<Node> v;
  int order;
  v.resize(ng);
  for (int i = 0; i < ng; i++) {
    cin >> v[i].weight;
    v[i].index = i;
  }
  vector<Node> res, local(v);
  for (int i = 0; i < ng; i++) {
    cin >> order;
    local[i] = v[order];
  }
  int level = 0;
  while (!local.empty()) {
    if (local.size() == 1) {
      res.push_back(local[0]);
      local.pop_back();
    }
    else {
      vector<Node> tmp;
      for (int i = 0; i < local.size(); i += np) {
        int fattest = 0, winner = 0;
        for (int j = 0; j < np && i + j < local.size(); j++) {
          if (local[i + j].weight > fattest) {
            fattest = local[i + j].weight;
            winner = j;
          }
        }
        for (int j = 0; j < np && i + j < local.size(); j++) {
          if (j == winner) {
            local[i + j].level = level + 1;
            tmp.push_back(local[i + j]);
          }
          else {
            local[i + j].level = level;
            res.push_back(local[i + j]);
          }
        }
      }
      local = tmp;
      level++;
    }
  }
  v[res[ng - 1].index].rank = 1;
  for (int i = ng-2; i >= 0; i--) {
    if (res[i].level == res[i + 1].level)
      v[res[i].index].rank = v[res[i + 1].index].rank;
    else
      v[res[i].index].rank = ng - i;
  }
  for (int i = 0; i < ng; i++) {
    if (i != 0) cout << ' ';
    cout << v[i].rank;
  }
  return 0;
}