#include <iostream>
#include <sstream>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>
#include <iomanip>
#include <map>
#include <string>
#include <cstdio>
#include <cstring>
#include <climits>
using namespace std;

struct station {
  double price;
  int d;

  bool operator< (const station& rhs) const {
    return d < rhs.d;
  }
};

int main() {
  int cmax, d, avg, n;
  cin >> cmax >> d >> avg >> n;
  vector<station> v;
  v.resize(n+1);
  for (int i = 0; i < n; i++)
    scanf("%lf %d", &v[i].price, &v[i].d);
  v[n].price = 0; v[n].d = d;
  sort(v.begin(), v.end());
  double sum = 0;
  int left = 0, index = 0;
  if (v[0].d != 0) {
    printf("The maximum travel distance = 0.00\n");
  }
  else {
    for (int i = 0; i < n;) {
      double m = INT_MAX;
      if (i == n - 1) break;
      index = i+1;
      if (index < n+1) {
        for (int j = i + 1; j < n+1 && (v[j].d - v[i].d) <= cmax * avg; j++) {
          if (v[j].price <= v[i].price) {
            index = j;
            break;
          }
          if (v[j].price < m) {
            m = v[j].price;
            index = j;
          }
        }
        //printf("%d %d %d\n", index, i, left);
        if (v[index].d - v[i].d > cmax*avg) {
          index = i;
          break;
        }
        if (v[index].price < v[i].price) {
          sum += v[i].price / avg * (v[index].d - v[i].d - left);
          left = 0;
        }
        else {
          sum += v[i].price / avg * (cmax*avg - left);
          left = cmax*avg - (v[index].d - v[i].d);
        }
      }
      i = index;
    }
    if (d - v[index].d > cmax*avg) {
      printf("The maximum travel distance = %.2f\n", (float)v[index].d + cmax*avg);
    }
    else {
      sum += v[index].price / avg * (d - v[index].d - left);
      printf("%.2lf", sum);
    }
  }
  
  return 0;
}