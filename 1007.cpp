#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
  int n;
  while (cin >> n) {
    int maxsum = 0, sum = 0;
    int* a = new int[n];
    int start = 0, end = n-1;
    bool neg = true;
    int j = 0;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      if (a[i] < 0) {
        if (a[i] + sum >= 0) {
          sum += a[i];
        }
        else {
          sum = 0;
          j = i + 1;
        }
        continue;
      }
      else {
        neg = false;
        sum += a[i];
        if (sum > maxsum) {
          maxsum = sum;
          start = j;
          end = i;
        }
      }
    }
    if (!neg && maxsum == 0) {
      cout << "0 0 0" << endl;
    }
    else {
      cout << maxsum << ' ' << a[start] << ' ' << a[end] << endl;
    }
  }
  return 0;
}