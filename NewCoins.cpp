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
class NewCoins {
public:
  int minCoins(vector <int> price) {
    int dp[100001];
    memset(dp, 0, sizeof(dp));

    for (int i=100000; i>=1; i--) {
      for (int j=0; j<price.size(); j++)
        dp[i] += price[j] / i;

      for (int j = i+i; j<=100000; j+=i) {
        int tmp = dp[j];
        for (int k=0; k<price.size(); k++)
          tmp += price[k] % j / i;
        dp[i] = min(dp[i], tmp);
      }
    }

    return dp[1];
  }
   
  // BEGIN CUT HERE
public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {25, 102}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(0, Arg1, minCoins(Arg0)); }
	void test_case_1() { int Arr0[] = {58}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(1, Arg1, minCoins(Arg0)); }
	void test_case_2() { int Arr0[] = {1, 4, 5, 9, 16}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 7; verify_case(2, Arg1, minCoins(Arg0)); }
	void test_case_3() { int Arr0[] = {1, 1, 1, 1, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; verify_case(3, Arg1, minCoins(Arg0)); }
	void test_case_4() { int Arr0[] = {28, 569, 587, 256, 15, 87, 927, 4, 589, 73, 98, 87, 597, 163, 6, 498}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 62; verify_case(4, Arg1, minCoins(Arg0)); }

  // END CUT HERE

};
// BEGIN CUT HERE
int main() {
NewCoins ___test;
___test.run_test(-1);
}
// END CUT HERE 
