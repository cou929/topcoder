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
class OnTheFarmDivTwo {
public:
  vector <int> animals(int heads, int legs) {
    vector <int> ret;
    int i;

    for (i=0; i<=heads; i++) {
      if (i * 2 + (heads - i) * 4 == legs) {
        ret.push_back(i);
        ret.push_back(heads-i);
        break;
      }
    }

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
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { 
    int Arg0 = 3; 
    int Arg1 = 8; 
    int Arr2[] = {2, 1 }; 
    vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); 
    verify_case(0, Arg2, animals(Arg0, Arg1)); }
	void test_case_1() { 
    int Arg0 = 10; 
    int Arg1 = 40; 
    int Arr2[] = {0, 10 }; 
    vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); 
    verify_case(1, Arg2, animals(Arg0, Arg1)); }
	void test_case_2() { 
    int Arg0 = 10; 
    int Arg1 = 42; 
    int Arr2[] = { }; 
    vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); 
    verify_case(2, Arg2, animals(Arg0, Arg1)); }
	void test_case_3() { 
    int Arg0 = 1; 
    int Arg1 = 3; 
    int Arr2[] = { }; 
    vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); 
    verify_case(3, Arg2, animals(Arg0, Arg1)); }
	void test_case_4() { 
    int Arg0 = 0; 
    int Arg1 = 0; 
    int Arr2[] = {0, 0 }; 
    vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); 
    verify_case(4, Arg2, animals(Arg0, Arg1)); }
	void test_case_5() { 
    int Arg0 = 3; 
    int Arg1 = 8; 
    int Arr2[] = {2, 1 }; 
    vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); 
    verify_case(5, Arg2, animals(Arg0, Arg1)); }
	void test_case_6() { 
    int Arg0 = 3; 
    int Arg1 = 8; 
    int Arr2[] = {2, 1 }; 
    vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); 
    verify_case(6, Arg2, animals(Arg0, Arg1)); }

  // END CUT HERE

};
// BEGIN CUT HERE
int main() {
OnTheFarmDivTwo ___test;
___test.run_test(-1);
}
// END CUT HERE 
