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
  int N;
  string user, pass;
  vector<pair<string, string> > m;
  bool dirty = false;
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> user >> pass;
    bool modified = false;
    for (auto it = pass.begin(); it != pass.end(); it++) {
      if (*it == '1') {
        *it = '@';
        modified = true;
      }
      else if (*it == '0') {
        *it = '%';
        modified = true;
      }
      else if (*it == 'l') {
        *it = 'L';
        modified = true;
      }
      else if (*it == 'O') {
        *it = 'o';
        modified = true;
      }
    }
    if (modified) {
      m.push_back(make_pair(user, pass));
      dirty = true;
    }
  }
  if (dirty) {
    cout << m.size() << endl;
    for (auto it = m.begin(); it != m.end(); it++) {
      cout << it->first << ' ' << it->second << endl;
    }
  }
  else {
    if (N == 1) {
      cout << "There is 1 account and no account is modified" << endl;
    }
    else {
      cout << "There are " << N << " accounts and no account is modified" << endl;
    }
  }
  return 0;
}