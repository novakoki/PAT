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

string add(const string& a, const string& b) {
  string res = "";
  int i = 0, j = 0, sum = 0, carry = 0;
  for (i = a.length() - 1, j = b.length() - 1; i >= 0 && j >= 0; i--, j--) {
    sum = a[i] - '0' + b[j] - '0' + carry;
    res += sum % 10 + '0';
    carry = sum / 10;
  }
  while (i >= 0) {
    sum = a[i] - '0' + carry;
    res += sum % 10 + '0';
    carry = sum / 10;
    i--;
  }
  while (j >= 0) {
    sum = b[j] - '0' + carry;
    res += sum % 10 + '0';
    carry = sum / 10;
    j--;
  }
  if (carry != 0) res += carry + '0';
  reverse(res.begin(), res.end());
  return res;
}

string sub(const string& a, const string& b) {
  string res = "";
  int i = 0, j = 0, borrow = 0;
  for (i = a.length() - 1, j = b.length() - 1; i >= 0 && j >= 0; i--, j--) {
    if (a[i] - '0' - borrow < b[j] - '0') {
      res += 10 + a[i] - '0' - borrow - (b[j] - '0') + '0';
      borrow = 1;
    }
    else {
      res += a[i] - '0' - borrow - (b[j] - '0') + '0';
      borrow = 0;
    }
  }
  while (i >= 0) {
    if (a[i] - '0' - borrow < 0) {
      res += 10 + a[i] - '0' - borrow + '0';
      borrow = 1;
    }
    else {
      res += a[i] - '0' - borrow + '0';
      borrow = 0;
    }
    i--;
  }
  reverse(res.begin(), res.end());
  i = 0;
  while (res[i] == '0') i++;
  return res.substr(i);
}

bool comp(const string& a, const string& b) {
  if (a.length() == b.length()) {
    return a < b;
  }
  else return a.length() < b.length();
}

bool operator< (const string& a, const string& b) {
  if (a[0] == '-') {
    if (b[0] == '-') {
      return comp(b.substr(1), a.substr(1));
    }
    else return true;
  }
  else {
    if (b[0] == '-') return false;
    else return comp(a, b);
  }
}

int main() {
  string a, b, c, res;
  int n;
  cin >> n;
  for (int i = 1; i <= n;i++) {
    cin >> a >> b >> c;
    if (a[0] == '-') {
      if (b[0] == '-') {
        res = "-" + add(a.substr(1), b.substr(1));
      }
      else {
        if (a.substr(1) < b) {
          res = sub(b, a.substr(1));
        }
        else if (a.substr(1) == b) res = "0";
        else {
          res = "-" + sub(a.substr(1), b);
        }
      }
    }
    else {
      if (b[0] != '-') {
        res = add(a, b);
      }
      else {
        if (b.substr(1) < a) {
          res = sub(a, b.substr(1));
        }
        else if (b.substr(1) == a) res = "0";
        else {
          res = "-" + sub(b.substr(1), a);
        }
      }
    }
    cout << "Case #" << i << ": "; // << res << endl;
    if (c < res) {
      cout << "true" << endl;
    }
    else cout << "false" << endl;
  }
  return 0;
}