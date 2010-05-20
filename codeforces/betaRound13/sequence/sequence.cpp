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

long long solve(vector <long long> seq) {
  long long ret = 10000000000000000LL;
  int i, j;
  int n = seq.size();
  vector <long long> nums = seq;
  long long dp[6000][2];

  nums.erase(unique(nums.begin(), nums.end()), nums.end());
  sort(nums.begin(), nums.end());

  for (i=0; i<nums.size(); i++)
    dp[i][0] = abs(nums[i] - seq[0]);

  for (i=1; i<n; i++) {
    long long best = dp[0][(i-1)%2];
    for (j=0; j<nums.size(); j++) {
      best = min(best, dp[j][(i-1)%2]);
      dp[j][i%2] = best + abs(seq[i] - nums[j]);
    }
  }

  for (i=0; i<nums.size(); i++)
    ret = min(ret, dp[i][(n-1)%2]);

  return ret;
}

int main(void) {
  long long n, tmp;
  int i;
  vector <long long> seq;

  cin >> n;

  for (i=0; i<n; i++) {
    cin >> tmp;
    seq.push_back(tmp);
  }

  cout << solve(seq) << endl;

  return 0;
}
