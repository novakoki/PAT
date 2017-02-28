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

int main() {
  /*freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);*/
  string s;
  while (cin >> s) {
    reverse(s.begin(), s.end());
    bool b = false;
    stack<string> st;
    string pos[] = { "", " Shi", " Bai", " Qian" };
    string num[] = { "ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu" };
    for (int i = 0; i < s.length(); i++) {
      if (s[i] == '-') {
        st.push("Fu");
      }
      else {
        if (i == 4) {
          st.push("Wan");
          b = false;
        }
        if (i == 8) {
          st.push("Yi");
          b = false;
        }

        if (s[i] == '0') {
          if (b) {
            st.push(num[0]);
            b = false;
          }
        }
        else {
          b = true;  
          st.push(num[s[i] - '0'] + pos[i % 4]);
        }
      }
    }
    if (st.empty())
      cout << "ling" << endl;
    else {
      cout << st.top();
      st.pop();
      while (!st.empty()) {
        cout << " " << st.top();
        st.pop();
      }
      cout << endl;
    }
  }
  return 0;
}