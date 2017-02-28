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
#include <numeric>
#include <functional>
using namespace std;

int n, k, p;
int res_fact_sum = 0;
vector<int> temp, res, part_sum;

void dfs(int s, int sum, int cnt, int fact_sum) {
  if (sum > n || cnt > k) return;
  if (sum == n && cnt == k) {
    if (res.empty()) {
      res = temp;
      res_fact_sum = fact_sum;
    }
    else {
      if (fact_sum > res_fact_sum) {
        res = temp;
        res_fact_sum = fact_sum;
      }
      else if (fact_sum == res_fact_sum) {
        bool larger = false;
        for (int i = 0; i < k;) {
          if (temp[i] == res[i]) {
            i++;
          }
          else {
            larger = temp[i] > res[i];
            break;
          }
        }
        if (larger)
          res = temp;
      }
    }
  }
  else if (s >= 1) {
    temp.push_back(s);
    dfs(s, sum + part_sum[s], cnt + 1, fact_sum + s);
    temp.pop_back();
    dfs(s - 1, sum, cnt, fact_sum);
  }
}

int main() {
#ifdef _DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  scanf("%d %d %d", &n, &k, &p);
  part_sum.push_back(0);
  for (int i = 1; ; i++) {
    int ps = pow(i, p);
    if (ps > n)
      break;
    part_sum.push_back(ps);
  }
  dfs(part_sum.size() - 1, 0, 0, 0);
  if (res.empty())
    printf("Impossible\n");
  else {
    printf("%d = ", n);
    for (int i = 0; i < k; i++) {
      if (i != 0)
        printf(" + ");
      printf("%d^%d", res[i], p);
    }
    printf("\n");
  }
  return 0;
}