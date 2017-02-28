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

struct User {
  bool not_shown;
  int uid, total, perfect, rank;
  vector<int> problems;

  User() {
    total = 0;
    perfect = 0;
    not_shown = true;
  }

  bool operator< (const User& rhs) const {
    if (total == rhs.total) {
      if (perfect == rhs.perfect)
        if (not_shown == rhs.not_shown)
          return uid < rhs.uid;
        else return not_shown < rhs.not_shown;
      else return perfect > rhs.perfect;
    }
    else return total > rhs.total;
  }
};

int main() {
  /*freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);*/
  int n, k, m;
  scanf("%d%d%d", &n, &k, &m);
  vector<int> scores(k+1, -2);

  vector<User> users;
  users.resize(n+1);
  for (int i = 1; i <= n; i++) {
    users[i].problems = scores;
  }

  for (int i = 1; i <= k; i++)
    scanf("%d", &scores[i]);
  int uid, pid, gain;
  while (m--) {
    scanf("%d%d%d", &uid, &pid, &gain);
    users[uid].uid = uid;
    users[uid].problems[pid] = max(gain, users[uid].problems[pid]);
  }

  for (int j = 1; j <= n; j++) {
    for (int i = 1; i <= k; i++) {
      if (users[j].problems[i] != -2 && users[j].problems[i] != -1) {
        users[j].not_shown = false;
        if (users[j].problems[i] == scores[i])
          users[j].perfect++;
        users[j].total += users[j].problems[i];
      }
    }
  }

  sort(users.begin() + 1, users.end());

  for (int i = 1; i <= n; i++) {
    if (!users[i].not_shown) {
      if (i != 1 && users[i].total == users[i - 1].total)
        users[i].rank = users[i - 1].rank;
      else users[i].rank = i;
      printf("%d %05d %d", users[i].rank, users[i].uid, users[i].total);
      for (int j = 1; j <= k; j++) {
        if (users[i].problems[j] == -2)
          printf(" -");
        else if (users[i].problems[j] == -1)
          printf(" 0");
        else
          printf(" %d", users[i].problems[j]);
      }
      printf("\n");
    }
    else break;
  }
  return 0;
}