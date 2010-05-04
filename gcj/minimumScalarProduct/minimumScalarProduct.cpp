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
#include "cout.hpp"

using namespace std;

int solve(vector <int> a, vector <int> b) {
  int ret = INT_MAX;

  sort(a.begin(), a.end());
  sort(b.begin(), b.end());

  do {
    ret = min(ret, inner_product(a.begin(), a.end(), b.begin(), 0));
  } while (next_permutation(a.begin(), a.end()));

  return ret;
}

map <pair <vector <int>, int>, int> memo;

int search(vector <int> unused, vector <int> &b, int pos) {
  int ret = INT_MAX;
  int i, n = unused.size();

  if (memo.find(make_pair(unused, pos)) != memo.end())
    return memo[make_pair(unused, pos)];

  if (pos >= b.size()) return 0;
  
  for (i=0; i<n; i++) {
    vector <int> tmp = unused;
    tmp.erase(tmp.begin() + i);
    ret = min(ret, unused[i] * b[pos] + search(tmp, b, pos + 1));
  }

  return memo[make_pair(unused, pos)] = ret;
}

int solve2(vector <int> a, vector <int> b) {
  memo.clear();
  return search(a, b, 0);
}

long long solve3(vector <int> a, vector <int> b) {
  long long ret = 0;
  int i, n = a.size();

  sort(a.begin(), a.end());
  sort(b.begin(), b.end());

  for (i=0; i<n; i++)
    ret += (long long)a[i] * (long long)b[b.size() - 1 - i];

  return ret;
}

int main(void) {
  int probNum, i, j, k, n;

  cin >> probNum;

  for (i=0; i<probNum; i++) {
    vector <int> a, b;
    cin >> n;
    for (j=0; j<n; j++) {
      cin >> k;
      a.push_back(k);
    }
    for (j=0; j<n; j++) {
      cin >> k;
      b.push_back(k);
    }
    cout << "Case #" << i + 1 << ": " << solve3(a, b) << endl;
  }

  return 0;
}
