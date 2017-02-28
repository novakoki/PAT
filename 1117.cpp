#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  int n;
  int* a;
  int ans;
  while (cin >> n) {
    ans = 0;
    a = new int[n];
    for (int i = 0; i < n; i++)
      cin >> a[i];
    sort(a, a + n);
    for (int i = 0; i < n; i++) {
      if (a[i] > n - i) {
        ans = n - i;
        break;
      }
    }
    delete[] a;
    cout << ans << endl;
  }
  return 0;
}