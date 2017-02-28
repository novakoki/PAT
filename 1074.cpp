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

struct Node {
  int addr, val, next;
};

int main() {
  int head, n, k, addr;
  scanf("%d %d %d", &head, &n, &k);
  Node* mem = new Node[100000];
  Node* li = new Node[n];
  for (int i = 0; i < n; i++) {
    scanf("%d", &addr);
    mem[addr].addr = addr;
    scanf("%d %d", &mem[addr].val, &mem[addr].next);
  }
  int p = head, sum = 0;
  while (p != -1) {
    li[sum++] = mem[p];
    p = mem[p].next;
  }
  Node* q = li;
  
  while (true) {
    if (q + k <= li + sum) {
      reverse(q, q + k);
      q += k;
    }
    else
      break;
  }
  for (int i = 0; i < sum; i++) {
    if (i != sum - 1)
      printf("%05d %d %05d\n", li[i].addr, li[i].val, li[i + 1].addr);
    else
      printf("%05d %d -1\n", li[i].addr, li[i].val);
  }
  return 0;
}