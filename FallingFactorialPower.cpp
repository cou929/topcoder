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
// BEGIN CUT HERE
#include "cout.hpp"
// END CUT HERE 
using namespace std;
class FallingFactorialPower {
public:
  double compute(int n, int k) {
    double ret = 1;

    if (k < 0)
      for (int i=1; i<=abs(k); i++)
        ret /= (double)(n + i);
    else if (k > 0)
      for (int i=0; i<k; i++)
        ret *= (double)(n - i);

    return ret;
  }
   
  // BEGIN CUT HERE
public:
	void run_test(int Case) { 
    if ((Case == -1) || (Case == 0)) test_case_0();
    if ((Case == -1) || (Case == 1)) test_case_1();
    if ((Case == -1) || (Case == 2)) test_case_2();
    if ((Case == -1) || (Case == 3)) test_case_3();
    if ((Case == -1) || (Case == 4)) test_case_4();
    if ((Case == -1) || (Case == 5)) test_case_5();
    if ((Case == -1) || (Case == 6)) test_case_6();
  }
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { 
    int Arg0 = 7; 
    int Arg1 = 3; 
    double Arg2 = 210.0; 
    verify_case(0, Arg2, compute(Arg0, Arg1)); }
	void test_case_1() { 
    int Arg0 = 10; 
    int Arg1 = 1; 
    double Arg2 = 10.0; 
    verify_case(1, Arg2, compute(Arg0, Arg1)); }
	void test_case_2() { 
    int Arg0 = 5; 
    int Arg1 = 0; 
    double Arg2 = 1.0; 
    verify_case(2, Arg2, compute(Arg0, Arg1)); }
	void test_case_3() { 
    int Arg0 = 3; 
    int Arg1 = -1; 
    double Arg2 = 0.25; 
    verify_case(3, Arg2, compute(Arg0, Arg1)); }
	void test_case_4() { 
    int Arg0 = 2; 
    int Arg1 = -3; 
    double Arg2 = 0.016666666666666666; 
    verify_case(4, Arg2, compute(Arg0, Arg1)); }
	void test_case_5() { 
    int Arg0 = 7; 
    int Arg1 = 3; 
    double Arg2 = 210.0; 
    verify_case(5, Arg2, compute(Arg0, Arg1)); }
	void test_case_6() { 
    int Arg0 = 7; 
    int Arg1 = 3; 
    double Arg2 = 210.0; 
    verify_case(6, Arg2, compute(Arg0, Arg1)); }

  // END CUT HERE

};
// BEGIN CUT HERE
int main() {
FallingFactorialPower ___test;
___test.run_test(-1);
}
// END CUT HERE 
