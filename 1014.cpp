#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <iomanip>
using namespace std;

int main() {
  int N, M, C, Q;
  while (cin >> N >> M >> C >> Q) {
    vector<int> v;
    int t;
    int* res = new int[C + 1];
    for (int i = 0; i < C; i++) {
      cin >> t;
      v.push_back(t);
    }
    vector<int> sum(N, 0);
    vector<queue<int> > q(N);
    int i = 0;
    for (i = 0; i < N*M; i++) {
      if (i >= C) break;
      res[i + 1] = sum[i%N];
      sum[i % N] += v[i];
      q[i % N].push(sum[i % N]);
    }
    for (int T = 0; ; T++) {
      if (i >= C) break;
      for (int j = 0; j < q.size(); j++) {
        if (i >= C) break;
        if (q[j].front() == T) {
          q[j].pop();
          res[i + 1] = sum[j];
          sum[j] += v[i];
          q[j].push(sum[j]);
          i++;
        }
      }
    }
    /*for (int i = 0; i < C; i++)
      cout << res[i + 1] << endl;*/
    while (Q--) {
      cin >> t;
      if (res[t] < 540) {
        int n = res[t] + 480 + v[t-1];
        int h = n / 60;
        int m = n % 60;
        if (h < 10) {
          cout << 0 << h;
        }
        else cout << h;
        cout << ':';
        if (m < 10) {
          cout << 0 << m;
        }
        else cout << m;
        cout << endl;
      }
      else cout << "Sorry" << endl;
    }
  }
  return 0;
}