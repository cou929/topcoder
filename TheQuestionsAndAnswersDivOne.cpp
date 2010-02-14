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
class TheQuestionsAndAnswersDivOne {
   public:
   int find(int questions, vector <string> answers) {
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
	int Arg0 = 2; 
	string Arr1[] = {"No", "Yes"}; 
	vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); 
	int Arg2 = 2; 
	verify_case(0, Arg2, find(Arg0, Arg1)); }
	void test_case_1() { 
	int Arg0 = 2; 
	string Arr1[] = {"No", "No", "No"}; 
	vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); 
	int Arg2 = 6; 
	verify_case(1, Arg2, find(Arg0, Arg1)); }
	void test_case_2() { 
	int Arg0 = 3; 
	string Arr1[] = {"Yes", "No", "No", "Yes"}; 
	vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); 
	int Arg2 = 12; 
	verify_case(2, Arg2, find(Arg0, Arg1)); }
	void test_case_3() { 
	int Arg0 = 3; 
	string Arr1[] = {"Yes", "Yes", "Yes", "No"}; 
	vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); 
	int Arg2 = 18; 
	verify_case(3, Arg2, find(Arg0, Arg1)); }
	void test_case_4() { 
	int Arg0 = 2; 
	string Arr1[] = {"No", "Yes"}; 
	vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); 
	int Arg2 = 2; 
	verify_case(4, Arg2, find(Arg0, Arg1)); }
	void test_case_5() { 
	int Arg0 = 2; 
	string Arr1[] = {"No", "Yes"}; 
	vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); 
	int Arg2 = 2; 
	verify_case(5, Arg2, find(Arg0, Arg1)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
TheQuestionsAndAnswersDivOne ___test;
___test.run_test(-1);
}
// END CUT HERE 
