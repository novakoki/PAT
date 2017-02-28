#include <iostream>
#include <sstream>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>
#include <iomanip>
#include <map>
#include <string>
#include <cstdio>
#include <cstring>
#include <climits>
using namespace std;

struct Node {
  char data;
  int next;
  bool visited;

  Node() { visited = false; }
};

int main() {
  int a, b, N;
  scanf("%d %d %d", &a, &b, &N);
  Node* mem = new Node[100000];
  int address, next;
  char data;
  bool common = true;
  for (int i = 0; i < N; i++) {
    scanf("%d %c %d", &address, &data, &next);
    mem[address].data = data;
    mem[address].next = next;
  }
  int i;
  for (i = a; i != -1; i = mem[i].next) {
    mem[i].visited = true;
  }
  for (i = b; i != -1; i = mem[i].next) {
    if (mem[i].visited)    
      break;
  }
  if (i != -1)
    printf("%05d\n", i);
  else printf("-1\n");
  return 0;
}