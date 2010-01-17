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
class Refactoring {
public:
  map <pair <int, int>, int> memo;

  int count(int n, int last)
  {
    int ret = 0;
    if (memo.find(make_pair(n, last)) != memo.end())
      return memo[make_pair(n, last)];

    for (int i=last; i*i<=n; i++)
      if (n % i == 0)
	ret += count(n/i, i) + 1;

    memo[make_pair(n, last)] = ret;
    return ret;
  }

  int refactor(int n)
  {
    return count(n, 2);
  }
   
  // BEGIN CUT HERE
public:
  void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
private:
  template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
  void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
  void test_case_0() { int Arg0 = 24; int Arg1 = 6; verify_case(0, Arg1, refactor(Arg0)); }
  void test_case_1() { int Arg0 = 9973; int Arg1 = 0; verify_case(1, Arg1, refactor(Arg0)); }
  void test_case_2() { int Arg0 = 9240; int Arg1 = 295; verify_case(2, Arg1, refactor(Arg0)); }
  void test_case_3() { int Arg0 = 1916006400; int Arg1 = 7389115; verify_case(3, Arg1, refactor(Arg0)); }

  // END CUT HERE

};
// BEGIN CUT HERE
int main() {
Refactoring ___test;
___test.run_test(-1);
}
// END CUT HERE 
