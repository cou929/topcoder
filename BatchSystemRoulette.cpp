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
class BatchSystemRoulette {
   public:
   vector <double> expectedFinishTimes(vector <int> duration, vector <string> user) {
      vector <double> ret;

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
}
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <double> &Expected, const vector <double> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { 
	int Arr0[] = {3, 2, 4, 1}; 
	vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
	string Arr1[] = {"Gil Grissom", "Sarah Sidle", "Warrick Brown", "Catherine Willows"}; 
	vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); 
	double Arr2[] = {6.0, 3.0, 10.0, 1.0 }; 
	vector <double> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); 
	verify_case(0, Arg2, expectedFinishTimes(Arg0, Arg1)); }
	void test_case_1() { 
	int Arr0[] = {3, 2, 4, 1}; 
	vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
	string Arr1[] = {"mac taylor", "Mac Taylor", "Mac Taylor", "Peyton Driscoll"}; 
	vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); 
	double Arr2[] = {4.0, 8.0, 9.0, 1.0 }; 
	vector <double> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); 
	verify_case(1, Arg2, expectedFinishTimes(Arg0, Arg1)); }
	void test_case_2() { 
	int Arr0[] = {13, 14, 15, 56, 56}; 
	vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
	string Arr1[] = {"Tim Speedle", "Tim Speedle", "Tim Speedle", "Horatio Caine", "YEEEAAAAAAAAAAH"}; 
	vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); 
	double Arr2[] = {27.5, 28.0, 28.5, 126.0, 126.0 }; 
	vector <double> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); 
	verify_case(2, Arg2, expectedFinishTimes(Arg0, Arg1)); }
	void test_case_3() { 
	int Arr0[] = {3, 2, 4, 1}; 
	vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
	string Arr1[] = {"Gil Grissom", "Sarah Sidle", "Warrick Brown", "Catherine Willows"}; 
	vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); 
	double Arr2[] = {6.0, 3.0, 10.0, 1.0 }; 
	vector <double> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); 
	verify_case(3, Arg2, expectedFinishTimes(Arg0, Arg1)); }
	void test_case_4() { 
	int Arr0[] = {3, 2, 4, 1}; 
	vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
	string Arr1[] = {"Gil Grissom", "Sarah Sidle", "Warrick Brown", "Catherine Willows"}; 
	vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); 
	double Arr2[] = {6.0, 3.0, 10.0, 1.0 }; 
	vector <double> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); 
	verify_case(4, Arg2, expectedFinishTimes(Arg0, Arg1)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
BatchSystemRoulette ___test;
___test.run_test(-1);
}
// END CUT HERE 
