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

struct Node {
  char name[9];
  int age, worth;

  bool operator< (const Node& rhs) const {
    if (worth == rhs.worth) {
      if (age == rhs.age) return strcmp(name, rhs.name) < 0;
      else return age < rhs.age;
    }
    else return worth > rhs.worth;
  }
};

int main() {
  int M, K;
  scanf("%d %d", &M, &K);
  vector<Node > v;
  v.resize(M);
  int age, worth;
  string name;
  for (int i = 0; i < M; i++) {
    scanf("%s %d %d", v[i].name, &v[i].age, &v[i].worth);
  }
  sort(v.begin(), v.end());
  int n, a, b;
  for (int i = 1; i <= K; i++) {
    scanf("%d %d %d", &n, &a, &b);
    vector<Node > res;
    int count = 0;
    for (auto item : v) {
      if (count >= n) break;
      if (a <= item.age && item.age <= b) {
        res.push_back(item);
        count++;
      }
    }
    printf("Case #%d:\n", i);
    for (auto item : res) printf("%s %d %d\n", item.name, item.age, item.worth);
    if (res.empty()) printf("None\n");
  }
  return 0;
}