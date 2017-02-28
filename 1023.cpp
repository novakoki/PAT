#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

void doubleNumber(string s, vector<int>& v) {
  v.clear();
  int carry = 0;
  int sum = 0;
  for (int i = s.length() - 1; i >= 0; i--) {
    sum = (s[i] - '0') * 2 + carry;
    carry = sum / 10;
    v.push_back(sum % 10);
  }
  if (carry != 0) v.push_back(carry);
}

int main() {
  string s;
  vector<int> v;
  while (cin >> s) {
    bool res = true;
    doubleNumber(s, v);
    if (s.length() == v.size()) {
      sort(s.begin(), s.end());
      vector<int> copy(v);
      sort(copy.begin(), copy.end());
      for (int i = 0; i < s.length(); i++) {
        if (s[i] - '0' != copy[i]) {
          res = false;
          break;
        }
      }
    }
    else {
      res = false;
    }
    if (res) {
      cout << "Yes" << endl;
    }
    else {
      cout << "No" << endl;
    }
    for (int i = v.size() - 1; i >= 0; i--) {
      cout << v[i];
    }
    cout << endl;
  }
  return 0;
}