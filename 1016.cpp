#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <iomanip>
#include <map>
#include <string>
#include <cstdio>
using namespace std;

int toll[24];

pair<int, int> calc(string start, string end) {
  int startDay = (start[3] - '0') * 10 + start[4] - '0';
  int startHour = (start[6] - '0') * 10 + start[7] - '0';
  int startMin = (start[9] - '0') * 10 + start[10] - '0';

  int endDay = (end[3] - '0') * 10 + end[4] - '0';
  int endHour = (end[6] - '0') * 10 + end[7] - '0';
  int endMin = (end[9] - '0') * 10 + end[10] - '0';

  int d = (endDay - startDay) * 24 * 60 + (endHour - startHour) * 60 + endMin - startMin;
  int sum = 0;
  startHour = startDay * 24 + startHour;
  endHour = endDay * 24 + endHour;
  if (startHour != endHour) {
    sum += (60 - startMin) * toll[startHour % 24];
    sum += endMin * toll[endHour % 24];
    for (int i = startHour+1; i < endHour; i++) {
      sum += 60 * toll[i % 24];
    }
  }
  else {
    sum += (endMin - startMin) * toll[startHour % 24];
  }

  return make_pair(d, sum);
}

int main() {
  for (int i = 0; i < 24; i++)
    cin >> toll[i];
  int n;
  string name, datetime, type;
  cin >> n;
  map<string, map<string, string> > records;
  while (n--) {
    cin >> name >> datetime >> type;
    if (records.find(name) != records.end()) {
      records[name][datetime] = type;
    }
    else {
      map<string, string> m;
      m[datetime] = type;
      records[name] = m;
    }
  }
  string month = datetime.substr(0, 2);
  for (auto i = records.begin(); i != records.end(); i++) {
    bool fit = false;
    int sum = 0;
    string startTime = "", endTime = "";
    for (auto j = i->second.begin(); j != i->second.end(); j++) {
      if (j->second == "on-line") {
        startTime = j->first;
        j++;
        if (j == i->second.end()) break;
        if (j->second != "off-line") {
          j--; continue;
        }
        endTime = j->first;
        pair<int, int> p = calc(startTime, endTime);
        sum += p.second;
        if (!fit) {
          cout << i->first << ' ' << month << endl;
        }
        cout << startTime.substr(3) << ' ' << endTime.substr(3) << ' ' << p.first << ' ';
        printf("$%d.%02d\n", p.second / 100, p.second % 100);
        fit = true;
      }
    }
    if (sum != 0)
      printf("Total amount: $%d.%02d\n", sum / 100, sum % 100);
  }
  return 0;
}