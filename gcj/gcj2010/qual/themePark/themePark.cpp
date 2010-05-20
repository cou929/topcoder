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

int solve(int R, int k, vector <int> groups) {
  int ret = 0;
  int i, j;
  queue <int> q;
  
  for (i=0; i<groups.size(); i++)
    q.push(groups[i]);

  for (i=0; i<R; i++) {
    int cur = 0;
    vector <int> next;
    while (!q.empty()) {
      int tmp = q.front();
      if (cur + tmp > k)
        break;
      cur += tmp;
      q.pop();
      next.push_back(tmp);
    }
    ret += cur;
    for (j=0; j<next.size(); j++)
      q.push(next[j]);
  }

  return ret;
}

int main(void) {
  int probNum, i, j;

  cin >> probNum;

  for (i=0; i<probNum; i++) {
    int R, k, N, g;
    vector <int> groups;
    cin >> R >> k >> N;
    for (j=0; j<N; j++) {
      cin >> g;
      groups.push_back(g);
    }

    cout << "Case #" << i + 1 << ": " << solve(R, k, groups) << endl;
  }

  return 0;
}
