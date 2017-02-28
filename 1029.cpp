#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>
#include <iomanip>
#include <map>
#include <string>
#include <cstdio>
#include <cstring>
using namespace std;

int main() {
  int m, n;
  cin >> m;
  long int* a = new long int[m];
  for (int i = 0; i < m; i++)
    scanf("%ld", &a[i]);
  cin >> n;
  long int* b = new long int[n];
  for (int i = 0; i < n; i++)
    scanf("%ld", &b[i]);
  long int* c = new long int[m + n];
  int cnt = 0, i = 0, j = 0;
  for (i, j; i < m && j < n;) {
    if (a[i] < b[j])
      c[cnt++] = a[i++];
    else
      c[cnt++] = b[j++];
  }
  while (i < m) c[cnt++] = a[i++];
  while (j < n) c[cnt++] = b[j++];
  printf("%ld\n", c[(m+n-1) / 2]);
  return 0;
}