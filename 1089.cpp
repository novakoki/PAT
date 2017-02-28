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
  while (scanf("%d", &n) != EOF) {
    vector<int> source(n, 0), target(n, 0), tmp(n, 0);
    for (int i = 0; i < n; i++)
      scanf("%d", &source[i]);
    for (int i = 0; i < n; i++)
      scanf("%d", &target[i]);
    
    vector<int> m = source;
    auto it = source.end();
    int i = 0, j = 0;
    for (i = 0; i < n - 1 && target[i] <= target[i + 1]; i++);
    for (j = i + 1; j < n && source[j] == target[j]; j++);

    if (j == n) {
      printf("Insertion Sort\n");
      sort(source.begin(), source.begin() + i + 2);
      for (int i = 0; i < source.size(); i++) {
        if (i != 0)
          printf(" ");
        printf("%d", source[i]);
      }
      printf("\n");
    }
    else {
      int k = 2;
      bool flag = false;
      while (k <= n) {
        for (auto it = m.begin(); it != m.end(); it += k) {
          if (m.end() - it > k)
            sort(it, it + k);
          else {
            sort(it, m.end());
            break;
          }
        }
        if (flag) {
          printf("Merge Sort\n");
          for (int i = 0; i < m.size(); i++) {
            if (i != 0)
              printf(" ");
            printf("%d", m[i]);
          }
          printf("\n");
          break;
        }
        bool equal = true;
        for (int i = 0; i < n; i++) {
          if (m[i] != target[i]) {
            equal = false;
            break;
          }
        }
        flag = equal;
        k *= 2;
      }
    }
  }
  return 0;
}