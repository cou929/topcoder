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

map <pair <int, int>, bool> memo;

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

int count(int fa, int fb, int ta, int tb) {
  int ret = 0;

  while (fa != ta || fb != tb) {
    if (fa > fb)
      fa -= fb;
    else
      fb -= fa;
    ret++;
  }

  return ret;
}

bool win(int a, int b) {
  if (memo.find(make_pair(a, b)) != memo.end())
    return memo[make_pair(a, b)];

  if (a == b) {
    memo[make_pair(a, b)] = false;
    return false;
  }

  int g = gcd(a, b);
  int L = min(a, b), R = max(a, b);
  int l = g, r = g;

  if (L == g) {
    memo[make_pair(a, b)] = true;
    return true;
  }

   
  l = L;
  r = R % l;

  int res1 = count(L, R, l, r);
  int res2 = count(l, r, g, g);

  //  cout << res1 << ", " << res2 << endl;

  if (res1 > 1) {
    memo[make_pair(a, b)] = true;
    return true;
  }

  if (res2 > 1 && l != g && res2 % 2 == 0) {
    memo[make_pair(a, b)] = true;
    return true;
  }

  memo[make_pair(a, b)] = false;
  return false;
}

bool win2(int a, int b) {
  if (memo.find(make_pair(a, b)) != memo.end())
    return memo[make_pair(a, b)];

  bool ret = true;

  if (a < b)
    swap(a, b);

  while (1) {
    if (a == b) {
      ret =  !ret;
      break;
    }

    if (a >= 2 * b)
      break;

    a %= b;
    swap(a, b);
    ret = !ret;
  }

  return memo[make_pair(a, b)] = ret;
}

int solve(int a1, int a2, int b1, int b2) {
  int ret = 0;
  int i, j;
  memo.clear();

  for (i=a1; i<=a2; i++)
    for (j=b1; j<=b2; j++)
      if (win2(max(i, j), min(i, j)))
        ret++;

  return ret;
}

int main(void) {
  int probNum, i;

  cin >> probNum;

  for (i=0; i<probNum; i++) {
    int a1, a2, b1, b2;
    cin >> a1 >> a2 >> b1 >> b2;
    cout << "Case #" << i + 1 << ": " << solve(a1, a2, b1, b2) << endl;
  }

  return 0;
}
