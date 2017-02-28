#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <cstdio>
#include <algorithm>
using namespace std;

int main () {
  int n, m;
  vector<int> couple(100000, -1);
  vector<bool> is_party(100000, false);
  scanf("%d", &n);
  int a, b;
  while (n--) {
    scanf("%d %d", &a, &b);
    couple[a] = b;
    couple[b] = a;
  }
  scanf("%d", &m);
  vector<int> v, data;
  while (m--) {
    scanf("%d", &a);
    data.push_back(a);
    is_party[a] = true;
  }
  for (int i = 0; i < data.size(); i++) {
    if (couple[data[i]] == -1 || !is_party[couple[data[i]]]){
      v.push_back(data[i]);
    }
  }
  printf("%d\n", v.size());
  sort(v.begin(), v.end());
  for (int i = 0; i < v.size(); i++) {
    if (i != 0)
      printf(" ");
    printf("%05d", v[i]);
  }
  return 0;
}