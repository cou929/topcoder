// BEGIN CUT HERE
// END CUT HERE
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>

using namespace std;

class SumOfPowers {
public:
  int value(int n, int k)
  {
    unsigned int i;

    for (i=0; )

  }

   
  // BEGIN CUT HERE
public:
  void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
private:
  template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
  void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
  void test_case_0() { int Arg0 = 5; int Arg1 = 1; int Arg2 = 15; verify_case(0, Arg2, value(Arg0, Arg1)); }
  void test_case_1() { int Arg0 = 4; int Arg1 = 2; int Arg2 = 30; verify_case(1, Arg2, value(Arg0, Arg1)); }
  void test_case_2() { int Arg0 = 13; int Arg1 = 5; int Arg2 = 1002001; verify_case(2, Arg2, value(Arg0, Arg1)); }
  void test_case_3() { int Arg0 = 123456789; int Arg1 = 1; int Arg2 = 383478132; verify_case(3, Arg2, value(Arg0, Arg1)); }

  // END CUT HERE

};

// BEGIN CUT HERE
int main() {
SumOfPowers ___test;
___test.run_test(-1);
}
// END CUT HERE 
