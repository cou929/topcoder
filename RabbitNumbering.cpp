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
class RabbitNumbering {
public:
  int theCount(vector <int> maxNumber) {
    long long ret = 1;
    int i;
    int n = maxNumber.size();
    
    sort(maxNumber.begin(), maxNumber.end());

    for (i=0; i<n; i++)
      ret = (ret * (maxNumber[i] - i)) % 1000000007;
 
    return (int)ret;
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
    int Arr0[] = {5}; 
    vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
    int Arg1 = 5; 
    verify_case(0, Arg1, theCount(Arg0)); }
	void test_case_1() { 
    int Arr0[] = {4, 4, 4, 4}; 
    vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
    int Arg1 = 24; 
    verify_case(1, Arg1, theCount(Arg0)); }
	void test_case_2() { 
    int Arr0[] = {5, 8}; 
    vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
    int Arg1 = 35; 
    verify_case(2, Arg1, theCount(Arg0)); }
	void test_case_3() { 
    int Arr0[] = {2, 1, 2}; 
    vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
    int Arg1 = 0; 
    verify_case(3, Arg1, theCount(Arg0)); }
	void test_case_4() { 
    int Arr0[] = {25, 489, 76, 98, 704, 98, 768, 39, 697, 8, 56, 74, 36, 95, 87, 2, 968, 4, 920, 54, 873, 90}; 
    vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
    int Arg1 = 676780400; 
    verify_case(4, Arg1, theCount(Arg0)); }
	void test_case_5() { 
    int Arr0[] = {1, 1, 1, 1}; 
    vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
    int Arg1 = 0; 
    verify_case(5, Arg1, theCount(Arg0)); }
	void test_case_6() { 
    int Arr0[] = {2, 3, 4}; 
    vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
    int Arg1 = 8; 
    verify_case(6, Arg1, theCount(Arg0)); }

  // END CUT HERE

};
// BEGIN CUT HERE
int main() {
RabbitNumbering ___test;
___test.run_test(-1);
}
// END CUT HERE 
