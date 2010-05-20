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
#include <fstream>
#include <cstring>
#include <numeric>

using namespace std;

string solve(int n, int k) {
  if ((1LL + (long long)k) % (long long)pow(2.0, n) == 0)
    return "ON";

  return "OFF";
}

int main(void) {
  int probNum, i;

  cin >> probNum;

  for (i=0; i<probNum; i++) {
    int n, k;

    cin >> n >> k;

    cout << "Case #" << i + 1 << ": " << solve(n, k) << endl;
  }

  return 0;
}
