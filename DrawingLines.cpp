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
class DrawingLines {
   public:
   double countLineCrossings(int n, vector <int> startDot, vector <int> endDot) {
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
}
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { 
	int Arg0 = 3; 
	int Arr1[] = {2}; 
	vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); 
	int Arr2[] = {3}; 
	vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); 
	double Arg3 = 1.5; 
	verify_case(0, Arg3, countLineCrossings(Arg0, Arg1, Arg2)); }
	void test_case_1() { 
	int Arg0 = 5; 
	int Arr1[] = {1,4}; 
	vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); 
	int Arr2[] = {3,1}; 
	vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); 
	double Arg3 = 5.5; 
	verify_case(1, Arg3, countLineCrossings(Arg0, Arg1, Arg2)); }
	void test_case_2() { 
	int Arg0 = 4; 
	int Arr1[] = {4,1}; 
	vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); 
	int Arr2[] = {4,1}; 
	vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); 
	double Arg3 = 0.5; 
	verify_case(2, Arg3, countLineCrossings(Arg0, Arg1, Arg2)); }
	void test_case_3() { 
	int Arg0 = 8; 
	int Arr1[] = {1,4,3,6,7}; 
	vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); 
	int Arr2[] = {1,3,2,4,5}; 
	vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); 
	double Arg3 = 7.5; 
	verify_case(3, Arg3, countLineCrossings(Arg0, Arg1, Arg2)); }
	void test_case_4() { 
	int Arg0 = 3; 
	int Arr1[] = {2}; 
	vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); 
	int Arr2[] = {3}; 
	vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); 
	double Arg3 = 1.5; 
	verify_case(4, Arg3, countLineCrossings(Arg0, Arg1, Arg2)); }
	void test_case_5() { 
	int Arg0 = 3; 
	int Arr1[] = {2}; 
	vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); 
	int Arr2[] = {3}; 
	vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); 
	double Arg3 = 1.5; 
	verify_case(5, Arg3, countLineCrossings(Arg0, Arg1, Arg2)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
DrawingLines ___test;
___test.run_test(-1);
}
// END CUT HERE 
