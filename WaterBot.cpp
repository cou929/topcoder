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
class WaterBot {
   public:
   int minTime(vector <string> garden, int carryLimit)
  {

  }
   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"5....",
 ".....",
 ".....",
 ".....",
 "...RW"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; int Arg2 = 16; verify_case(0, Arg2, minTime(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"3.2..",
 ".....",
 ".....",
 "....R",
 "....W"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; int Arg2 = 16; verify_case(1, Arg2, minTime(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {".5555",
 ".....",
 ".....",
 "....R",
 "....W"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 85; verify_case(2, Arg2, minTime(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"R.....55",
 "......55",
 "........",
 "........",
 "........",
 ".......W"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = -1; verify_case(3, Arg2, minTime(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"R.......",
 "........",
 "....5...",
 "...5W5..",
 "....5...",
 "........"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; int Arg2 = -1; verify_case(4, Arg2, minTime(Arg0, Arg1)); }
	void test_case_5() { string Arr0[] = {".1",
 ".2",
 ".3",
 ".4",
 "R.",
 "W."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; int Arg2 = 28; verify_case(5, Arg2, minTime(Arg0, Arg1)); }
	void test_case_6() { string Arr0[] = {"R....",
 ".....",
 ".....",
 ".....",
 "....W"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; int Arg2 = 0; verify_case(6, Arg2, minTime(Arg0, Arg1)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
WaterBot ___test;
___test.run_test(-1);
}
// END CUT HERE 
