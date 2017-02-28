#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <iomanip>
#include <map>
#include <string>
#include <cstdio>
using namespace std;

int strToTime(string s) {
  return ((s[0] - '0') * 10 + s[1] - '0') * 3600 +
    ((s[3] - '0') * 10 + s[4] - '0') * 60 +
    (s[6] - '0') * 10 + s[7] - '0';
}

int main() {
  int N, K;
  string arrTime;
  int cost;
  while (cin >> N >> K) {
    map<int, int> m;
    vector<int> sum(K, 8*3600);
    for (int i = 0; i < N; i++) {
      cin >> arrTime >> cost;
      m[strToTime(arrTime)] = cost * 60;
    }
    int count = 0;
    int total = 0;
    for (auto it = m.begin(); it != m.end(); it++) {
      if (it->first > 17 * 3600) break;
      auto minIt = min_element(sum.begin(), sum.end());
      total += it->first < *minIt ? *minIt - it->first : 0;
      *minIt = max(*minIt, it->first) + it->second;
      count++;
    }
    printf("%.1f\n", total / 60.0 / count);
  }
  return 0;
}