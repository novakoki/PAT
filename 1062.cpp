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
  int id, v, t;

  Node(){}
  Node(int i, int v, int t):id(i), v(v), t(t){}

  bool operator< (const Node& b) const {
    if (t + v == b.t + b.v) {
      if (v == b.v) {
        return id < b.id;
      }
      else return v > b.v;
    }
    else return t + v > b.t + b.v;
  }
};

int main() {
  int N, L, H;
  scanf("%d %d %d", &N, &L, &H);
  int id, v, t;
  vector<Node> sage, noble, fool, small;
  for (int i = 0; i < N; i++) {
    scanf("%d %d %d", &id, &v, &t);
    if (t >= L && v >= L) {
      if (v >= H && t >= H) {
        sage.push_back(Node(id, v, t));
      }
      else if (t < H && v >= H) {
        noble.push_back(Node(id, v, t));
      }
      else if (t < H && v < H && t <= v) {
        fool.push_back(Node(id, v, t));
      }
      else {
        small.push_back(Node(id, v, t));
      }
    }
  }
  sort(sage.begin(), sage.end());
  sort(noble.begin(), noble.end());
  sort(fool.begin(), fool.end());
  sort(small.begin(), small.end());
  printf("%d\n", sage.size() + noble.size() + fool.size() + small.size());
  for (auto item : sage) printf("%08d %d %d\n", item.id, item.v, item.t);
  for (auto item : noble) printf("%08d %d %d\n", item.id, item.v, item.t);
  for (auto item : fool) printf("%08d %d %d\n", item.id, item.v, item.t);
  for (auto item : small) printf("%08d %d %d\n", item.id, item.v, item.t);
  return 0;
}