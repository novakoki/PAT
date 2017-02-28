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

struct Cake {
  float amount, price;

  bool operator<(const Cake& rhs) const {
    return price / amount > rhs.price / rhs.amount;
  }
};

int main() {
  int n, demand;
  scanf("%d %d", &n, &demand);
  vector<Cake> v;
  v.resize(n);
  for (int i = 0; i < n; i++)
    scanf("%f", &v[i].amount);
  for (int i = 0; i < n; i++)
    scanf("%f", &v[i].price);
  sort(v.begin(), v.end());
  float res = 0.0;
  for (auto item : v) {
    if (item.amount <= demand) {
      res += item.price;
      demand -= item.amount;
    }
    else {
      res += item.price / item.amount * demand;
      break;
    }
  }
  printf("%.2f", res);
  return 0;
}