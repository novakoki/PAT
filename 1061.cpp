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

string weeks[] = { "MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN" };

int main() {
  string a, b, c, d;
  cin >> a >> b >> c >> d;
  int len = min(a.length(), b.length());
  bool week = true;
  for (int i = 0; i < len; i++) {
    if (a[i] == b[i]) {
      if (week) {
        if (a[i] <= 'G' && a[i] >= 'A') {
          cout << weeks[a[i] - 'A'] << ' ';
          week = false;
        }
      }
      else if ((a[i] >= '0' && a[i] <= '9') || (a[i] >= 'A' && a[i] <= 'N')) {
        if (a[i] <= '9') printf("%02d:", a[i] - '0');
        else printf("%02d:", a[i] - 'A' + 10);
        break;
      }
    }
  }
  len = min(c.length(), d.length());
  for (int i = 0; i < len; i++) {
    if (c[i] == d[i] && ((c[i] >= 'A' && c[i] <= 'Z') || (c[i] >= 'a' && c[i] <= 'z')))  {
      printf("%02d", i);
      break;
    }
  }
  return 0;
}