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
class CreatePairs {
public:
  int maximalSum(vector <int> data)
  {
    int ret = 0;
    int zeros = 0;
    int ones = 0;
    vector <int> negative;
    vector <int> positive;

    for (int i=0; i<data.size(); i++)
      if (data[i] == 0)
	zeros++;
      else if (data[i] == 1)
	ones++;
      else if (data[i] > 1)
	positive.push_back(data[i]);
      else
	negative.push_back(data[i]);

    sort(negative.begin(), negative.end());
    sort(positive.rbegin(), positive.rend());

    for (int i=0; i<positive.size(); i++)
      {
	if (i+1 < positive.size())
	  {
	    ret += positive[i] * positive[i+1];
	    i++;
	  }
	else
	  ret += positive[i];
      }

    for (int i=0; i<negative.size(); i++)
      {
	if (i+1 < negative.size())
	  {
	    ret += negative[i] * negative[i+1];
	    i++;
	  }
	else
	  {
	    if (zeros > 0)
	      zeros--;
	    else
	      ret += negative[i];
	  }
      }

    ret += ones;

    return ret;
  }
  // BEGIN CUT HERE
public:
  void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 4)) test_case_5(); }
private:
  template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
  void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
  void test_case_0() { int Arr0[] = {0, 1, 2, 4, 3, 5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 27; verify_case(0, Arg1, maximalSum(Arg0)); }
  void test_case_1() { int Arr0[] = {-1, 1, 2, 3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; verify_case(1, Arg1, maximalSum(Arg0)); }
  void test_case_2() { int Arr0[] = {-1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -1; verify_case(2, Arg1, maximalSum(Arg0)); }
  void test_case_3() { int Arr0[] = {-1, 0, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(3, Arg1, maximalSum(Arg0)); }
  void test_case_4() { int Arr0[] = {1, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(4, Arg1, maximalSum(Arg0)); }
  void test_case_5() { int Arr0[] = {-2, -2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(5, Arg1, maximalSum(Arg0)); }

  // END CUT HERE
};
// BEGIN CUT HERE
int main() {
CreatePairs ___test;
___test.run_test(-1);
}
// END CUT HERE 
