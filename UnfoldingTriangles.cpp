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
class UnfoldingTriangles {
public:
  vector <string> grid;

  bool isInRange(int x, int y) {
    if (0 <= x && x < grid.size() && 0 <= y && y < grid[0].size())
      return true;
    return false;
  }

  int solve(vector <string> _grid, int unfoldLimit) {
    int ret = 0;
    grid = _grid;

    for (int i=0; i<grid.size(); i++)
      reverse(grid[i].begin(), grid[i].end());
    reverse(grid.begin(), grid.end());

    for (int cur_row=0; cur_row<grid.size(); cur_row++) {
      for (int cur_col=0; cur_col<grid[cur_row].size(); cur_col++) {
        int limit = min(grid.size() - cur_row, grid[0].size() - cur_col);
        int max_size = 0;
        for (int length=1; length<=limit; length++) {
          int ulim = unfoldLimit;
          bool isValid = true;

          for (int i=0; i<length; i++)
            for (int j=0; j<length-i; j++) {
              char cur_grid = grid[cur_row + i][cur_col + j];
              // '.' grid not allowed
              if (cur_grid == '.') {
                isValid = false;
                goto ENDLOOP;
              }
              // hypotenuse grids must be '/'
              if (j == length-i-1 && cur_grid != '/') {
                isValid = false;
                goto ENDLOOP;
              }
              // grids which shares a side with triangle must not be '#'
              if (i == 0)
                if (isInRange(cur_row + i - 1, cur_col + j) && grid[cur_row + i - 1][cur_col + j] == '#') {
                  isValid = false;
                  goto ENDLOOP;
                }
              if (j == 0)
                if (isInRange(cur_row + i, cur_col + j - 1) && grid[cur_row + i][cur_col + j - 1] == '#') {
                  isValid = false;
                  goto ENDLOOP;
                }
              // grids which is in triangle and equal to '/' must be unfolded
              if (cur_grid == '/' && j < length-i-1)
                ulim--;
              if (ulim < 0) {
                isValid = false;
                goto ENDLOOP;
              }
            }
        ENDLOOP:
          // update max size
          if (isValid) {
            int cur_size = 0;
            for (int i=1; i<=length; i++) cur_size += i;
            max_size = max(max_size, cur_size);
          }
        }
        ret = max(ret, max_size);
      }
    }

    if (ret == 0) ret = -1;
    return ret;
  }
   
  // BEGIN CUT HERE
public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {".../",
                                        "../#",
                                        "./#/",
                                        "/#//"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; int Arg2 = 10; verify_case(0, Arg2, solve(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {".../",
                                        "../#",
                                        "./#/",
                                        "/#//"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 3; verify_case(1, Arg2, solve(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"////",
                                        "////",
                                        "////",
                                        "////"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; int Arg2 = 6; verify_case(2, Arg2, solve(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {".....#...",
                                        "....###.."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; int Arg2 = -1; verify_case(3, Arg2, solve(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"#//#",
                                        "#//#",
                                        "####",
                                        "///#"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; int Arg2 = 1; verify_case(4, Arg2, solve(Arg0, Arg1)); }
	void test_case_5() { string Arr0[] = {".../.../",
                                        "../#..//",
                                        "./.#.///",
                                        "/###...."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 6; verify_case(5, Arg2, solve(Arg0, Arg1)); }

  // END CUT HERE

};
// BEGIN CUT HERE
int main() {
UnfoldingTriangles ___test;
___test.run_test(-1);
}
// END CUT HERE 
