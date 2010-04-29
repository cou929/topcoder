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
class SquareFreeNumbers {
public:
  int getCount(long long min, long long max) {
    long long i, j;
    set <long long> n;

    for (i=2; i*i <= max; i++)
        for (j=1; i*i*j<=max; j++)
          if (i*i*j >= min)
            n.insert(i*i*j);

    return max - min + 1 - n.size();
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
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { 
    long long Arg0 = 1LL; 
    long long Arg1 = 10LL; 
    int Arg2 = 7; 
    verify_case(0, Arg2, getCount(Arg0, Arg1)); }
	void test_case_1() { 
    long long Arg0 = 15LL; 
    long long Arg1 = 15LL; 
    int Arg2 = 1; 
    verify_case(1, Arg2, getCount(Arg0, Arg1)); }
	void test_case_2() { 
    long long Arg0 = 1LL; 
    long long Arg1 = 1000LL; 
    int Arg2 = 608; 
    verify_case(2, Arg2, getCount(Arg0, Arg1)); }
	void test_case_3() { 
    long long Arg0 = 1LL; 
    long long Arg1 = 10LL; 
    int Arg2 = 7; 
    verify_case(3, Arg2, getCount(Arg0, Arg1)); }
	void test_case_4() { 
    long long Arg0 = 1LL; 
    long long Arg1 = 10LL; 
    int Arg2 = 7; 
    verify_case(4, Arg2, getCount(Arg0, Arg1)); }

  // END CUT HERE

};
// BEGIN CUT HERE
int main() {
SquareFreeNumbers ___test;
___test.run_test(-1);
}
// END CUT HERE 
