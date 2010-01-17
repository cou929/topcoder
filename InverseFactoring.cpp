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
class InverseFactoring {
public:
  int getTheNumber(vector <int> factors)
  {
    int ret;

    sort(factors.begin(), factors.end());
    int maxi = factors[factors.size()-1];

    for (int t=2; ; t++)
      {
	ret = maxi*t;
	vector <int> props;
	for (int i=2; i*2<=ret; i++)
	  {
	    if (ret % i == 0)
	      props.push_back(i);
	  }

	bool ok = true;
	for (int i=0; i<min(props.size(), factors.size()); i++)
	  if (props.size() != factors.size() || props[i] != factors[i])
	    {
	      ok = false;
	      break;
	    }

	for (int i=0; i<factors.size(); i++)
	  if (factors[i] == ret)
	    {
	      ok = false;
	      break;
	    }

	if (ok)
	  break;
      }

    return ret;
  }
   
  // BEGIN CUT HERE
public:
  void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 3)) test_case_4(); }
private:
  template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
  void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
  void test_case_0() { int Arr0[] = {2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(0, Arg1, getTheNumber(Arg0)); }
  void test_case_1() { int Arr0[] = {4,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 8; verify_case(1, Arg1, getTheNumber(Arg0)); }
  void test_case_2() { int Arr0[] = {3,4,2,12,6,8}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 24; verify_case(2, Arg1, getTheNumber(Arg0)); }
  void test_case_3() { int Arr0[] = {14,26456,2,28,13228,3307,7,23149,8,6614,46298,56,4,92596}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 185192; verify_case(3, Arg1, getTheNumber(Arg0)); }
  void test_case_4() { int Arr0[] = {3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 9; verify_case(0, Arg1, getTheNumber(Arg0)); }

  // END CUT HERE

};
// BEGIN CUT HERE
int main() {
InverseFactoring ___test;
___test.run_test(-1);
}
// END CUT HERE 
