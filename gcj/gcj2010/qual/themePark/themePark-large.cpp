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

bool ok(vector <long long> &visited, long long pos) {
  int i;
  for (i=0; i<pos; i++)
    if (visited[visited.size()-1 - i] != visited[visited.size()-1 - pos - i])
      return false;
  return true;
}

long long solve(long long R, long long k, vector <long long> groups) {
  long long ret = 0;
  int i, j;
  vector <long long> visited;
  vector <long long> profits;
  long long amount = 0;
  long long top = 0;
  long long pos = -1;
  
  for (i=0; i<R; i++) {
    long long cur = 0;
    vector <long long> next;

    visited.push_back(top);

    for (j=0; j<groups.size(); j++) {
      if (cur + groups[top] > k)
        break;
      cur += groups[top];
      top = (top + 1) % groups.size();
    }

    if (top == groups.size())
      top = (top + 1) % groups.size();

    amount += cur;
    profits.push_back(cur);

    pos = -1;
    for (j=1; j<=visited.size()/2; j++)
      if (ok(visited, j)) {
        pos = j;
        break;
      }
    if (pos != -1)
      break;
  }

  ret = amount;
  if (pos != -1) {
    ret = 0;
    long long p = 0;
    for (i=0; i<pos; i++)
      p += profits[visited.size()-1-i];
    long long pre = visited.size() - pos*2;
    for (i=0; i<pre; i++)
      ret += profits[i];
    ret += (R - pre) / pos * p;
    for (i=0; i<(R - pre)%pos; i++)
      ret += profits[pre + i];
  }
  
  return ret;
}

int main(void) {
  int probNum, i, j;

  cin >> probNum;

  for (i=0; i<probNum; i++) {
    long long R, k, N, g;
    vector <long long> groups;
    cin >> R >> k >> N;
    for (j=0; j<N; j++) {
      cin >> g;
      groups.push_back(g);
    }

    cout << "Case #" << i + 1 << ": " << solve(R, k, groups) << endl;
  }

  return 0;
}
