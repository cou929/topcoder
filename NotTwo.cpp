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
class NotTwo {
public:
  int maxStones(int width, int height)
  {
    int ret = 0;
    int board[width][height];
    memset(board, 0, sizeof(board));
    int dirx[2] = {0, -2};
    int diry[2] = {-2, 0};

    for (int i=0; i<width; i++)
      for (int j=0; j<height; j++)
        {
          int flg = 0;
          for (int k=0; k<2; k++)
            {
              int curx = i + dirx[k];
              int cury = j + diry[k];
              if (0 <= curx && curx < width && 0 <= cury && cury < height && board[curx][cury] != 0)
                continue;
              flg++;
            }

          if (flg == 2)
            {
              board[i][j] = 1;
              ret++;
            }
        }

    return ret;
  }
   
  // BEGIN CUT HERE
public:
  void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
private:
  template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
  void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
  void test_case_0() { int Arg0 = 3; int Arg1 = 2; int Arg2 = 4; verify_case(0, Arg2, maxStones(Arg0, Arg1)); }
  void test_case_1() { int Arg0 = 3; int Arg1 = 3; int Arg2 = 5; verify_case(1, Arg2, maxStones(Arg0, Arg1)); }
  void test_case_2() { int Arg0 = 8; int Arg1 = 5; int Arg2 = 20; verify_case(2, Arg2, maxStones(Arg0, Arg1)); }

  // END CUT HERE

};
// BEGIN CUT HERE
int main() {
NotTwo ___test;
___test.run_test(-1);
}
// END CUT HERE 
