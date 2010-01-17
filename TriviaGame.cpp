// BEGIN CUT HERE
// END CUT HERE
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
class TriviaGame {
  int MIN;
public:
  int maximumScore(vector <int> points, int tokensNeeded, vector <int> bonuses)
  {
    MIN  = -10000000;
    int ret = MIN;
    int dp[points.size()][tokensNeeded];
    memset(dp, MIN, sizeof(dp));

    if (tokensNeeded == 1)
      {
	dp[0][0] = max(dp[0][0], max(points[0] + bonuses[0], -1 * points[0]));
      }
    else
      {
	dp[0][0] = -1 * points[0];
	dp[0][1] = points[0];
      }

    for (int i=1; i<points.size(); i++)
      {
	for (int j=0; j<tokensNeeded; j++)
	  if (dp[i-1][j] != MIN)
	    {
	      // correct
	      if (j == tokensNeeded-1)
		dp[i][0] = max(dp[i][0], dp[i-1][j] + points[i] + bonuses[i]);
	      else
		dp[i][j+1] = max(dp[i][j+1], dp[i-1][j] + points[i]);

	      // incorrect
	      dp[i][j] = max(dp[i][j], dp[i-1][j] - points[i]);
	    }
      }

    for (int i=0; i<tokensNeeded; i++)
      ret = max(ret, dp[points.size()-1][i]);

    return ret;
  }
   
  // BEGIN CUT HERE
public:
  void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3();  }
private:
  template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
  void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
  void test_case_0() { int Arr0[] = {1, 2, 3, 4, 5, 6}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arr2[] = {4, 4, 4, 4, 4, 4}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 29; verify_case(0, Arg3, maximumScore(Arg0, Arg1, Arg2)); }
  void test_case_1() { int Arr0[] = {1, 2, 3, 4, 5, 6}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arr2[] = {1, 1, 1, 20, 1, 1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 39; verify_case(1, Arg3, maximumScore(Arg0, Arg1, Arg2)); }
  void test_case_2() { int Arr0[] = {150, 20, 30, 40, 50}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arr2[] = {0, 0, 0, 250, 0}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 500; verify_case(2, Arg3, maximumScore(Arg0, Arg1, Arg2)); }
  void test_case_3() { int Arr0[] = {1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arr2[] = {10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 550000; verify_case(3, Arg3, maximumScore(Arg0, Arg1, Arg2)); }

  // END CUT HERE

};
// BEGIN CUT HERE
int main() {
TriviaGame ___test;
___test.run_test(-1);

// {, 1, }
}
// END CUT HERE 
