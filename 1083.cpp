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

struct Student {
  char name[11], id[11];
  int grade;

  bool operator< (const Student& rhs) const {
    return grade > rhs.grade;
  }
};

int main() {
  /*freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);*/
  int n, lower, upper;
  while (scanf("%d", &n) != EOF) {
    vector<Student> v;
    v.resize(n);
    for (int i = 0; i < n; i++) {
      scanf("%s %s %d", &v[i].name, &v[i].id, &v[i].grade);
    }
    scanf("%d %d", &lower, &upper);
    sort(v.begin(), v.end());
    bool exist = false;
    for (int i = 0; i < n; i++) {
      if (lower <= v[i].grade && v[i].grade <= upper) {
        exist = true;
        printf("%s %s\n", v[i].name, v[i].id);
      }
    }
    if (!exist)
      printf("NONE\n");
  }

  return 0;
}