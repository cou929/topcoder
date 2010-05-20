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
class TheMoviesLevelTwoDivOne {
   public:
   vector <int> find(vector <int> length, vector <int> scary) {
      vector <int> ret;

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
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { 
	int Arr0[] = {100, 50}; 
	vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
	int Arr1[] = {1, 1}; 
	vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); 
	int Arr2[] = {0, 1 }; 
	vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); 
	verify_case(0, Arg2, find(Arg0, Arg1)); }
	void test_case_1() { 
	int Arr0[] = {100, 50}; 
	vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
	int Arr1[] = {1, 49}; 
	vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); 
	int Arr2[] = {1, 0 }; 
	vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); 
	verify_case(1, Arg2, find(Arg0, Arg1)); }
	void test_case_2() { 
	int Arr0[] = {100, 100, 100, 100}; 
	vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
	int Arr1[] = {77, 76, 75, 74}; 
	vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); 
	int Arr2[] = {3, 0, 1, 2 }; 
	vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); 
	verify_case(2, Arg2, find(Arg0, Arg1)); }
	void test_case_3() { 
	int Arr0[] = {100}; 
	vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
	int Arr1[] = {99}; 
	vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); 
	int Arr2[] = {0 }; 
	vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); 
	verify_case(3, Arg2, find(Arg0, Arg1)); }
	void test_case_4() { 
	int Arr0[] = {100, 50}; 
	vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
	int Arr1[] = {1, 1}; 
	vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); 
	int Arr2[] = {0, 1 }; 
	vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); 
	verify_case(4, Arg2, find(Arg0, Arg1)); }
	void test_case_5() { 
	int Arr0[] = {100, 50}; 
	vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
	int Arr1[] = {1, 1}; 
	vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); 
	int Arr2[] = {0, 1 }; 
	vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); 
	verify_case(5, Arg2, find(Arg0, Arg1)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
TheMoviesLevelTwoDivOne ___test;
___test.run_test(-1);
}
// END CUT HERE 
