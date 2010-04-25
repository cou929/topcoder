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

int run(string a, string b) {
  int i, j;
  int n = a.size(), m = b.size();
  int dp[n+1][m+1];
  memset(dp, 0, sizeof(dp));
  
  for (i=1; i<=n; i++)
    for (j=1; j<=m; j++)
      dp[i][j] = max(dp[i-1][j-1] + ((a[i-1] == b[j-1]) ? 1 : 0), max(dp[i-1][j], dp[i][j-1]));
  
  return dp[n][m];
}

int main(int argc, char ** argv) {
  string a, b;

  while (cin >> a >> b)
    cout << run(a, b) << endl;

  return 0;
}
