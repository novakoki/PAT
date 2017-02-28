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
#include <valarray>
using namespace std;

int main() {
#ifdef _DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int n;
  while (cin >> n) {
    int m = sqrt(n + 0.5);
    bool prime = true;
    for (int i = 12; i >= 1; i--) {
      if (!prime)
        break;
      for (int start = 2; start <= m; start++) {
        long long product = 1;
        for (int j = 0; j < i; j++)
          product *= start + j;
        if (n % product == 0) {
          cout << i << endl;
          for (int j = 0; j < i; j++) {
            if (j != 0)
              cout << "*";
            cout << start + j;
          }
          cout << endl;
          prime = false;
          break;
        }
      }
    }
    if (prime) {
      cout << 1 << endl;
      cout << n << endl;
    }
  }
  return 0;
}