#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <cstdio>
using namespace std;

int count(int n) {
  int sum = 0;
  while (n != 0) {
    sum += n % 10;
    n /= 10;
  }
  return sum;
}

int main () {
  int n, num;
  scanf("%d", &n);
  set<int> s;
  while (n--) {
    scanf("%d", &num);
    s.insert(count(num));
  }
  printf("%d\n", s.size());
  for (auto it = s.begin(); it != s.end(); it++) {
    if (it != s.begin())
      printf(" ");
    printf("%d", *it);
  }
  printf("\n");
  return 0;
}