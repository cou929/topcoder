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
class TrueStatements {
public:
  int numberTrue(vector <int> statements) {
    int ret = -1;
    int i;

    for (i=0; i<=50; i++) {
      int c = count(statements.begin(), statements.end(), i);
      if (i == c)
        ret = max(ret, c);
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
  }
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { 
    int Arr0[] = {0, 1, 2, 3}; 
    vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
    int Arg1 = 1; 
    verify_case(0, Arg1, numberTrue(Arg0)); }
	void test_case_1() { 
    int Arr0[] = {0}; 
    vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
    int Arg1 = -1; 
    verify_case(1, Arg1, numberTrue(Arg0)); }
	void test_case_2() { 
    int Arr0[] = {0, 3, 1, 3, 2, 3}; 
    vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
    int Arg1 = 3; 
    verify_case(2, Arg1, numberTrue(Arg0)); }
	void test_case_3() { 
    int Arr0[] = {1, 1}; 
    vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
    int Arg1 = 0; 
    verify_case(3, Arg1, numberTrue(Arg0)); }
	void test_case_4() { 
    int Arr0[] = {0, 1, 2, 3}; 
    vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
    int Arg1 = 1; 
    verify_case(4, Arg1, numberTrue(Arg0)); }
	void test_case_5() { 
    int Arr0[] = {0, 1, 2, 3}; 
    vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
    int Arg1 = 1; 
    verify_case(5, Arg1, numberTrue(Arg0)); }

  // END CUT HERE

};
// BEGIN CUT HERE
int main() {
TrueStatements ___test;
___test.run_test(-1);
}
// END CUT HERE 
