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
using namespace std;

int main() {
#ifdef _DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int n;
  while (scanf("%d", &n) != EOF) {
    vector<int> so(n+1, 0), ta(n+1, 0);
    for (int i = 1; i <= n; i++)
      scanf("%d", &so[i]);
    for (int i = 1; i <= n; i++)
      scanf("%d", &ta[i]);
    int i = 1, j = 1;
    for (i; i < n && ta[i] <= ta[i + 1]; i++);
    for (j = i + 1; j <= n && so[j] == ta[j]; j++);

    if (j == n + 1) {
      printf("Insertion Sort\n");
      sort(ta.begin() + 1, ta.begin() + i + 2);
    }
    else {
      printf("Heap Sort\n");
      int index = n;
      for (index; index > 1 && ta[index] >= ta[index - 1]; index--);
      swap(ta[1], ta[index]);

      for (int i = 1; 2 * i < index;) {
        int child = 2 * i;
        if (child + 1 < index && ta[child] < ta[child+1])
          child++;
        if (ta[i] < ta[child]) {
          swap(ta[i], ta[child]);
          i = child;
        }
        else
          break;
      }
    }

    for (int i = 1; i < ta.size(); i++) {
      if (i != 1)
        printf(" ");
      printf("%d", ta[i]);
    }
    printf("\n");
  }
  return 0;
}