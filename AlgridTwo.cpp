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
#include <numeric>
// BEGIN CUT HERE
#include "cout.hpp"
// END CUT HERE
using namespace std;
class AlgridTwo {
  public:
  int makeProgram(vector <string> output) {
    int ret;

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
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { 
	string Arr0[] = {"BB",
 "WB"}; 
	vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
	int Arg1 = 1; 
	verify_case(0, Arg1, makeProgram(Arg0)); }
	void test_case_1() { 
	string Arr0[] = {"BBWBBB",
 "WBWBBW"}; 
	vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
	int Arg1 = 8; 
	verify_case(1, Arg1, makeProgram(Arg0)); }
	void test_case_2() { 
	string Arr0[] = {"BWBWBW",
 "WWWWWW",
 "WBBWBW"}; 
	vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
	int Arg1 = 0; 
	verify_case(2, Arg1, makeProgram(Arg0)); }
	void test_case_3() { 
	string Arr0[] = {"WWBWBWBWBWBWBWBW",
 "BWBWBWBWBWBWBWBB",
 "BWBWBWBWBWBWBWBW"}; 
	vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
	int Arg1 = 73741817; 
	verify_case(3, Arg1, makeProgram(Arg0)); }
	void test_case_4() { 
	string Arr0[] = {"BB",
 "WB"}; 
	vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
	int Arg1 = 1; 
	verify_case(4, Arg1, makeProgram(Arg0)); }
	void test_case_5() { 
	string Arr0[] = {"BB",
 "WB"}; 
	vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
	int Arg1 = 1; 
	verify_case(5, Arg1, makeProgram(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
AlgridTwo ___test;
___test.run_test(-1);
}
// END CUT HERE 
