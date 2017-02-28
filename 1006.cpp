#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct record {
  string id;
  string signin;
  string signout;

  record (string a, string b, string c):id(a),signin(b),signout(c){}
};

bool compSignin(record& a, record& b) {
  return a.signin < b.signin;
}

bool compSignout(record& a, record& b) {
  return a.signout > b.signout;
}

int main() {
  int n;
  string id, signin, signout;
  vector<record> v;
  while (cin >> n) {
    v.clear();
    for (int i = 0; i < n; i++) {
      cin >> id >> signin >> signout;
      v.push_back(record(id, signin, signout));
    }
    sort(v.begin(), v.end(), compSignin);
    cout << v[0].id << ' ';
    sort(v.begin(), v.end(), compSignout);
    cout << v[0].id << endl;
  }
  return 0;
}