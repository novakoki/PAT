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
  int n, p;
  scanf("%d%d", &n, &p);
  if (n == 0) {
    printf("0\n");
  }
  else {
    vector<long long> v(n, 0);
    for (int i = 0; i < n; i++)
      scanf("%lld", &v[i]);
    sort(v.begin(), v.end());
    int res = 1;
    for (int i = 0; i + res < n; i++) {
      for (int j = i + res; j < n; j++) {
        if (v[j] <= v[i] * p) {
          res = max(res, j - i + 1);
        }
        else break;
      }
    }
    printf("%d\n", res);
  }
  return 0;
}