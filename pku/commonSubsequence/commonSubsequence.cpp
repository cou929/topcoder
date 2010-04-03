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

using namespace std;

int run(string seq1, string seq2) {
  int i, j;
  int n = seq1.size(), m = seq2.size();
  int dp[n+1][m+1];
  memset(dp, 0, sizeof(dp));

  for (i=1; i<=n; i++)
    for (j=1; j<=m; j++) {
      int cur = dp[i-1][j-1];
      if (seq1[i-1] == seq2[j-1]) cur++;
      cur = max(cur, max(dp[i-1][j], dp[i][j-1]));
      dp[i][j] = cur;
    }

  return dp[n][m];
}

int main(int argc, char ** argv) {
  string seq1, seq2;

  while (cin >> seq1 >> seq2)
    cout << run(seq1, seq2) << endl;

  return 0;
}
