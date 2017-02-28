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
#include <stack>
using namespace std;

int main() {
  int M, N, K;
  cin >> M >> N >> K;
  vector<int> p(N, 0);
  while (K--) {
    bool ok = true;
    for (int i = 0; i < N; i++) cin >> p[i];
    stack<int> s;
    int i = 1, j = 0;
    while (j < N) {
      if (i == p[j]) {
        i++; j++;
      }
      else if (!s.empty() && s.top() == p[j]) {
        s.pop();
        j++;
      }
      else if (i <= N) {
        s.push(i++);
        if (s.size() >= M) {
          ok = false;
          break;
        }
      }
      else {
        ok = false;
        break;
      }
    }
    if (ok) cout << "YES" << endl;
    else cout << "NO" << endl;
  }
  return 0;
}