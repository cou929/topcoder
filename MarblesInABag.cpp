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
class MarblesInABag {
public:
  double m[2001][4001]; // modified

  double r(int red, int blue)
  {
    double ret = 0;

    if (red > 2000 || red>blue)  // modified
      return 0;

    if (m[red][blue] != -1)
      return m[red][blue];

    ret += ((double)blue/(red+blue)) * r(red, blue-2);
    if (red >= 1)
      ret += ((double)red/(red+blue)) * r(red-1, blue-1);

    m[red][blue] = ret;

    return ret;
  }

  double getProbability(int redCount, int blueCount)
  {
    for (int i=0; i<2001; i++)
      for (int j=0; j<4001; j++)
	m[i][j] = -1;

    m[0][1] = 1;

    return r(redCount, blueCount);
  }
   
  // BEGIN CUT HERE
public:
  void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
private:
  template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
  void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
  void test_case_0() { int Arg0 = 1; int Arg1 = 2; double Arg2 = 0.3333333333333333; verify_case(0, Arg2, getProbability(Arg0, Arg1)); }
  void test_case_1() { int Arg0 = 2; int Arg1 = 3; double Arg2 = 0.13333333333333333; verify_case(1, Arg2, getProbability(Arg0, Arg1)); }
  void test_case_2() { int Arg0 = 2; int Arg1 = 5; double Arg2 = 0.22857142857142856; verify_case(2, Arg2, getProbability(Arg0, Arg1)); }
  void test_case_3() { int Arg0 = 11; int Arg1 = 6; double Arg2 = 0.0; verify_case(3, Arg2, getProbability(Arg0, Arg1)); }
  void test_case_4() { int Arg0 = 4; int Arg1 = 11; double Arg2 = 0.12183372183372182; verify_case(4, Arg2, getProbability(Arg0, Arg1)); }
  void test_case_5() { int Arg0 = 2001; int Arg1 = 4000; double Arg2 = 0.1010101; verify_case(4, Arg2, getProbability(Arg0, Arg1)); }

  // END CUT HERE

};
// BEGIN CUT HERE
int main() {
MarblesInABag ___test;
___test.run_test(-1);
}
// END CUT HERE 
