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
  int n;
  cin >> n;
  string s;
  int cnt = 0;
  double sum = 0.0, num = 0.0;
  while (n--) {
    cin >> s;
    int point = -1;
    bool legal = true;
    for (int i = 0; i < s.length(); i++) {
      if (s[i] == '-') {
        if (i != 0) {
          legal = false;
          break;
        }
      }
      else if (s[i] == '.') {
        if (s.length() - i - 1 > 2 || (point != -1)) {
          legal = false;
          break;
        }
        else
          point = i;
      }
      else if (s[i] > '9' || '0' > s[i]) {
        legal = false;
        break;
      }
    }
    if (legal)
      num = stod(s);
    if (legal && -1000 <= num && num <= 1000) {
      sum += stod(s);
      cnt++;
    }
    else {
      cout << "ERROR: " << s << " is not a legal number" << endl;
    }
  }
  if (cnt == 0)
    cout << "The average of 0 numbers is Undefined" << endl;
  else if (cnt == 1)
    cout << "The average of 1 number is " << fixed << setprecision(2) << sum << endl;
  else
    cout << "The average of " << cnt << " numbers is " << fixed << setprecision(2) << sum / cnt << endl;
  return 0;
}