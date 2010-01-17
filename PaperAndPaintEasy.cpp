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
class PaperAndPaintEasy {
public:
  long long computeArea(int width, int height, int xfold, int cnt, int x1, int y1, int x2, int y2)
  {
    long long color = 0;

    if (xfold > width/2)
      xfold = width - xfold;

    if (xfold <= x1)
      {
	color += ((long long)x2 - x1) * (cnt + 1);
      }
    else if (x2 <= xfold)
      {
	color += ((long long)x2 - x1) * (cnt + 1) * 2;
      }
    else
      {
	color += ((long long)xfold - x1) * (cnt + 1) * 2;
	color += ((long long)x2 - xfold) * (cnt + 1);
      }

    color *= (y2 - y1);

    return (long long)width * (long long)height - color;
  }
   
  // BEGIN CUT HERE
public:
  void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); 
    if ((Case == -1) || (Case == 5)) test_case_5(); 
    if ((Case == -1) || (Case == 5)) test_case_6(); 
  }
private:
  template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
  void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
  void test_case_0() { int Arg0 = 5; int Arg1 = 6; int Arg2 = 2; int Arg3 = 2; int Arg4 = 1; int Arg5 = 1; int Arg6 = 3; int Arg7 = 2; long long Arg8 = 21LL; verify_case(0, Arg8, computeArea(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7)); }
  void test_case_1() { int Arg0 = 3; int Arg1 = 13; int Arg2 = 1; int Arg3 = 0; int Arg4 = 1; int Arg5 = 8; int Arg6 = 2; int Arg7 = 12; long long Arg8 = 35LL; verify_case(1, Arg8, computeArea(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7)); }
  void test_case_2() { int Arg0 = 12; int Arg1 = 12; int Arg2 = 7; int Arg3 = 3; int Arg4 = 3; int Arg5 = 1; int Arg6 = 6; int Arg7 = 2; long long Arg8 = 124LL; verify_case(2, Arg8, computeArea(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7)); }
  void test_case_3() { int Arg0 = 4; int Arg1 = 5; int Arg2 = 4; int Arg3 = 0; int Arg4 = 0; int Arg5 = 0; int Arg6 = 1; int Arg7 = 1; long long Arg8 = 19LL; verify_case(3, Arg8, computeArea(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7)); }
  void test_case_4() { int Arg0 = 4; int Arg1 = 8; int Arg2 = 4; int Arg3 = 3; int Arg4 = 0; int Arg5 = 1; int Arg6 = 2; int Arg7 = 2; long long Arg8 = 24LL; verify_case(4, Arg8, computeArea(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7)); }
  void test_case_5() { int Arg0 = 4; int Arg1 = 8; int Arg2 = 3; int Arg3 = 0; int Arg4 = 1; int Arg5 = 1; int Arg6 = 3; int Arg7 = 2; long long Arg8 = 30LL; verify_case(5, Arg8, computeArea(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7)); }
  void test_case_6() { int Arg0 = 523558807; int Arg1 = 418626050; int Arg2 = 309432663; int Arg3 = 37; int Arg4 = 116654897; int Arg5 = 3157497; int Arg6 = 261252008; int Arg7 = 6989421; long long Arg8 = 184202986320132254LL; verify_case(6, Arg8, computeArea(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7)); }

  // END CUT HERE

};
// BEGIN CUT HERE
int main() {
PaperAndPaintEasy ___test;
___test.run_test(-1);
}
// END CUT HERE 
