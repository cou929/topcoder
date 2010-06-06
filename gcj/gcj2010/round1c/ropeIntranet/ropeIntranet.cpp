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

int solve(vector <int> a, vector <int> b) {
  int ret = 0;
  int n = a.size();
  int i, j;

  for (i=0; i<n; i++)
    for (j=i+1; j<n; j++) {
      if ((a[i] < a[j] && b[i] > b[j]) ||
          (a[i] > a[j] && b[i] < b[j]))
        ret++;
    }

  return ret;
}

int main(void) {
  int probNum, i, j, aa, bb;

  cin >> probNum;

  for (i=0; i<probNum; i++) {
    int N;
    vector <int> a, b;
    cin >> N;

    for (j=0; j<N; j++) {
      cin >> aa >> bb;
      a.push_back(aa);
      b.push_back(bb);
    }

    cout << "Case #" << i + 1 << ": " << solve(a, b) << endl;
  }

  return 0;
}
