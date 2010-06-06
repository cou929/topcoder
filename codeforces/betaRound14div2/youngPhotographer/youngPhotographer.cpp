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

int solve(vector <int> a, vector <int> b, int x) {
  int ret = 0;
  int left = 0, right = 1000;
  int i;

  for (i=0; i<a.size(); i++) {
    left = max(left, min(a[i], b[i] ));
    right = min(right, max(a[i], b[i] ));
    if (left > right)
      return -1;
  }

  if (left <= x && x <= right)
    return 0;
  else
    return min(abs(x - left), abs(x - right));

  return ret;
}

int main(void) {
  int n, x;
  int a, b;
  vector <int> va, vb;
  int i;

  cin >> n >> x;

  for (i=0; i<n; i++) {
    cin >> a >> b;
    va.push_back(a);
    vb.push_back(b);
  }

  cout << solve(va, vb, x) << endl;

  return 0;
}
