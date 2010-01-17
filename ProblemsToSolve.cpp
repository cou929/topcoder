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

using namespace std;

class ProblemsToSolve {
public:
  int getProbNum(int r, int l)
  {
    int ret = 0;

    ret += 2;
    ret += (l - r - 1) / 2;

    if (r != 0)
      {
	ret++;
	ret += (r - 1) / 2;
      }

    return ret;
  }

  int minNumber(vector <int> pleasantness, int variety)
  {
    int ret = pleasantness.size();

    for (int i=1; i<pleasantness.size(); i++)
      {
	bool found = false;
	for (int j=0; j<i; j++)
	  {
	    if (abs(pleasantness[i] - pleasantness[j]) >= variety)
	      {
		ret = min(getProbNum(j, i), ret);
		found = true;
	      }
	  }
	if (found)
	  break;
      }

    return ret;
  }

   
  // BEGIN CUT HERE
public:
  void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
private:
  template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
  void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
  void test_case_0() { int Arr0[] = {1, 2, 3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 2; verify_case(0, Arg2, minNumber(Arg0, Arg1)); }
  void test_case_1() { int Arr0[] = {1, 2, 3, 4, 5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; int Arg2 = 3; verify_case(1, Arg2, minNumber(Arg0, Arg1)); }
  void test_case_2() { int Arr0[] = {10, 1, 12, 101}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 100; int Arg2 = 3; verify_case(2, Arg2, minNumber(Arg0, Arg1)); }
  void test_case_3() { int Arr0[] = {10, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 9; int Arg2 = 2; verify_case(3, Arg2, minNumber(Arg0, Arg1)); }
  void test_case_4() { int Arr0[] = {6, 2, 6, 2, 6, 3, 3, 3, 7}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; int Arg2 = 2; verify_case(4, Arg2, minNumber(Arg0, Arg1)); }

  // END CUT HERE

};

// BEGIN CUT HERE
int main() {
ProblemsToSolve ___test;
___test.run_test(-1);
}
// END CUT HERE 
