#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int decReverse(int n, int d) {
  vector<int> v;
  while (n != 0) {
    v.push_back(n % d);
    n /= d;
  }
  int sum = 0;
  for (int i = v.size() - 1; i >= 0; i--)
    sum += v[i] * pow(d, v.size() - 1 - i);
  return sum;
}

vector<int> primes = { 2,3,5,7 };

bool isPrime(int n) {
  if (n == 1) return false;
  bool res = true;
  for (int i = 0; ; i++) {
    if (primes[i] * primes[i] > n) break;
    if (n % primes[i] == 0) {
      res = false;
      break;
    }
  }
  return res;
}

void generatePrimes() {
  for (int i = 11; i < 100000; i++) {
    if (isPrime(i)) primes.push_back(i);
  }
}

int main() {
  int n, d;
  generatePrimes();
  while (cin >> n >> d) {
    if (n < 0) break;
    int rev = decReverse(n, d);
    if (isPrime(n) && isPrime(rev)) {
      cout << "Yes" << endl;
    }
    else {
      cout << "No" << endl;
    }
  }
  return 0;
}