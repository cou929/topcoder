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
class Thirteen {
   public:
   int calcTime(vector <string> city) {
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
	string Arr0[] = { "#AB##",
  "###A#",
  "###C#",
  "####K",
  "#####" }; 
	vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
	int Arg1 = 16; 
	verify_case(0, Arg1, calcTime(Arg0)); }
	void test_case_1() { 
	string Arr0[] = { "#Z",
  "Z#" }; 
	vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
	int Arg1 = -1; 
	verify_case(1, Arg1, calcTime(Arg0)); }
	void test_case_2() { 
	string Arr0[] = { "#A#C##",
  "##FA#K",
  "###D#D",
  "A###A#",
  "##C###",
  "####A#" }; 
	vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
	int Arg1 = 10; 
	verify_case(2, Arg1, calcTime(Arg0)); }
	void test_case_3() { 
	string Arr0[] = { "Good#####",
  "#Luck####",
  "##and####",
  "##Have###",
  "####Fun##",
  "#####in##",
  "#####the#",
  "CHALLENGE",
  "##PHASE##" }; 
	vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
	int Arg1 = 137; 
	verify_case(3, Arg1, calcTime(Arg0)); }
	void test_case_4() { 
	string Arr0[] = { "###No#####",
  "####Zaphod",
  "#####Just#",
  "######very",
  "####very##",
  "improbable",
  "##########",
  "##########",
  "##########",
  "##########" }; 
	vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
	int Arg1 = 103; 
	verify_case(4, Arg1, calcTime(Arg0)); }
	void test_case_5() { 
	string Arr0[] = { "#AB##",
  "###A#",
  "###C#",
  "####K",
  "#####" }; 
	vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
	int Arg1 = 16; 
	verify_case(5, Arg1, calcTime(Arg0)); }
	void test_case_6() { 
	string Arr0[] = { "#AB##",
  "###A#",
  "###C#",
  "####K",
  "#####" }; 
	vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
	int Arg1 = 16; 
	verify_case(6, Arg1, calcTime(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
Thirteen ___test;
___test.run_test(-1);
}
// END CUT HERE 
