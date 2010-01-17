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
class SuperString {
   public:
   string goodnessSubstring(vector <string> superstring)
  {

  }
   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"CHALLENGE"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "CHALLENG"; verify_case(0, Arg1, goodnessSubstring(Arg0)); }
	void test_case_1() { string Arr0[] = {"THEWORD"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "THEWORD"; verify_case(1, Arg1, goodnessSubstring(Arg0)); }
	void test_case_2() { string Arr0[] = {"THE", "MULTI", "LINE", "TEST"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "HEMULTI"; verify_case(2, Arg1, goodnessSubstring(Arg0)); }
	void test_case_3() { string Arr0[] = {"ZYXWVUTSRQPONMLKJIHGFEDCBA", "ZYXWVUTSRQPONMLKJIHGFEDCBA"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "AZYXWVUTSRQPONMLKJIHGFEDCB"; verify_case(3, Arg1, goodnessSubstring(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
SuperString ___test;
___test.run_test(-1);
}
// END CUT HERE 
