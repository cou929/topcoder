#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <utility>
#include <set>
#include <cctype>
#include <queue>
#include <stack>
#include <numeric>

using namespace std;

int main(void) {
  int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  int total = 1;
  int ret = 0;
  int i, j;

  for (i = 1900; i <= 2000; i++) {
    for (j=0; j<12; j++) {
      total += days[j];
      if (j == 2 && i % 4 == 0 && i % 400 != 0)
        total += 1;
      if (total % 7 == 0 && i != 1900) {
        cout << total << endl;
        ret++;
      }
    }
  }

  cout << ret << endl;

  return 1;
}
