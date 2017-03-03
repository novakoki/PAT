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
#include <memory>
#include <valarray>
#include <numeric>
#include <functional>
using namespace std;

struct Person {
  char name[9];
  int height;

  bool operator< (const Person& p) {
    if (height == p.height)
      return strcmp(name, p.name) > 0;
    else
      return height < p.height;
  }
};

int main() {
#ifdef _DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int n, row;
  scanf("%d %d", &n, &row);
  vector<Person> people;
  people.resize(n);
  for (int i = 0; i < n; i++)
    scanf("%s %d", people[i].name, &people[i].height);
  sort(people.begin(), people.end());
  int col = n / row;
  int cols = n - (row - 1) * col, highest = cols / 2,
  left = highest - 1, right = highest + 1, cnt = n - 1;
  vector<char*> tmp(cols, NULL);
  tmp[highest] = people[cnt--].name;
  while (!(left < 0 && right >= cols)) {
    if (left >= 0)
      tmp[left--] = people[cnt--].name;
    if (right < cols)
      tmp[right++] = people[cnt--].name;
  }
  for (int i = 0; i < cols; i++) {
    if (i != 0)
      printf(" ");
    printf("%s", tmp[i]);
  }
  printf("\n");
  cols = col, highest = cols / 2;
  for (int i = 0; i < row - 1; i++) {
    left = highest - 1, right = highest + 1;
    tmp[highest] = people[cnt--].name;
    while (!(left < 0 && right >= cols)) {
      if (left >= 0)
        tmp[left--] = people[cnt--].name;
      if (right < cols)
        tmp[right++] = people[cnt--].name;
    }
    for (int i = 0; i < cols; i++) {
      if (i != 0)
        printf(" ");
      printf("%s", tmp[i]);
    }
    printf("\n");
  }
  return 0;
}