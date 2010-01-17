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
using namespace std;
class PyramidOfCubes {
public:
  double surface(int K)
  {
  }
   
  // BEGIN CUT HERE
public:
  void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
private:
  template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
  void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
  void test_case_0() { int Arg0 = 14; double Arg1 = 42.0; verify_case(0, Arg1, surface(Arg0)); }
  void test_case_1() { int Arg0 = 21; double Arg1 = 58.0; verify_case(1, Arg1, surface(Arg0)); }
  void test_case_2() { int Arg0 = 1; double Arg1 = 6.0; verify_case(2, Arg1, surface(Arg0)); }
  void test_case_3() { int Arg0 = 2; double Arg1 = 10.0; verify_case(3, Arg1, surface(Arg0)); }
  void test_case_4() { int Arg0 = 451234; double Arg1 = 47498.0; verify_case(4, Arg1, surface(Arg0)); }

  // END CUT HERE

};
// BEGIN CUT HERE
int main() {
PyramidOfCubes ___test;
___test.run_test(-1);
}
// END CUT HERE 
