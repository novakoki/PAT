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
using namespace std;

bool is_alpha(char c) {
  return ('0' <= c && c <= '9') ||
    ('a' <= c && c <= 'z') ||
    ('A' <= c && c <= 'Z');
}

char to_lower_case(char c) {
  if ('A' <= c && c <= 'Z')
    return c + 'a' - 'A';
  else return c;
}

int main() {
  char c;
  unordered_map<string, int> freq;
  string tmp = "", res = "";
  int cnt = 0;
  while (scanf("%c", &c) != EOF) {
    if (is_alpha(c)) {
      tmp += to_lower_case(c);
    }
    else if (!tmp.empty()) {
      if (freq.find(tmp) == freq.end())
        freq[tmp] = 1;
      else freq[tmp]++;
      if (freq[tmp] > cnt) {
        res = tmp;
        cnt = freq[tmp];
      }
      tmp = "";
    }
  }
  cout << res << ' ' << cnt;
  return 0;
}