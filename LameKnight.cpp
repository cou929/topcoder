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
class LameKnight {
public:
  int maxCells(int height, int width) {
    int ret = 1;

    if (height >= 3 && width >= 7) {
      ret += 4 + width - 7;
    } else {
      if (height > 1 && width > 1 && height * width != 4) {
        if (height == 2) {
          if (width < 5)
            ret += 1;
          else if (width < 7)
            ret += 2;
          else
            ret += 3;
        } else {
          if (width == 2)
            ret += 1;
          else if (width == 3)
            ret += 2;
          else if (width < 7)
            ret += 3;
        }
      }
    }

    return ret;
  }
   
  // BEGIN CUT HERE
public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 100; int Arg1 = 50; int Arg2 = 48; verify_case(0, Arg2, maxCells(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 1; int Arg1 = 1; int Arg2 = 1; verify_case(1, Arg2, maxCells(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 17; int Arg1 = 5; int Arg2 = 4; verify_case(2, Arg2, maxCells(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 2; int Arg1 = 4; int Arg2 = 2; verify_case(3, Arg2, maxCells(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 1; int Arg1 = 5; int Arg2 = 1; verify_case(4, Arg2, maxCells(Arg0, Arg1)); }

  // END CUT HERE

};
// BEGIN CUT HERE
int main() {
LameKnight ___test;
___test.run_test(-1);
}
// END CUT HERE 
