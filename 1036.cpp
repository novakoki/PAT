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

struct student {
  string name, id;
  int grade;

  student(){}
  student(string n, string i, int g):name(n), id(i), grade(g){}

  bool operator<(const student& b) const {
    return grade < b.grade;
  }
};

int main() {
  int n;
  cin >> n;
  vector<student> m, f;
  string name, id;
  char sex;
  int grade;
  while (n--) {
    cin >> name >> sex >> id >> grade;
    if (sex == 'M') m.push_back(student(name, id, grade));
    else f.push_back(student(name, id, grade));
  }
  sort(m.begin(), m.end());
  sort(f.begin(), f.end());
  if (f.empty()) cout << "Absent" << endl;
  else cout << f.rbegin()->name << ' ' << f.rbegin()->id << endl;
  if (m.empty()) cout << "Absent" << endl;
  else cout << m.begin()->name << ' ' << m.begin()->id << endl;
  if (!f.empty() && !m.empty()) {
    cout << f.rbegin()->grade - m.begin()->grade << endl;
  }
  else cout << "NA" << endl;
  return 0;
}