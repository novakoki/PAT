#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

void fromDec(int n, int d, vector<int>& v) {
  v.clear();
  if (n == 0) v.push_back(0);
  while (n != 0) {
    v.push_back(n % d);
    n /= d;
  }
}

int main() {
  int n, d;
  vector<int> v;
  while (cin >> n >> d) {
    fromDec(n, d, v);
    int length = v.size()-1;
    bool isPalin = true;
    for (int i = 0; i < (length+1) / 2; i++) {
      if (v[i] != v[length - i]) {
        isPalin = false;
        break;
      }
    }
    if (isPalin) {
      cout << "Yes" << endl;
    }
    else {
      cout << "No" << endl;
    }
    cout << v[length];
    for (int i = length - 1; i >= 0; i--) cout << " " << v[i];
    cout << endl;
  }
  return 0;
}