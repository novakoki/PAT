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

int main() {
#ifdef _DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int n;
  scanf("%d", &n);
  vector<int> v(n, 0);
  for (int i = 0; i < n; i++)
    scanf("%d", &v[i]);
  sort(v.begin(), v.end());
  int sum0 = 0, sum1 = 0;
  for (int i = 0; i < n / 2; i++)
    sum0 += v[i];
  for (int i = n / 2; i < n; i++)
    sum1 += v[i];
  printf("%d %d\n", n % 2 == 0 ? 0 : 1, sum1 - sum0);
  return 0;
}