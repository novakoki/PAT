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
using namespace std;

vector<string> u = { "tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec" },
v = { "", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou" };

unordered_map<string, int> mu, mv;

string earth_to_mars(const string& s) {
  int n = stoi(s);
  int a = n / 13, b = n % 13;
  string res = "";
  if (a != 0) {
    res += v[a];
    if (b != 0)
      res += " " + u[b];
  }
  else
    res += u[b];
  return res;
}

int mars_to_earth(const string& s) {
  int i = 0;
  while (i < s.length() && s[i++] != ' ');
  if (i == s.length())
    return mu[s];
  else
    return mv[s.substr(0, i - 1)] * 13 + mu[s.substr(i, s.length() - i)];
}

int main() {
#ifdef _DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int n;
  string s;
  for (int i = 0; i < u.size(); i++) {
    mu[u[i]] = i;
    mu[v[i]] = i * 13;
    mv[v[i]] = i;
  }
  scanf("%d\n", &n);
  while (n--) {
    getline(cin, s);
    if ('0' <= s[0] && s[0] <= '9')
      cout << earth_to_mars(s) << endl;
    else
      cout << mars_to_earth(s) << endl;
  }
  return 0;
}