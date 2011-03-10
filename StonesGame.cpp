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
class StonesGame {
  public:
  string winner(int N, int M, int K, int L) {
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
	if ((Case == -1) || (Case == 6)) test_case_6();
	if ((Case == -1) || (Case == 7)) test_case_7();
}
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { 
	int Arg0 = 3; 
	int Arg1 = 1; 
	int Arg2 = 1; 
	int Arg3 = 2; 
	string Arg4 = "Draw"; 
	verify_case(0, Arg4, winner(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { 
	int Arg0 = 5; 
	int Arg1 = 1; 
	int Arg2 = 2; 
	int Arg3 = 2; 
	string Arg4 = "Romeo"; 
	verify_case(1, Arg4, winner(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { 
	int Arg0 = 5; 
	int Arg1 = 5; 
	int Arg2 = 2; 
	int Arg3 = 3; 
	string Arg4 = "Strangelet"; 
	verify_case(2, Arg4, winner(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { 
	int Arg0 = 5; 
	int Arg1 = 5; 
	int Arg2 = 2; 
	int Arg3 = 2; 
	string Arg4 = "Draw"; 
	verify_case(3, Arg4, winner(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { 
	int Arg0 = 1000000; 
	int Arg1 = 804588; 
	int Arg2 = 705444; 
	int Arg3 = 292263; 
	string Arg4 = "Romeo"; 
	verify_case(4, Arg4, winner(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_5() { 
	int Arg0 = 1000000; 
	int Arg1 = 100000; 
	int Arg2 = 500000; 
	int Arg3 = 600000; 
	string Arg4 = "Strangelet"; 
	verify_case(5, Arg4, winner(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_6() { 
	int Arg0 = 3; 
	int Arg1 = 1; 
	int Arg2 = 1; 
	int Arg3 = 2; 
	string Arg4 = "Draw"; 
	verify_case(6, Arg4, winner(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_7() { 
	int Arg0 = 3; 
	int Arg1 = 1; 
	int Arg2 = 1; 
	int Arg3 = 2; 
	string Arg4 = "Draw"; 
	verify_case(7, Arg4, winner(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
StonesGame ___test;
___test.run_test(-1);
}
// END CUT HERE 
