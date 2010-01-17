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
using namespace std;
class TeamSplit {
public:
  int difference(vector <int> strengths)
  {
    int a = 0, b = 0;

    sort(strengths.rbegin(), strengths.rend());

    for (int i=0; i<strengths.size(); i++)
      if (i % 2 == 0)
	a += strengths[i];
      else
	b += strengths[i];

    return abs(a - b);
  }
   
  // BEGIN CUT HERE
public:
  void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
private:
  template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
  void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
  void test_case_0() { int Arr0[] = {5,7,8,4,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(0, Arg1, difference(Arg0)); }
  void test_case_1() { int Arr0[] = {100}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 100; verify_case(1, Arg1, difference(Arg0)); }
  void test_case_2() { int Arr0[] = {1000,1000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(2, Arg1, difference(Arg0)); }
  void test_case_3() { int Arr0[] = {9,8,7,6}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(3, Arg1, difference(Arg0)); }
  void test_case_4() { int Arr0[] = {1,5,10,1,5,10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(4, Arg1, difference(Arg0)); }
  void test_case_5() { int Arr0[] = {824, 581,   9, 776, 149, 493, 531, 558, 995, 637,
				     394, 526, 986, 548, 344, 509, 319,  37, 790, 491,
				     479,  34, 776, 321, 258, 851, 711, 365, 763, 355,
				     386, 877, 596,  96, 151, 166, 558, 109, 874, 959,
				     845, 181, 976, 335, 930,  22,  78, 120, 907, 584}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 478; verify_case(5, Arg1, difference(Arg0)); }

  // END CUT HERE

};
// BEGIN CUT HERE
int main() {
TeamSplit ___test;
___test.run_test(-1);
}
// END CUT HERE 
