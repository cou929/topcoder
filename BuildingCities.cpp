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
class BuildingCities {
   public:
   int findMinimumCities(int maxDirect, int maxTravel, vector <int> cityX, vector <int> cityY) {
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
	if ((Case == -1) || (Case == 6)) test_case_6();
}
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { 
	int Arg0 = 1; 
	int Arg1 = 5; 
	int Arr2[] = {0,0,0,1,2,2,3}; 
	vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); 
	int Arr3[] = {0,1,2,2,2,1,1}; 
	vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); 
	int Arg4 = 1; 
	verify_case(0, Arg4, findMinimumCities(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { 
	int Arg0 = 3; 
	int Arg1 = 15; 
	int Arr2[] = {2,6,10,14}; 
	vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); 
	int Arr3[] = {2,6,2,6}; 
	vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); 
	int Arg4 = 3; 
	verify_case(1, Arg4, findMinimumCities(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { 
	int Arg0 = 2; 
	int Arg1 = 15; 
	int Arr2[] = {0,5,2,3,1,8,6,4,7,9,10}; 
	vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); 
	int Arr3[] = {0,5,2,3,1,8,6,4,7,9,10}; 
	vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); 
	int Arg4 = 0; 
	verify_case(2, Arg4, findMinimumCities(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { 
	int Arg0 = 2; 
	int Arg1 = 5; 
	int Arr2[] = {0,5}; 
	vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); 
	int Arr3[] = {0,5}; 
	vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); 
	int Arg4 = -1; 
	verify_case(3, Arg4, findMinimumCities(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { 
	int Arg0 = 5; 
	int Arg1 = 1500; 
	int Arr2[] = {0,1000}; 
	vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); 
	int Arr3[] = {0,1000}; 
	vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); 
	int Arg4 = 282; 
	verify_case(4, Arg4, findMinimumCities(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_5() { 
	int Arg0 = 1; 
	int Arg1 = 5; 
	int Arr2[] = {0,0,0,1,2,2,3}; 
	vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); 
	int Arr3[] = {0,1,2,2,2,1,1}; 
	vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); 
	int Arg4 = 1; 
	verify_case(5, Arg4, findMinimumCities(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_6() { 
	int Arg0 = 1; 
	int Arg1 = 5; 
	int Arr2[] = {0,0,0,1,2,2,3}; 
	vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); 
	int Arr3[] = {0,1,2,2,2,1,1}; 
	vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); 
	int Arg4 = 1; 
	verify_case(6, Arg4, findMinimumCities(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
BuildingCities ___test;
___test.run_test(-1);
}
// END CUT HERE 
