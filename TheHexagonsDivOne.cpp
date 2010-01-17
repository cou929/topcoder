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
class TheHexagonsDivOne {
public:
  long long count(int n) {
    long long ret = 0;
    long long N = n;

    if (n < 4) return ret;

    if (n >= 4)
      ret += 4 * 2 * 2 * 2 * 2 * N * (N-1) * (N-2) * (N-3);

    if (n >= 5)
      ret += 18 * 2 * 2 * 2 * 2 * 2 * N * (N-1) * (N-2) * (N-3) * (N-4);

    if (n >= 6)
      ret += 9 * 2 * 2 * 2 * 2 * 2 * 2 * N * (N-1) * (N-2) * (N-3) * (N-4) * (N-5);

    if (n >= 7)
      ret += 2 * 2 * 2 * 2 * 2 * 2 * 2 * N * (N-1) * (N-2) * (N-3) * (N-4) * (N-5) * (N-6);

    ret /= 6;

    return ret;
  }
   
  // BEGIN CUT HERE
public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; long long Arg1 = 0LL; verify_case(0, Arg1, count(Arg0)); }
	void test_case_1() { int Arg0 = 4; long long Arg1 = 256LL; verify_case(1, Arg1, count(Arg0)); }
	void test_case_2() { int Arg0 = 8; long long Arg1 = 3458560LL; verify_case(2, Arg1, count(Arg0)); }
	void test_case_3() { int Arg0 = 20; long long Arg1 = 11193888000LL; verify_case(3, Arg1, count(Arg0)); }

  // END CUT HERE

};
// BEGIN CUT HERE
int main() {
TheHexagonsDivOne ___test;
___test.run_test(-1);
}
// END CUT HERE 
