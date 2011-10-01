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

int solve(void) {
  int ret = 0;
  int M = 0, C = 0, W = 0;
  vector <pair <int, int> > cuts;
  int maxi = 0;
  int i, j, n;

  cin >> M >> C >> W;

  for (i=0; i<C; i++) {
    int A = 0, B = 0;
    cin >> A >> B;
    cuts.push_back(make_pair(A, B));
    maxi = max(maxi, A + B - 1);
  }

  n = cuts.size();

  for (i=1; i<=M; i++) {
    int cur_pos = i;

    if (i > maxi) {
      if (i == W) {
        ret = i;
        break;
      }
      continue;
    }
    
    // if (i % 100000 == 0)
    //   cout << i << endl;

    for (j=0; j<n; j++) {
      if (cuts[j].first + cuts[j].second - 1 < cur_pos)
        continue;

      if (cuts[j].first <= cur_pos)
        cur_pos = cur_pos - cuts[j].first + 1;
      else
        cur_pos += cuts[j].second;
    }

    if (cur_pos == W) {
      ret = i;
      break;
    }
  }

  return ret;
}

int main(void) {
  int probNum, i;

  cin >> probNum;

  for (i=0; i<probNum; i++) {
    cout << "Case #" << i + 1 << ": " << solve() << endl;
  }

  return 0;
}
