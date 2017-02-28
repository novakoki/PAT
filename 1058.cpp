#include <iostream>
#include <sstream>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>
#include <iomanip>
#include <map>
#include <unordered_map>
#include <string>
#include <set>
#include <stack>
#include <cstdio>
#include <cstring>
#include <climits>
using namespace std;

int main() {
  int a1, a2, a3, b1, b2, b3;
  scanf("%d.%d.%d %d.%d.%d", &a1, &a2, &a3, &b1, &b2, &b3);
  int sum = a3 + b3, carry = 0;
  int c3 = sum % 29;
  carry = sum / 29;
  sum = a2 + b2 + carry;
  int c2 = sum % 17;
  carry = sum / 17;
  sum = a1 + b1 + carry;
  int c1 = sum;
  printf("%d.%d.%d", c1, c2, c3);
  return 0;
}