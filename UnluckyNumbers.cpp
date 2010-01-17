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

using namespace std;

class UnluckyNumbers {
public:
  int getCount(vector <int> luckySet, int n)
  {
    int i;
    int ret = 0;
    int u=0, l;

    sort(luckySet.begin(), luckySet.end());

    for (i=0; i<luckySet.size(); i++)
      {
	if (luckySet[i] == n)
	  return ret;

	if (luckySet[i] > n)
	  {
	    u = luckySet[i]-1;

	    if (i>0)
	      l = luckySet[i-1] + 1;
	    else
	      l = 1;
	    break;
	  }
      }


    ret = (n-l)*(u-n+1) + (u-n);

    return ret;
  }

   
  // BEGIN CUT HERE
public:
  void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
private:
  template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
  void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
  void test_case_0() { int Arr0[] = {1, 7, 14, 10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 4; verify_case(0, Arg2, getCount(Arg0, Arg1)); }
  void test_case_1() { int Arr0[] = {4, 8, 13, 24, 30}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; int Arg2 = 5; verify_case(1, Arg2, getCount(Arg0, Arg1)); }
  void test_case_2() { int Arr0[] = {10, 20, 30, 40, 50}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 30; int Arg2 = 0; verify_case(2, Arg2, getCount(Arg0, Arg1)); }
  void test_case_3() { int Arr0[] = {3, 7, 12, 18, 25, 100, 33, 1000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 59; int Arg2 = 1065; verify_case(3, Arg2, getCount(Arg0, Arg1)); }

  // END CUT HERE

};

// BEGIN CUT HERE
int main() {
UnluckyNumbers ___test;
___test.run_test(-1);
}
// END CUT HERE 
