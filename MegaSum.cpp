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
class MegaSum {
   public:
   int calculate(long long N) {

  }
   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { long long Arg0 = 8LL; int Arg1 = 58; verify_case(0, Arg1, calculate(Arg0)); }
	void test_case_1() { long long Arg0 = 12LL; int Arg1 = 282; verify_case(1, Arg1, calculate(Arg0)); }
	void test_case_2() { long long Arg0 = 11LL; int Arg1 = 128; verify_case(2, Arg1, calculate(Arg0)); }
	void test_case_3() { long long Arg0 = 6LL; int Arg1 = 50; verify_case(3, Arg1, calculate(Arg0)); }
	void test_case_4() { long long Arg0 = 34539LL; int Arg1 = 437909839; verify_case(4, Arg1, calculate(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
MegaSum ___test;
___test.run_test(-1);
}
// END CUT HERE 
