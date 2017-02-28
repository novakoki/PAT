#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>
#include <iomanip>
#include <map>
#include <string>
#include <cstdio>
using namespace std;

struct Rank {
  string id;
  int final_rank;
  int local_rank;
  int location;
  int score;

  Rank(string id, int l, int s):id(id), location(l), score(s){}
  Rank(){}
};

bool comp(Rank& a, Rank& b) {
  if (a.score != b.score)
  return a.score > b.score;
  else return a.id < b.id;
}

int main() {
  int n, k, score;
  string id;
  while (cin >> n) {
    vector<Rank> final;
    for (int i = 0; i < n; i++) {
      vector<Rank> local;
      cin >> k;
      for (int j = 0; j < k;j++) {
        cin >> id >> score;
        local.push_back(Rank(id, i+1, score));
      }
      sort(local.begin(), local.end(), comp);
      for (int j = 0; j < local.size(); j++) {
        if (j != 0 && local[j].score == local[j - 1].score) {
          local[j].local_rank = local[j-1].local_rank;
        }
        else {
          local[j].local_rank = j + 1;
        }
        final.push_back(local[j]);
      }
    }
    sort(final.begin(), final.end(), comp);
    cout << final.size() << endl;
    for (int j = 0; j < final.size(); j++) {
      if (j != 0 && final[j].score == final[j - 1].score) {
        final[j].final_rank = final[j - 1].final_rank;
      }
      else final[j].final_rank = j + 1;
      cout << final[j].id << ' ' << final[j].final_rank << ' ' << final[j].location << ' ' << final[j].local_rank << endl;
    }
  }
  return 0;
}