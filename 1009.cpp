#include <iostream>
#include <list>
#include <string>
#include <algorithm>
#include <iomanip>
using namespace std;

struct item {
  int exp;
  double coe;

  item(int e, double c):exp(e), coe(c){}
};

bool operator< (const item& a, const item& b) {
  return a.exp > b.exp;
}

item operator* (const item& a, const item& b) {
  return item(a.exp + b.exp, a.coe*b.coe);
}

struct poly {
  list<item> ls;

  poly() {}

  poly(list<item> l):ls(l) {}

  void operator+=(const item& a) {
    if (ls.empty()) {
      ls.push_back(a);
    }
    else {
      auto it = lower_bound(ls.begin(), ls.end(), a);
      if (it != ls.end() && it->exp == a.exp) {
        it->coe += a.coe;
        if (it->coe == 0) {
          ls.erase(it);
        }
      }
      else {
        ls.insert(it, a);
      }
    }
  }
};

ostream& operator<<(ostream& out, poly p) {
  out << p.ls.size();
  for (auto it = p.ls.begin(); it != p.ls.end(); it++) {
    out << ' ' << it->exp;
    out << fixed << setprecision(1) << ' ' << it->coe;
  }
  out << endl;
  return out;
}

int main() {
  int n;
  int exp;
  double coe;
  cin >> n;
  poly a; poly b; poly res;
  while (n--) {
    cin >> exp >> coe;
    a += item(exp, coe);
  }
  cin >> n;
  while (n--) {
    cin >> exp >> coe;
    b += item(exp, coe);
  }
  for (auto i = a.ls.begin(); i != a.ls.end(); i++) {
    for (auto j = b.ls.begin(); j != b.ls.end(); j++) {
      res += (*i)*(*j);
    }
  }
  cout << res;
  return 0;
}