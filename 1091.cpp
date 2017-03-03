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

int m, n, l, t;
bool stroke[1300][130][80], visited[1300][130][80];

struct Point {
  int x, y, z;

  Point(int x, int y, int z):x(x), y(y), z(z) {}
};

int bfs(Point s) {
  queue<Point> q;
  q.push(s);
  int cnt = 0;
  while (!q.empty()) {
    auto t = q.front(); q.pop();
    if (t.x < 0 || t.x >= m || t.y < 0 || t.y >= n || t.z < 0 || t.z >= l ||
      !stroke[t.x][t.y][t.z] || visited[t.x][t.y][t.z])
      continue;
    visited[t.x][t.y][t.z] = true;
    cnt++;
    q.push(Point(t.x + 1, t.y, t.z));
    q.push(Point(t.x - 1, t.y, t.z));
    q.push(Point(t.x, t.y + 1, t.z));
    q.push(Point(t.x, t.y - 1, t.z));
    q.push(Point(t.x, t.y, t.z + 1));
    q.push(Point(t.x, t.y, t.z - 1));
  }
  return cnt >= t ? cnt : 0;
}

int main() {
#ifdef _DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  scanf("%d%d%d%d", &m, &n, &l, &t);

  for (int i = 0; i < l; i++)
    for (int j = 0; j < m; j++)
      for (int k = 0; k < n; k++)
        scanf("%d", &stroke[j][k][i]);
  int res = 0;
  for (int i = 0; i < l; i++)
    for (int j = 0; j < m; j++)
      for (int k = 0; k < n; k++)
        if(stroke[j][k][i] && !visited[j][k][i])
          res += bfs(Point(j, k, i));

  printf("%d\n", res);
  return 0;
}