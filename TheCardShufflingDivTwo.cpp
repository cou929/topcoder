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
class TheCardShufflingDivTwo {
public:
  int shuffle(int n, int m)
  {
    int ret = 1;

    if (n % 2 == 1)
      n--;

    for (int i=0; i<m; i++)
      {
	if (ret*2 <=n)
	  ret *= 2;
	else
	  ret = ret*2 - n - 1;
      }

    return ret;
  }
   
  // BEGIN CUT HERE
public:
  void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
private:
  template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
  void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
  void test_case_0() { int Arg0 = 5; int Arg1 = 1; int Arg2 = 2; verify_case(0, Arg2, shuffle(Arg0, Arg1)); }
  void test_case_1() { int Arg0 = 5; int Arg1 = 2; int Arg2 = 4; verify_case(1, Arg2, shuffle(Arg0, Arg1)); }
  void test_case_2() { int Arg0 = 2; int Arg1 = 10; int Arg2 = 1; verify_case(2, Arg2, shuffle(Arg0, Arg1)); }
  void test_case_3() { int Arg0 = 1000000; int Arg1 = 999999; int Arg2 = 2; verify_case(3, Arg2, shuffle(Arg0, Arg1)); }

  // END CUT HERE

};
// BEGIN CUT HERE
int main() {
TheCardShufflingDivTwo ___test;
___test.run_test(-1);
}
// END CUT HERE 
