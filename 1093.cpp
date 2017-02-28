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
  string s;
  getline(cin, s);
  const int mod = 1000000007;
  int res = 0, ct = 0, cp = 0;
  for (auto item : s) {
    if (item == 'T')
      ct++;
  }
  for (auto item : s) {
    if (item == 'P')
      cp++;
    else if (item == 'T')
      ct--;
    else if (item == 'A')
      res = ((res % mod) + ((cp % mod) * (ct % mod)) % mod) % mod;
  }
  cout << res << endl;
  return 0;
}