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

  vector<bool> is_prime(10001, true);
  is_prime[0] = false;
  is_prime[1] = false;
  for (int i = 2; i * i < 10001; i++) {
    if (is_prime[i]) {
      for (int j = i * i; j < 10001; j += i)
        is_prime[j] = false;
    }
  }

  int n, k, id;
  scanf("%d", &n);
  vector<int> rank(10001, 0);
  vector<bool> checked(10001, false);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &id);
    rank[id] = i;
  }
  scanf("%d", &k);
  while (k--) {
    scanf("%d", &id);
    if (rank[id] == 0) {
      printf("%04d: Are you kidding?\n", id);
    }
    else {
      if (checked[id]) {
        printf("%04d: Checked", id);
      }
      else {
        if (rank[id] == 1) {
          printf("%04d: Mystery Award", id);
        }
        else if (is_prime[rank[id]]) {
          printf("%04d: Minion", id);
        }
        else {
          printf("%04d: Chocolate", id);
        }
        checked[id] = true;
      }
      printf("\n");
    }
  }

  return 0;
}