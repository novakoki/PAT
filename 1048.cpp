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
#include <cstdio>
#include <cstring>
#include <climits>
#include <set>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  int n;
  vector<int> v(1000, 0);
  while (N--) {
    cin >> n;
    v[n]++;
  }
  bool exist = false;
  for (int i = 0; i < 1000; i++) {
    if (v[i]) {
      v[i]--;
      if (M > i && v[M - i]) {
        exist = true;
        cout << i << ' ' << M - i;
        break;
      }
      else v[i]++;
    }
  }
  if (!exist) cout << "No Solution" << endl;
  return 0;
}