#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string table[] = { "0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "A", "B", "C" };

int main() {
  int a, b, c;
  while (cin >> a >> b >> c) {
    cout << "#" << table[a / 13] + table[a % 13] << table[b / 13] + table[b % 13]<< table[c / 13] + table[c % 13] <<endl;
  }
  return 0;
}