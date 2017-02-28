#include <iostream>
#include <string>
using namespace std;

int main() {
  int a, b;
  while (cin >> a >> b) {
    int sum = a + b;
    int res = sum;
    int n, count = 1;
    if (res == 0) {
      cout << 0 << endl;
    }
    else {
      string s = "";
      if (res < 0) {
        res = -res;
      }
      while (res != 0) {
        n = res % 10;
        s += n + '0';
        if (count % 3 == 0) {
          s += ',';
        }
        res /= 10;
        ++count;
      }
      int length = s.length() - 1;
      if (s[length] == ',') --length;
      if (sum < 0) cout << '-';
      for (int i = length; i >= 0; i--)
        cout << s[i];
      cout << endl;
    }
  }
  return 0;
}