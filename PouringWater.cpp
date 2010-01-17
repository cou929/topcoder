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

class PouringWater {
public:
  int countBit(int N)
  {
    int n = N;
    int counter = 0;

    while (n)
      {
	if (n & 1)
	  counter++;
	n = n >> 1;
      }

    return counter;
  }

  int getMinBottles(int N, int K)
  {
    for (int i=0;;i++)
      {
	if (countBit(N+i) <= K)
	  return i;
      }

    return -1;
  }
   
  // BEGIN CUT HERE
public:
  void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
private:
  template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
  void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
  void test_case_0() { int Arg0 = 3; int Arg1 = 1; int Arg2 = 1; verify_case(0, Arg2, getMinBottles(Arg0, Arg1)); }
  void test_case_1() { int Arg0 = 13; int Arg1 = 2; int Arg2 = 3; verify_case(1, Arg2, getMinBottles(Arg0, Arg1)); }
  void test_case_2() { int Arg0 = 1000000; int Arg1 = 5; int Arg2 = 15808; verify_case(2, Arg2, getMinBottles(Arg0, Arg1)); }

  // END CUT HERE

};

// BEGIN CUT HERE
int main() {
PouringWater ___test;
___test.run_test(-1);
}
// END CUT HERE 
