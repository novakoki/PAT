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
  int N;
  scanf("%d", &N);
  vector<int> v(N, 0);
  for (int i = 0; i < N; i++)
    scanf("%d", &v[i]);
  sort(v.rbegin(), v.rend());
  int m = sqrt(N);
  while (N % m != 0)
    m++;
  int n = N / m;
  if (m < n)
    swap(m, n);
  vector<int> vec(n, 0);
  vector<vector<int> > mat(m, vec);

  int i = 0, j = 0, cnt = 0;

  while (cnt < N) {
    while (cnt < N && j < n && mat[i][j] == 0)
      mat[i][j++] = v[cnt++];
    j--; i++;
    while (cnt < N && i < m && mat[i][j] == 0)
      mat[i++][j] = v[cnt++];
    i--; j--;
    while (cnt < N && j >= 0 && mat[i][j] == 0)
      mat[i][j--] = v[cnt++];
    j++; i--;
    while (cnt < N && i >= 0 && mat[i][j] == 0)
      mat[i--][j] = v[cnt++];
    i++; j++;
  }

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (j != 0)
        printf(" ");
      printf("%d", mat[i][j]);
    }
    printf("\n");
  }
  return 0;
}