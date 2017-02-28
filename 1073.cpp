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

int main() {
  string s;
  cin >> s;
  char sign = s[0], esign = '+';
  string number = "";
  int exp = 0, dot_index = 0;
  for (int i = 1; i < s.length(); i++) {
    if (s[i] == '.') {
      dot_index = i - 1;
      break;
    }
  }
  for (int i = s.length() - 1; i >= 0; i--) {
    if (s[i] == 'E') {
      esign = s[i + 1];
      exp = stoi(s.substr(i + 2));
      if (esign == '-')
        exp = -exp;
      int j = i-1;
      /*while (j >= 0) {
        if (s[j] == '0') j--;
        else break;
      }*/
      number += s[1];
      number = number + s.substr(dot_index + 2, j - dot_index - 1);
      break;
    }
  }
  if (sign == '-')
    cout << sign;
  if (dot_index + exp <= 0) {
    cout << "0." << string(-(dot_index + exp), '0') << number;
  }
  else if (dot_index + exp < number.length()) {
    for (int i = 0; i < number.length(); i++) {
      if (i == dot_index + exp) {
        cout << '.' << number[i];
      }
      else cout << number[i];
    }
  }
  else {
    cout << number << string(dot_index + exp - number.length(), '0');
  }
  return 0;
}