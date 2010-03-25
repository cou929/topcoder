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
// BEGIN CUT HERE
#include "cout.hpp"
// END CUT HERE 
using namespace std;
class HanoiState {
   public:
   string partwayState(string target, int moves) {
      string ret;

      return ret;
  }
   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { 
	if ((Case == -1) || (Case == 0)) test_case_0();
	if ((Case == -1) || (Case == 1)) test_case_1();
	if ((Case == -1) || (Case == 2)) test_case_2();
	if ((Case == -1) || (Case == 3)) test_case_3();
	if ((Case == -1) || (Case == 4)) test_case_4();
	if ((Case == -1) || (Case == 5)) test_case_5();
}
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { 
	string Arg0 = "CCC"; 
	int Arg1 = 4; 
	string Arg2 = "BBC"; 
	verify_case(0, Arg2, partwayState(Arg0, Arg1)); }
	void test_case_1() { 
	string Arg0 = "AAC"; 
	int Arg1 = 7; 
	string Arg2 = "AAC"; 
	verify_case(1, Arg2, partwayState(Arg0, Arg1)); }
	void test_case_2() { 
	string Arg0 = "AAAAAAAAAAAAAAAAAAAAAAAAAAAA"; 
	int Arg1 = 0; 
	string Arg2 = "AAAAAAAAAAAAAAAAAAAAAAAAAAAA"; 
	verify_case(2, Arg2, partwayState(Arg0, Arg1)); }
	void test_case_3() { 
	string Arg0 = "ABCABCABCABCABCABCABCABCABCABC"; 
	int Arg1 = 100000000; 
	string Arg2 = "CCCCCCCCBAAAABBBBACBAAAAACBAAA"; 
	verify_case(3, Arg2, partwayState(Arg0, Arg1)); }
	void test_case_4() { 
	string Arg0 = "CCC"; 
	int Arg1 = 4; 
	string Arg2 = "BBC"; 
	verify_case(4, Arg2, partwayState(Arg0, Arg1)); }
	void test_case_5() { 
	string Arg0 = "CCC"; 
	int Arg1 = 4; 
	string Arg2 = "BBC"; 
	verify_case(5, Arg2, partwayState(Arg0, Arg1)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
HanoiState ___test;
___test.run_test(-1);
}
// END CUT HERE 
