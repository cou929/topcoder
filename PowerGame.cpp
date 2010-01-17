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
class PowerGame {
   public:
   string winner(int size0, int size1) {
      string ret;

      return ret;
  }
   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 4; int Arg1 = 9; string Arg2 = "Alan will win after 1 moves"; verify_case(0, Arg2, winner(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 4; int Arg1 = 3; string Arg2 = "Alan will win after 1 moves"; verify_case(1, Arg2, winner(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 2; int Arg1 = 3; string Arg2 = "Bob will win after 2 moves"; verify_case(2, Arg2, winner(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 7; int Arg1 = 13; string Arg2 = "Bob will win after 4 moves"; verify_case(3, Arg2, winner(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 2136; int Arg1 = 1244; string Arg2 = "Alan will win after 7 moves"; verify_case(4, Arg2, winner(Arg0, Arg1)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
PowerGame ___test;
___test.run_test(-1);
}
// END CUT HERE 
