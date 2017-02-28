#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <stack>
#include <algorithm>
#include <cstdio>
#include <climits>
#include <queue>
#include <unordered_map>
using namespace std;

int main () {
  /*freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);*/
  int n, m, l;
  scanf("%d%d", &n, &m);
  vector<int> order(201, 0);
  int color;
  for (int i = 1; i <= m; i++) {
    scanf("%d", &color);
    order[color] = i;
  }
  scanf("%d", &l);
  vector<int> colors;
  colors.resize(l);
  int cnt = 0;
  for (int i = 0; i < l; i++) {
    scanf("%d", &color);
    if (order[color] > 0) {
      colors[cnt++] = order[color];
    }
  }
  vector<int> dp(cnt, 1), p(cnt, 0);

  int max_length = 1;
  for (int i = 1; i < cnt; i++) {
    for (int j = 0; j < i; j++) {
      if (colors[j] <= colors[i]) {
        dp[i] = dp[j] + 1;
      }
    }
    max_length = max(dp[i], max_length);
  }
  
  printf("%d\n", max_length);
  return 0;
}