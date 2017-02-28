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
using namespace std;

struct Node {
  int val, addr, next;
};

int main() {
#ifdef _DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int n, head, addr;
  unique_ptr<Node[]> mem(new Node[100000]);
  scanf("%d %d", &head, &n);
  while (n--) {
    scanf("%d", &addr);
    scanf("%d %d", &mem[addr].val, &mem[addr].next);
    mem[addr].addr = addr;
  }
  unordered_map<int, bool> visited;
  vector<Node> li, removed;
  for (int p = head; p != -1; p = mem[p].next) {
    if (visited.find(abs(mem[p].val)) != visited.end())
      removed.push_back(mem[p]);
    else {
      visited[abs(mem[p].val)] = true;
      li.push_back(mem[p]);
    }
  }
  for (int i = 0; i < li.size(); i++) {
    printf("%05d %d ", li[i].addr, li[i].val);
    if (i != li.size() - 1)
      printf("%05d\n", li[i + 1].addr);
    else
      printf("-1\n");
  }
  for (int i = 0; i < removed.size(); i++) {
    printf("%05d %d ", removed[i].addr, removed[i].val);
    if (i != removed.size() - 1)
      printf("%05d\n", removed[i + 1].addr);
    else
      printf("-1\n");
  }
  return 0;
}