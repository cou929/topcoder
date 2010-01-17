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
class QuasiLatinSquares {
   public:
   vector <string> makeSquare(int n, int d)
  {

  }
   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 3; string Arr2[] = {"0 1 2", "1 2 0", "2 0 1" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, makeSquare(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 5; int Arg1 = 2; string Arr2[] = {"0 0 0 0 1", "0 0 0 0 1", "0 0 0 0 1", "0 0 0 0 1", "1 1 1 1 0" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, makeSquare(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 5; int Arg1 = 4; string Arr2[] = {"0 0 1 2 3", "0 0 1 2 3", "1 1 0 3 2", "2 2 3 0 1", "3 3 2 1 0" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(2, Arg2, makeSquare(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 9; int Arg1 = 7; string Arr2[] = {"0 0 0 1 2 3 4 5 6", "0 0 0 1 2 3 4 5 6", "0 0 0 1 2 3 4 5 6", "1 1 1 0 3 2 5 6 4", "2 2 2 3 0 1 6 4 5", "3 3 3 4 5 6 0 1 2", "4 4 4 2 6 5 1 0 3", "5 5 5 6 1 4 2 3 0", "6 6 6 5 4 0 3 2 1" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(3, Arg2, makeSquare(Arg0, Arg1)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
QuasiLatinSquares ___test;
___test.run_test(-1);
}
// END CUT HERE 
