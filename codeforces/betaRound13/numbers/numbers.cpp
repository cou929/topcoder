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

string toStr(int n) {ostringstream ss; ss << n; return ss.str();}

int gcd(const int _a, const int _b) {
  int a = max(_a, _b);
  int b = min(_a, _b);

  while (b) {
    int tmp = a % b;
    a = b;
    b = tmp;
  }

  return a;
}

string solve(int n) {
  string ret;
  int numerator = 0, denominator = n - 1 - 1;
  int i;

  for (i=2; i<n; i++) {
    int tmp = n;
    while (tmp > 0) {
      numerator += tmp % i;
      tmp /= i;
    }
  }

  int g = gcd(numerator, denominator);

  ret = toStr(numerator / g) + '/' + toStr(denominator / g);
  return ret;
}

int main(void) {
  int n;
  
  cin >> n;
  cout << solve(n) << endl;

  return 0;
}
