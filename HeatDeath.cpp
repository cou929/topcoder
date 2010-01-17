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
class HeatDeath {
   public:
   int maxTime(vector <int> energy)
  {

  }
   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = { 5, 7, 9 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(0, Arg1, maxTime(Arg0)); }
	void test_case_1() { int Arr0[] = { 5, 6, 5, 6 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(1, Arg1, maxTime(Arg0)); }
	void test_case_2() { int Arr0[] = { 1, 1, 1, 1, 1, 999, 999, 999, 999, 999 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 12435; verify_case(2, Arg1, maxTime(Arg0)); }
	void test_case_3() { int Arr0[] = { 354, 903, 100, 951, 669, 311, 339, 500, 942, 72, 712, 54, 64,
  572, 7, 977, 74, 524, 314, 160, 526, 729, 114, 691, 771, 704,
  288, 47, 735, 85, 694, 124, 349, 905, 611, 371, 885, 738, 165,
  442, 138, 348, 605, 239, 535, 33, 142, 946, 4, 231 }
; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 214090; verify_case(3, Arg1, maxTime(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
HeatDeath ___test;
___test.run_test(-1);
}
// END CUT HERE 
