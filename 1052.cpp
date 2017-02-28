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
  int addr, key, next;
  bool flag;

  Node(){
    flag = false;
  }
  Node(int a, int k, int n):addr(a), key(k), next(n){}

  bool operator< (const Node& rhs) const {
    if (!flag || !rhs.flag) return flag > rhs.flag;
    return key < rhs.key;
  }
};

int main() {
  int n, head;
  cin >> n >> head;
  vector<Node> mem;
  mem.resize(100000);
  int addr, key, next;
  while (n--) {
    scanf("%d %d %d", &addr, &key, &next);
    mem[addr] = Node(addr, key, next);
  }
  int count = 0;
  for (int i = head; i != -1; i = mem[i].next) {
    mem[i].flag = true;
    count++;
  }
  if (count == 0) {
    printf("0 -1\n");
  }
  else {
    sort(mem.begin(), mem.end());
    printf("%d %05d\n", count, mem[0].addr);
    for (int i = 0; i < count; i++) {
      if (mem[i].flag) {
        printf("%05d %d ", mem[i].addr, mem[i].key);
        if (mem[i + 1].flag) printf("%05d\n", mem[i + 1].addr);
        else printf("-1\n");
      }
    }
  }
  return 0;
}