#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <iomanip>
#include <map>
#include <string>
#include <cstdio>
using namespace std;

string add(string a, string b) {
  string res;
  res.resize(a.length() + 1);
  int sum = 0, carry = 0;
  for (int i = a.length() - 1; i >= 0; i--) {
    sum = carry + a[i] - '0' + b[i] - '0';
    carry = sum / 10;
    res[i + 1] = sum % 10 + '0';
  }
  if (carry != 0) {
    res[0] = carry + '0';
    return res;
  }
  else return res.substr(1);
}

bool isPalin(string s) {
  if (s.length() == 1) return true;
  int low = 0, high = s.length() - 1;
  while (low < high) {
    if (s[low++] != s[high--]) return false;
  }
  return true;
}

int main() {
  string s;
  int n;
  while (cin >> s >> n) {
    int count = 0;
    while (!isPalin(s) && count < n) {
      string origin = s;
      reverse(s.begin(), s.end());
      s = add(s, origin);
      count++;
    }
    cout << s << endl;
    cout << count << endl;
  }
  return 0;
}