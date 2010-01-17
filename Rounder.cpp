// BEGIN CUT HERE
// END CUT HERE
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>

using namespace std;

class Rounder {
   public:
   int round(int n, int b)
  {
    int i;
    int ret = 0;

    int div = n / b;

    int small = b * div;
    int large = small + b;

    ret = large;
    if ((n - small) < (large - n))
      ret = small;

    return ret;
   }

   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 5; int Arg1 = 10; int Arg2 = 10; verify_case(0, Arg2, round(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 4; int Arg1 = 10; int Arg2 = 0; verify_case(1, Arg2, round(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 100; int Arg1 = 3; int Arg2 = 99; verify_case(2, Arg2, round(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 123456; int Arg1 = 7; int Arg2 = 123459; verify_case(3, Arg2, round(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 49; int Arg1 = 7; int Arg2 = 49; verify_case(4, Arg2, round(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
Rounder ___test;
___test.run_test(-1);
}
// END CUT HERE 
