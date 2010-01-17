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
class BadSubstring {
public:
  long long howMany(int length)
  {
    long long l[length+1];
    l[0] = 1;
    l[1] = 3;

    for (int i=2; i<=length; i++)
      l[i] = l[i-2]*2 + (l[i-1] - l[i-2])*3;

    return l[length];
  }
   
  // BEGIN CUT HERE
public:
  void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
private:
  template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
  void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
  void test_case_0() { int Arg0 = 0; long long Arg1 = 1LL; verify_case(0, Arg1, howMany(Arg0)); }
  void test_case_1() { int Arg0 = 3; long long Arg1 = 21LL; verify_case(1, Arg1, howMany(Arg0)); }
  void test_case_2() { int Arg0 = 29; long long Arg1 = 1548008755920LL; verify_case(2, Arg1, howMany(Arg0)); }

  // END CUT HERE

};
// BEGIN CUT HERE
int main() {
BadSubstring ___test;
___test.run_test(-1);
}
// END CUT HERE 
