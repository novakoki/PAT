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

int main() {
  int n;
  scanf("%d", &n);
  int high = 0, low = 0;
  bool same = true;
  int a[4];
  memset(a, 0, 4 * sizeof(int));
  int tmp = n, cnt = 0;
  while (tmp != 0) {
    a[cnt++] = tmp % 10;
    tmp /= 10;
  }
  for (int i = 0; i < 3; i++) {
    if (a[i] != a[i + 1]) {
      same = false;
      break;
    }
  }
  if (same) {
    printf("%04d - %04d = 0000\n", n, n);
  }
  else {
    const int target = 6174;
    int diff = 0;
    while (diff != target) {
      sort(a, a + 4);
      high = 0; low = 0;
      for (int i = 0; i < 4; i++) {
        high += a[i] * pow(10, i);
        low += a[i] * pow(10, 3 - i);
      }
      diff = high - low;
      printf("%04d - %04d = %04d\n", high, low, diff);
      cnt = 0;
      tmp = diff;
      memset(a, 0, 4 * sizeof(int));
      while (tmp != 0) {
        a[cnt++] = tmp % 10;
        tmp /= 10;
      }
    }
  }
  return 0;
}