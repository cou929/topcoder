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
class SalaryCalculator {
public:
  double calcHours(int P1, int P2, int salary)
  {
    double ret = 0;
    if (salary <= P1 * 200)
      {
	ret = (double)salary/P1;
      }
    else
      {
	double diff = salary - 200*P1;
	ret = 200 + diff/P2;
      }
    return ret;
  }
   
  // BEGIN CUT HERE
public:
  void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
private:
  template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
  void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
  void test_case_0() { int Arg0 = 10; int Arg1 = 15; int Arg2 = 1000; double Arg3 = 100.0; verify_case(0, Arg3, calcHours(Arg0, Arg1, Arg2)); }
  void test_case_1() { int Arg0 = 10; int Arg1 = 15; int Arg2 = 3000; double Arg3 = 266.6666666666667; verify_case(1, Arg3, calcHours(Arg0, Arg1, Arg2)); }
  void test_case_2() { int Arg0 = 100; int Arg1 = 1; int Arg2 = 1000000; double Arg3 = 980200.0; verify_case(2, Arg3, calcHours(Arg0, Arg1, Arg2)); }
  void test_case_3() { int Arg0 = 17; int Arg1 = 23; int Arg2 = 973546; double Arg3 = 42380.260869565216; verify_case(3, Arg3, calcHours(Arg0, Arg1, Arg2)); }
  void test_case_4() { int Arg0 = 82; int Arg1 = 8; int Arg2 = 12140; double Arg3 = 148.0487804878049; verify_case(4, Arg3, calcHours(Arg0, Arg1, Arg2)); }

  // END CUT HERE

};
// BEGIN CUT HERE
int main() {
SalaryCalculator ___test;
___test.run_test(-1);
}
// END CUT HERE 
