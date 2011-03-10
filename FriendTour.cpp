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
class FriendTour {
   public:
   double tourProbability(vector <string> friends, int K) {
      double ret;

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
}
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { 
	string Arr0[] = {"2 3 4",
 "1 3 4",
 "1 2 4",
 "1 2 3"}; 
	vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
	int Arg1 = 1; 
	double Arg2 = 0.2222222222222222; 
	verify_case(0, Arg2, tourProbability(Arg0, Arg1)); }
	void test_case_1() { 
	string Arr0[] = {"2 3 4",
 "1 3 4",
 "1 2 4",
 "1 2 3"}; 
	vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
	int Arg1 = 2; 
	double Arg2 = 0.6666666666666666; 
	verify_case(1, Arg2, tourProbability(Arg0, Arg1)); }
	void test_case_2() { 
	string Arr0[] = {"3 2 4",
 "3 5 1",
 "5 2 1 4",
 "3 1 5",
 "3 2 4"}; 
	vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
	int Arg1 = 2; 
	double Arg2 = 0.3333333333333333; 
	verify_case(2, Arg2, tourProbability(Arg0, Arg1)); }
	void test_case_3() { 
	string Arr0[] = {"3 2 4",
 "3 5 1",
 "5 2 1 4",
 "3 1 5 6",
 "3 2 4",
 "4"}
; 
	vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
	int Arg1 = 2; 
	double Arg2 = 0.3055555555555556; 
	verify_case(3, Arg2, tourProbability(Arg0, Arg1)); }
	void test_case_4() { 
	string Arr0[] = {"6 5 4 2",
 "1 6 3 5",
 "5 4 2",
 "3 1 5",
 "2 4 3 1 6",
 "1 2 5"}; 
	vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
	int Arg1 = 3; 
	double Arg2 = 0.73125; 
	verify_case(4, Arg2, tourProbability(Arg0, Arg1)); }
	void test_case_5() { 
	string Arr0[] = {"2 3 4",
 "1 3 4",
 "1 2 4",
 "1 2 3"}; 
	vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
	int Arg1 = 1; 
	double Arg2 = 0.2222222222222222; 
	verify_case(5, Arg2, tourProbability(Arg0, Arg1)); }
	void test_case_6() { 
	string Arr0[] = {"2 3 4",
 "1 3 4",
 "1 2 4",
 "1 2 3"}; 
	vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
	int Arg1 = 1; 
	double Arg2 = 0.2222222222222222; 
	verify_case(6, Arg2, tourProbability(Arg0, Arg1)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
FriendTour ___test;
___test.run_test(-1);
}
// END CUT HERE 
