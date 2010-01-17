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
class RepeatedPatterns {
   public:
   long long findZeroSegment(string P1, string P2, string zeroCount)
  {

  }
   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "111010100001010"; string Arg1 = "010000001000"; string Arg2 = "3"; long long Arg3 = 7LL; verify_case(0, Arg3, findZeroSegment(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arg0 = "1101010010"; string Arg1 = "0001000"; string Arg2 = "3"; long long Arg3 = 9999999LL; verify_case(1, Arg3, findZeroSegment(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arg0 = "1101010010"; string Arg1 = "0001000"; string Arg2 = "5"; long long Arg3 = 20000011LL; verify_case(2, Arg3, findZeroSegment(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arg0 = "10101010"; string Arg1 = "101010101010"; string Arg2 = "9876543219876"; long long Arg3 = -1LL; verify_case(3, Arg3, findZeroSegment(Arg0, Arg1, Arg2)); }
	void test_case_4() { string Arg0 = "11111111111111111111111111"; string Arg1 = "0"; string Arg2 = "9876543219876"; long long Arg3 = -1LL; verify_case(4, Arg3, findZeroSegment(Arg0, Arg1, Arg2)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
RepeatedPatterns ___test;
___test.run_test(-1);
}
// END CUT HERE 
