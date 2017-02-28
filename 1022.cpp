#include <iostream>
#include <sstream>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>
#include <iomanip>
#include <map>
#include <string>
#include <cstdio>
#include <cstring>
#include <climits>
using namespace std;

void insert(map<string, list<int> >& m, const string& key, const int& value) {
  if (m.find(key) != m.end()) {
    auto it = lower_bound(m[key].begin(), m[key].end(), value);
    m[key].insert(it, value);
  }
  else {
    list<int> l;
    l.push_back(value);
    m[key] = l;
  }
}

void print(map<string, list<int> >& m, const string& key) {
  if (m.find(key) != m.end()) {
    for (auto it = m[key].begin(); it != m[key].end(); it++)
      printf("%07d\n", *it);
  }
  else cout << "Not Found" << endl;
}

int main() {
  int n;
  int id;
  string title, author, keyword, keywords, publisher, year;
  map<string, list<int> > tm, am, km, pm, ym;
  cin >> n;
  while (n--) {
    scanf("%d\n", &id);
    getline(cin, title);
    getline(cin, author);
    getline(cin, keywords);
    getline(cin, publisher);
    getline(cin, year);
    insert(tm, title, id);
    insert(am, author, id);
    insert(pm, publisher, id);
    insert(ym, year, id);
    stringstream ss(keywords);
    while (ss >> keyword) insert(km, keyword, id);
  }
  cin >> n;
  int type;
  string key;
  while (n--) {
    scanf("%d: ", &type);
    getline(cin, key);
    printf("%d: ", type);
    cout << key << endl;
    switch (type) {
    case 1: print(tm, key); break;
    case 2: print(am, key); break;
    case 3: print(km, key); break;
    case 4: print(pm, key); break;
    case 5: print(ym, key); break;
    }
  }
  return 0;
}