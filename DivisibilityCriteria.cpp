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
class DivisibilityCriteria {
public:
  vector <int> multipliers(int N, int P)
  {
    vector <int> ret(1, 1);
    int mul = 1;

    for (int i=1; i<N; i++)
      {
	mul = (mul * 10) % P;
	ret.push_back(mul);
      }

    reverse(ret.begin(), ret.end());

    return ret;
  }
   
  // BEGIN CUT HERE
public:
  void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
private:
  template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
  void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
  void test_case_0() { int Arg0 = 6; int Arg1 = 7; int Arr2[] = {5, 4, 6, 2, 3, 1 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, multipliers(Arg0, Arg1)); }
  void test_case_1() { int Arg0 = 7; int Arg1 = 11; int Arr2[] = {1, 10, 1, 10, 1, 10, 1 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, multipliers(Arg0, Arg1)); }
  void test_case_2() { int Arg0 = 5; int Arg1 = 13; int Arr2[] = {3, 12, 9, 10, 1 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(2, Arg2, multipliers(Arg0, Arg1)); }
  void test_case_3() { int Arg0 = 2; int Arg1 = 2; int Arr2[] = {0, 1 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(3, Arg2, multipliers(Arg0, Arg1)); }
  void test_case_4() { int Arg0 = 16; int Arg1 = 97; int Arr2[] = {45, 53, 15, 50, 5, 49, 34, 81, 76, 27, 90, 9, 30, 3, 10, 1 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(4, Arg2, multipliers(Arg0, Arg1)); }

  // END CUT HERE

};
// BEGIN CUT HERE
int main() {
DivisibilityCriteria ___test;
___test.run_test(-1);
}
// END CUT HERE 
