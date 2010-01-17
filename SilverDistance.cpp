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
class SilverDistance {
  // 将棋の銀将が無限大の盤上に置かれている. スタート, ゴールの座標が与えられるので, 最短何手でゴールまで行けるかを求める.
  // スタートからゴールまでgreedyに一手ずつ進んでいく方針です. 行けるところまでは斜めに進み, syとgyの差が0だったら右下, 右上, 右下, ... のようにジグザグに進みます. またgx - sx == 0 で gy - sy > 0 のような真下に進まなければいけない場合は, 右下, 左下, 右下, ... のようにジグザグに進みます.
public:
  int minSteps(int sx, int sy, int gx, int gy) {
    int ret = 0;
    int curx = sx, cury = sy;
   
    while (!(curx == gx && cury == gy)) {
      int dirx = 0;
      int diry = 0;

      if (gx - curx > 0)
        dirx = 1;
      else if (gx - curx < 0)
        dirx = -1;

      if (gy - cury > 0)
        diry = 1;
      else
        diry = -1;

      if (dirx == 0 && diry == -1)
        dirx = 1;

      curx += dirx;
      cury += diry;
      ret++;
    }

    return ret;
  }
   
  // BEGIN CUT HERE
public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 0; int Arg1 = 0; int Arg2 = 0; int Arg3 = -2; int Arg4 = 2; verify_case(0, Arg4, minSteps(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 0; int Arg1 = 0; int Arg2 = -4; int Arg3 = 3; int Arg4 = 5; verify_case(1, Arg4, minSteps(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 0; int Arg1 = 0; int Arg2 = 5; int Arg3 = 8; int Arg4 = 8; verify_case(2, Arg4, minSteps(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = -487617; int Arg1 = 826524; int Arg2 = 892309; int Arg3 = -918045; int Arg4 = 1744571; verify_case(3, Arg4, minSteps(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arg0 = -27857; int Arg1 = 31475; int Arg2 = -27857; int Arg3 = 31475; int Arg4 = 0; verify_case(4, Arg4, minSteps(Arg0, Arg1, Arg2, Arg3)); }

  // END CUT HERE

};
// BEGIN CUT HERE
int main() {
SilverDistance ___test;
___test.run_test(-1);
}
// END CUT HERE 
