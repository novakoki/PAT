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
#include <cstdio>
#include <cstring>
#include <climits>
using namespace std;

int main() {
  int NC, NP;
  vector<long long> cv, pv;
  cin >> NC;
  cv.resize(NC);
  for (int i = 0; i < NC; i++)
    scanf("%lld", &cv[i]);
  cin >> NP;
  pv.resize(NP);
  for (int i = 0; i < NP; i++)
    scanf("%lld", &pv[i]);
  long long sum = 0;
  sort(cv.begin(), cv.end());
  sort(pv.begin(), pv.end());
  for (int i = 0; i < NC && i < NP && cv[i] < 0 && pv[i] < 0; i++)
    sum += cv[i] * pv[i];
  for (int i = NC - 1, j = NP - 1; i >= 0 && j >= 0 && cv[i] > 0 && pv[i] > 0; i--, j--)
    sum += cv[i] * pv[j];
  printf("%lld\n", sum);
  return 0;
}