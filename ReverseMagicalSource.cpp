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
class ReverseMagicalSource {
public:
  int find(int source, int A)
  {
    int ret = source;
    int i = 1;

    while (A >= ret)
      ret += source * pow((double)10, i++);

    return ret;
  } 
   
  // BEGIN CUT HERE
public:
  void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
private:
  template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
  void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
  void test_case_0() { int Arg0 = 19; int Arg1 = 200; int Arg2 = 209; verify_case(0, Arg2, find(Arg0, Arg1)); }
  void test_case_1() { int Arg0 = 19; int Arg1 = 18; int Arg2 = 19; verify_case(1, Arg2, find(Arg0, Arg1)); }
  void test_case_2() { int Arg0 = 333; int Arg1 = 36963; int Arg2 = 369963; verify_case(2, Arg2, find(Arg0, Arg1)); }
  void test_case_3() { int Arg0 = 1234; int Arg1 = 1000000; int Arg2 = 1370974; verify_case(3, Arg2, find(Arg0, Arg1)); }

  // END CUT HERE

};
// BEGIN CUT HERE
int main() {
ReverseMagicalSource ___test;
___test.run_test(-1);
}
// END CUT HERE 
