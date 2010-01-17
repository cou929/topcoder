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
using namespace std;
class NumbersAndMatches {
public:
  long long differentNumbers(long long N, int K) {
    char  match_nums[10][8] = {"1110111", "0010011", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};
    const int MAX_ADD = 200;
    const int MAX_REM = MAX_ADD;
    long long dp[19][MAX_ADD][MAX_REM];
    int digit_num = 0;

    memset(dp, 0, sizeof(dp));
    dp[0][0][0] = 1;

    while (N > 0) {
      int cur_num = N % 10;
      N /= 10;
      digit_num++;

      for (int i=0; i<10; i++) {
        int add_num = 0;
        int remove_num = 0;
        for (int j=0; j<7; j++)
          if (match_nums[cur_num][j] - match_nums[i][j] > 0)
            remove_num++;
          else if (match_nums[cur_num][j] - match_nums[i][j] < 0)
            add_num++;

        for (int j=add_num; j<=K; j++)
          for (int k=remove_num; k<=K; k++)
            dp[digit_num][j][k] += dp[digit_num-1][j-add_num][k-remove_num];
      }
    }

    long long ret = 0;
    for (int i=0; i<=K; i++)
      ret += dp[digit_num][i][i];

    return ret;
  }
   

};


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
