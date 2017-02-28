#include <iostream>
#include <iomanip>
using namespace std;

int main() {
  char result[] = { 'W', 'T', 'L' };
  double n, product = 1;
  for (int i = 0; i < 3; i++) {
    double res = 0;
    int index = 0;
    for (int j = 0; j < 3; j++) {
      cin >> n;
      if (n > res) {
        res = n;
        index = j;
      }
    }
    product *= res;
    cout << result[index] << ' ';
  }
  cout<< fixed << setprecision(2) << (product * 0.65 - 1) * 2 << endl;
  return 0;
}