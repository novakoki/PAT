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

struct Record {
  char plate[8];
  int time;
  bool inout;
};

long long str_to_int(char* s) {
  long long res = 0, factor = 1;
  for (int i = 6; i >= 0; i--) {
    if ('0' <= s[i] && s[i] <= '9')
      res += (s[i] - '0') * factor;
    else if ('A' <= s[i] && s[i] <= 'Z')
      res += (s[i] - 'A' + 10) * factor;
    factor *= 36;
  }
  return res;
}

int calc_time(int h, int m, int s) {
  return h * 60 * 60 + m * 60 + s;
}

bool comp(const Record& a, const Record& b) {
  return a.time < b.time;
}

bool comp1(const Record& a, const Record& b) {
  if (strcmp(a.plate, b.plate) == 0)
    return a.time < b.time;
  return strcmp(a.plate, b.plate) < 0;
}

int main() {
  /*freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);*/
  int n, k, h, m, s;
  char inout[4];
  scanf("%d %d", &n, &k);
  vector<Record> records, validRecords;
  records.resize(n);
  for (int i = 0; i < n; i++) {
    scanf("%s %d:%d:%d %s", records[i].plate, &h, &m, &s, inout);
    records[i].inout = inout[0] == 'i';
    records[i].time = calc_time(h, m, s);
  }
  unordered_map<string, int> total_time;
  sort(records.begin(), records.end(), comp1);
  
  int i1 = 0, i2 = 1;
  while (i2 < n) {
    if (strcmp(records[i1].plate, records[i2].plate) == 0 && records[i1].inout && !records[i2].inout) {
      validRecords.push_back(records[i1]);
      validRecords.push_back(records[i2]);
      total_time[records[i1].plate] += records[i2].time - records[i1].time;
      i1 += 2; i2 += 2;
    }
    else {
      i1++; i2++;
    }
  }
  sort(validRecords.begin(), validRecords.end(), comp);
  int index = 0, total = 0;
  while (k--) {
    scanf("%d:%d:%d", &h, &m, &s);
    int t = calc_time(h, m, s);

    for (index; index < validRecords.size() && validRecords[index].time <= t; index++) {
      if (validRecords[index].inout)
        total++;
      else
        total--;
    }
    printf("%d\n", total);
  }
  if (!total_time.empty()) {
    int longest = -1;
    vector<string> v;
    for (auto item : total_time) {
      if (item.second > longest) {
        longest = item.second;
        v.clear();
        v.push_back(item.first);
      }
      else if (item.second == longest) {
        v.push_back(item.first);
      }
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++) {
      printf("%s ", v[i].data());
    }
    printf("%02d:%02d:%02d\n", longest / 3600, longest / 60 % 60, longest % 60);
  }
  return 0;
}