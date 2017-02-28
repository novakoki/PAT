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
  bool inf = false;

  Rational(long long a, long b) :num(a), den(b) {
    if (b == 0)
      inf = true;
    else if (a != 0)
      reduce();
  }

  long long gcd(long long a, long long b) {
    return b == 0 ? a : gcd(b, a % b);
  }

  void reduce() {
    int g = gcd(abs(num), abs(den));
    num /= g; den /= g;
    if (den < 0)
      num = -num, den = -den;
  }

  void print() {
    if (inf) {
      printf("Inf");
    }
    else {
      if (num == 0)
        printf("0");
      else {
        int integer = num / den, remain = num % den;
        if (num < 0)
          printf("(");
        if (integer != 0)
          printf("%d", integer);
        if (integer != 0 && remain != 0)
          printf(" ");
        if (remain != 0) {
          if (integer < 0)
            printf("%d", -remain);
          else
            printf("%d", remain);
          printf("/%d", den);
        }
        if (num < 0)
          printf(")");
      }
    }
  }
};

Rational operator+ (const Rational& a, const Rational& b) {
  return Rational(a.num*b.den + a.den*b.num, a.den*b.den);
}

Rational operator- (const Rational& a, const Rational& b) {
  return Rational(a.num*b.den - a.den*b.num, a.den*b.den);
}

Rational operator* (const Rational& a, const Rational& b) {
  return Rational(a.num*b.num, a.den*b.den);
}

Rational operator/ (const Rational& a, const Rational& b) {
  return Rational(a.num*b.den, a.den*b.num);
}

int main() {
  /*freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);*/
  int a, b, c, d;
  while (scanf("%lld/%lld %lld/%lld", &a, &b, &c, &d) != EOF) {
    Rational r1(a, b), r2(c, d);

    r1.print();
    printf(" + ");
    r2.print();
    printf(" = ");
    (r1 + r2).print();
    printf("\n");

    r1.print();
    printf(" - ");
    r2.print();
    printf(" = ");
    (r1 - r2).print();
    printf("\n");

    r1.print();
    printf(" * ");
    r2.print();
    printf(" = ");
    (r1 * r2).print();
    printf("\n");

    r1.print();
    printf(" / ");
    r2.print();
    printf(" = ");
    (r1 / r2).print();
    printf("\n");
  }
  return 0;
}