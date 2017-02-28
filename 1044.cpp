#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <stack>
#include <algorithm>
#include <cstdio>
#include <queue>
using namespace std;

int main () {
  int n, m;
  scanf("%d %d", &n, &m);
  vector<int> sum(n, 0), num(n, 0);
  int part_sum = 0;
  for (int i = 0; i < n; i++) {
    scanf("%d", &num[i]);
    part_sum += num[i];
    sum[i] = part_sum;
  }
  bool is_possible = false;
  while (!is_possible) {
    for (int i = 0; i < n; i++) {
      vector<int>::iterator it = lower_bound(sum.begin(), sum.end(), m - num[i] + sum[i]);
      if (it != sum.end() && *it - sum[i] + num[i] == m) {
        is_possible = true;
        printf("%d-%d\n", i+1, it-sum.begin()+1);
      }
    }
    m++;
  }
  return 0;
}