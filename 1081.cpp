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

struct Rational {
  long long num, den;
  Rational(long long a, long long b):num(a), den(b) {
    reduce();
  }

  static long long gcd(long long a, long long b) {
    if (b == 0) return a;
    return gcd(b, a % b);
  }

  void reduce() {
    long long a = num, b = den;
    if (num < 0) a = -a;
    long long g = gcd(a, b);
    num /= g;
    den /= g;
  }

  void operator+=(const Rational& rhs) {
    num = num * rhs.den + den * rhs.num;
    den *= rhs.den;
    reduce();
  }

  void print() {
    long long a = num, b = den;
    if (a < 0) a = -a;
    long long integer = a / b;
    long long remain = a % b;

    if (integer != 0) {
            if (num < 0)
                printf("-");
      printf("%lld", integer);
      if (remain != 0)
        printf(" %lld/%lld", remain, b);
        }
        else {
            if (num < 0)
                printf("-");
            if (remain != 0)
                printf("%lld/%lld", remain, b);
            else
                printf("0");
        }
  }
};

int main() {
  /*freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);*/
  int n;
  long long num, den;
  scanf("%d", &n);
    scanf("%lld/%lld", &num, &den);
    auto res = Rational(num, den);
    for (int i = 1; i < n; i++) {
        scanf("%lld/%lld", &num, &den);
        res += Rational(num, den);
    }
    res.print();
  return 0;
}