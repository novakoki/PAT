#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

struct poly {
  int exp;
  double coe;
};

int main() {
  int k, l;
  cin >> k;
  poly* a = new poly[k];
  for (int i = 0; i < k; i++)
    cin >> a[i].exp >> a[i].coe;
  cin >> l;
  poly* b = new poly[l];
  for (int i = 0; i < l; i++)
    cin >> b[i].exp >> b[i].coe;
  int i = 0, j = 0;
  int length = k < l ? k : l;
  vector<poly*> v;
  for (i = 0, j = 0; i < length && j < length;) {
    poly* p = new poly;
    if (a[i].exp == b[j].exp) {
      p->exp = a[i].exp;
      p->coe = a[i].coe + b[j].coe;
      if (p->coe != 0) {
        v.push_back(p);
      }
      ++i; ++j;
    }
    else if (a[i].exp > b[j].exp) {
      v.push_back(&a[i]);
      ++i;
    }
    else {
      v.push_back(&b[j]);
      ++j;
    }
  }
  for (i; i < k; i++) v.push_back(&a[i]);
  for (j; j < l; j++) v.push_back(&b[j]);
  cout << v.size();
  for (int i = 0; i < v.size(); i++) {
    cout << ' ' << v[i]->exp << ' ';
    cout << fixed << setprecision(1) << v[i]->coe;
  }
  cout << endl;
  return 0;
}