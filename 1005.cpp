#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
  string s;
  string digit[] = { "zero", "one", "two", "three", "four","five","six","seven","eight","nine" };
  while (cin >> s) {
    int sum = 0;
    for (int i = 0; i < s.length(); i++)
      sum += s[i] - '0';
    stack<string> s;
    while (sum != 0) {
      s.push(digit[sum % 10]);
      sum /= 10;
    }
    if (s.empty()) {
      cout << "zero" << endl;
    }
    else {
      cout << s.top();
      s.pop();
      while (!s.empty()) {
        cout << ' ' << s.top();
        s.pop();
      }
      cout << endl;
    }
  }
  return 0;
}