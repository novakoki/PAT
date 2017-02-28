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
  /*freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);*/
  int m, n, key, pos;
  scanf("%d %d", &m, &n);

  vector<bool> is_prime(2*m, true);
  is_prime[0] = false;
  is_prime[1] = false;
  for (int i = 2; i * i < 2*m; i++) {
    if (is_prime[i]) {
      for (int j = i*i; j < 2*m; j+=i)
        is_prime[j] = false;
    }
  }
  while (!is_prime[m]) m++;

  vector<bool> table(m, false);
  vector<int> res;
  while (n--) {
    scanf("%d", &key);
    int index = 0;
    bool flag = false;
    pos = key % m;
    for (int step = 0; step < m; step++) {
      index = (pos + step * step) % m;
      if (!table[index]) {
        table[index] = true;
        res.push_back(index);
        flag = true;
        break;
      }
    }
    if (!flag)
      res.push_back(-1);
  }
  for (int i = 0; i < res.size(); i++) {
    if (i != 0)
      printf(" ");
    if (res[i] == -1)
      printf("-");
    else
      printf("%d", res[i]);
  }
  return 0;
}