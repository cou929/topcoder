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
class PlanarGraphShop {
public:
  int bestCount(int N) {
    int ret = 0;
    vector <int> dp(N+1, INT_MAX);
    dp[0] = 0;
    
    for (int nodes=1; nodes<=36; nodes++) {
      int limit = 3*nodes - 6;
      if (nodes == 1) limit = 0;
      if (nodes == 2) limit = 1;
      for (int edges=0; edges<=limit; edges++) {
        int cost = (int)pow((double)nodes, 3) + (int)pow((double)edges, 2);
        for (int i=0; i<=N-cost; i++)
          dp[i+cost] = min(dp[i] + 1, dp[i+cost]);
      }
    }

    ret = dp[N];
    return ret;
  }
   
  // BEGIN CUT HERE
public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3();if ((Case == -1) || (Case == 4)) test_case_4(); }
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 36; int Arg1 = 1; verify_case(0, Arg1, bestCount(Arg0)); }
	void test_case_1() { int Arg0 = 7; int Arg1 = 7; verify_case(1, Arg1, bestCount(Arg0)); }
	void test_case_2() { int Arg0 = 72; int Arg1 = 2; verify_case(2, Arg1, bestCount(Arg0)); }
	void test_case_3() { int Arg0 = 50000; int Arg1 = 3; verify_case(3, Arg1, bestCount(Arg0)); }
	void test_case_4() { int Arg0 = 100; int Arg1 = 1; verify_case(4, Arg1, bestCount(Arg0)); }

  // END CUT HERE

};
// BEGIN CUT HERE
int main() {
PlanarGraphShop ___test;
___test.run_test(-1);
}
// END CUT HERE 
