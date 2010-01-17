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
class DesignCalendar {
public:
  int shortestPeriod(int dayLength, int yearLength)
  {
//     double d = (double)yearLength / dayLength - (int)((double)yearLength / dayLength);
//     return (int)(1.0 / d);

    for (int i=1; i<10000; i++)
      {
	long long tmp = yearLength * i;
	if (tmp % dayLength == 0)
	 return i;

	if (i == 1728)
	  cout << tmp << " " << tmp % dayLength << endl;
      }

    return -1;
  }
   
  // BEGIN CUT HERE
public:
  void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
private:
  template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
  void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
  void test_case_0() { int Arg0 = 4; int Arg1 = 1461; int Arg2 = 4; verify_case(0, Arg2, shortestPeriod(Arg0, Arg1)); }
  void test_case_1() { int Arg0 = 86400; int Arg1 = 31558150; int Arg2 = 1728; verify_case(1, Arg2, shortestPeriod(Arg0, Arg1)); }
  void test_case_2() { int Arg0 = 98; int Arg1 = 100; int Arg2 = 49; verify_case(2, Arg2, shortestPeriod(Arg0, Arg1)); }
  void test_case_3() { int Arg0 = 1000; int Arg1 = 50000100; int Arg2 = 10; verify_case(3, Arg2, shortestPeriod(Arg0, Arg1)); }
  void test_case_4() { int Arg0 = 5673; int Arg1 = 28565335; int Arg2 = 5673; verify_case(4, Arg2, shortestPeriod(Arg0, Arg1)); }
  void test_case_5() { int Arg0 = 5555; int Arg1 = 846555; int Arg2 = 1111; verify_case(5, Arg2, shortestPeriod(Arg0, Arg1)); }

  // END CUT HERE

};
// BEGIN CUT HERE
int main() {
DesignCalendar ___test;
___test.run_test(-1);
}
// END CUT HERE 
