#include <iostream>
#include <sstream>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>
#include <iomanip>
#include <map>
#include <unordered_map>
#include <string>
#include <cstdio>
#include <cstring>
#include <climits>
#include <set>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> v(n+1, 0);
  int sum = 0;
  int d;
  for (int i = 1; i <= n; i++) {
    cin >> d;
    sum += d;
    v[i] = sum;
  }
  cin >> n;
  int a, b;
  while (n--) {
    cin >> a >> b;
    if (a > b) swap(a, b);
    cout << min(v[b - 1] - v[a - 1], sum - (v[b - 1] - v[a - 1])) << endl;
  }
  return 0;
}