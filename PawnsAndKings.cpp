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
class PawnsAndKings {
   public:
   int minNumberOfMoves(vector <string> board)
  {

  }
   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {".PPPPKP.", 
 "........", 
 "........", 
 "........", 
 "........", 
 "........", 
 "........", 
 "........"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; verify_case(0, Arg1, minNumberOfMoves(Arg0)); }
	void test_case_1() { string Arr0[] = {"P......P", 
 "........", 
 "........",
 "........",
 "...KK...",
 "........",
 "........",
 "P......P"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 20; verify_case(1, Arg1, minNumberOfMoves(Arg0)); }
	void test_case_2() { string Arr0[] = {".....P.P",
 "..K....P",
 "....K...",
 "..PP...P",
 "...K..KK",
 "........",
 "K.......",
 "KP.K...."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 9; verify_case(2, Arg1, minNumberOfMoves(Arg0)); }
	void test_case_3() { string Arr0[] = {"PK...KPK",
 "......K.",
 "...K....",
 "..KPK...",
 "...K....",
 "........",
 "........",
 "K..P.K.P"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 8; verify_case(3, Arg1, minNumberOfMoves(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
PawnsAndKings ___test;
___test.run_test(-1);
}
// END CUT HERE 
