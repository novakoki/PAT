#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
using namespace std;

struct grade {
  string id;
  int math;
  int c;
  int eng;
  double avg;
  int mathRank;
  int cRank;
  int engRank;
  int avgRank;

  grade(string id, int m, int c, int e):id(id), math(m), c(c), eng(e){
    avg = (math + c + eng) / 3.0;
  }
};

bool compm(grade& a, grade& b) {
  return a.math > b.math;
}

bool compc(grade& a, grade& b) {
  return a.c > b.c;
}

bool compe(grade& a, grade& b) {
  return a.eng > b.eng;
}

bool compa(grade& a, grade& b) {
  return a.avg > b.avg;
}

int main() {
  int N, M;
  string id;
  int math, c, eng;
  while (cin >> N >> M) {
    vector<grade> v;
    while (N--) {
      cin >> id >> c >> math >> eng;
      v.push_back(grade(id, math, c, eng));
    }
    sort(v.begin(), v.end(), compa);
    for (int i = 0; i < v.size(); i++) {
      if (i != 0 && v[i].avg == v[i - 1].avg) {
        v[i].avgRank = v[i - 1].avgRank;
      }
      else {
        v[i].avgRank = i + 1;
      }
    }
    sort(v.begin(), v.end(), compc);
    for (int i = 0; i < v.size(); i++) {
      if (i != 0 && v[i].c == v[i - 1].c) {
        v[i].cRank = v[i - 1].cRank;
      }
      else {
        v[i].cRank = i + 1;
      }
    }
    sort(v.begin(), v.end(), compm);
    for (int i = 0; i < v.size(); i++) {
      if (i != 0 && v[i].math == v[i - 1].math) {
        v[i].mathRank = v[i - 1].mathRank;
      }
      else {
        v[i].mathRank = i + 1;
      }
    }
    sort(v.begin(), v.end(), compe);
    for (int i = 0; i < v.size(); i++) {
      if (i != 0 && v[i].eng == v[i - 1].eng) {
        v[i].engRank = v[i - 1].engRank;
      }
      else {
        v[i].engRank = i + 1;
      }
    }
    for (int i = 0; i < M; i++) {
      cin >> id;
      bool exist = false;
      for (auto it = v.begin(); it != v.end(); it++) {
        if (it->id == id) {
          int rank = min(min(it->avgRank, it->cRank), min(it->mathRank, it->engRank));
          cout << rank;
          if (it->avgRank == rank) {
            cout << " A" << endl;
          }
          else if (it->cRank == rank) {
            cout << " C" << endl;
          }
          else if (it->mathRank == rank) {
            cout << " M" << endl;
          }
          else {
            cout << " E" << endl;
          }
          exist = true;
          break;
        }
      }
      if (!exist) {
        cout << "N/A" << endl;
      }
    }
  }
  return 0;
}