#include <iostream>
using namespace std;

int main() {
  int total, n;
  int cur = 0, sum = 0;
  while (cin >> total) {
    while(total--) {
      cin >> n;
      if (n - cur > 0) {
        sum += 6 * (n - cur);
      }
      else if (n - cur < 0) {
        sum += 4 * (cur - n);
      }
      sum += 5;
      cur = n;
    }
    cout << sum << endl;
  }
  return 0;
}