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
class MaximumScoredNumber {
public:
  int getNumber(int lowerBound, int upperBound)
  {
    int ret = 0;
    set <int> squares;
    int n = 0;
    int maxscore = 0;

    for (int i=0; i*i<=upperBound/2; i++)
      for (int j=0; i*i+j*j <= upperBound; j++)
	squares.insert(i*i + j*j);

    while (n*n <= 10000)
      {
	squares.insert(n*n);
	n++;
      }

    for (int i=lowerBound; i<=upperBound; i++)
      {
	int local = 0;
	for (int j=0; j*j<=i/2; j++)
	  {
	    if (find(squares.begin(), squares.end(), (i-j*j)) != squares.end())
	      local++;
	  }

	if (maxscore <= local)
	  {
	    maxscore = local;
	    ret = i;
	  }
      }

    return ret;
  }
   
  // BEGIN CUT HERE
public:
  void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 4)) test_case_5(); }
private:
  template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
  void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
  void test_case_0() { int Arg0 = 0; int Arg1 = 2; int Arg2 = 2; verify_case(0, Arg2, getNumber(Arg0, Arg1)); }
  void test_case_1() { int Arg0 = 0; int Arg1 = 30; int Arg2 = 25; verify_case(1, Arg2, getNumber(Arg0, Arg1)); }
  void test_case_2() { int Arg0 = 0; int Arg1 = 0; int Arg2 = 0; verify_case(2, Arg2, getNumber(Arg0, Arg1)); }
  void test_case_3() { int Arg0 = 5; int Arg1 = 99; int Arg2 = 85; verify_case(3, Arg2, getNumber(Arg0, Arg1)); }
  void test_case_4() { int Arg0 = 0; int Arg1 = 10000; int Arg2 = 9425; verify_case(4, Arg2, getNumber(Arg0, Arg1)); }
  void test_case_5() { int Arg0 = 5737; int Arg1 = 8673; int Arg2 = 8450; verify_case(4, Arg2, getNumber(Arg0, Arg1)); }

  // END CUT HERE

};
// BEGIN CUT HERE
int main() {
MaximumScoredNumber ___test;
___test.run_test(-1);
}
// END CUT HERE 
