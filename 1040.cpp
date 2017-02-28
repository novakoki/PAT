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
using namespace std;

int main() {
  string s;
  getline(cin, s);
  int max_length = 1;
  vector<vector<bool> > dp;
  dp.resize(s.length());
  for (auto&& item : dp) item.resize(s.length());
  for (int i = 1; i <= s.length(); i++) {
    for (int j = 0; j + i <= s.length(); j++) {
      if (i == 1) dp[j][j] = true;
      else if (i == 2) {
        dp[j][j + 1] = s[j] == s[j + 1];
        if (dp[j][j + 1] && max_length < 2) {
          max_length = 2;
        }
      }
      else {
        dp[j][j + i - 1] = s[j] == s[j + i - 1] && dp[j + 1][j + i - 2];
        if (dp[j][j + i - 1] && max_length < i) {
          max_length = i;
        }
      }
    }
  }
  cout << max_length;
  return 0;
}