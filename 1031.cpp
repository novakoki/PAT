#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  string s;
  while (cin >> s) {
    int n1 = (s.length() + 2) / 3;
    int n2 = s.length() + 2 - 2 * n1;
    for (int i = 0; i < n1-1; i++) {
      cout << s[i] << string(n2-2, ' ') << s[s.length() - 1 - i] << endl;
    }
    for (int i = n1 - 1; i < n1 - 1 + n2; i++) {
      cout << s[i];
    }
    cout << endl;
  }
  return 0;
}