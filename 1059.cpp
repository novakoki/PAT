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
#include <set>
#include <stack>
#include <cstdio>
#include <cstring>
#include <climits>
using namespace std;

int main() {
  long int n;
  scanf("%d", &n);
  if (n == 1) printf("1=1\n");
  else {
    int m = sqrt(n + 0.5);
    int l = sqrt(m + 0.5);
    vector<bool> prime(n + 1, true);
    for (int i = 2; i <= l; i++) {
      if (prime[i]) {
        for (int j = i * i; j <= m; j += i)
          prime[j] = false;
      }
    }
    printf("%d=", n);
    int count = 0;
    bool first = true;
    for (int i = 2; i <= n; i++) {
      count = 0;
      if (prime[i]) {
        while (n % i == 0) {
          n /= i;
          count++;
        }
        if (count != 0) {
          if (!first) printf("*");
          printf("%d", i);
          if (count > 1) printf("^%d", count);
          first = false;
        }
      }
    }
    printf("\n");
  }
  return 0;
}