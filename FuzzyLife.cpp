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
#include <numeric>
// BEGIN CUT HERE
#include "cout.hpp"
// END CUT HERE 
using namespace std;
class FuzzyLife {
public:
  int countAround(vector <string> &grid, int x, int y) {
    int ret = 0;
    int dx[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
    int dy[8] = {1, 1, 1, 0, -1, -1, -1, 0};
    int i;

    for (i=0; i<8; i++)
      if (0 <= x + dx[i] && x + dx[i] < grid.size() && 0 <= y + dy[i] && y + dy[i] < grid[0].size())
        if (grid[x + dx[i]][y + dy[i]] == '1')
          ret++;

    return ret;
  }

  int calc(vector <string> grid, int x, int y, int n, int m) {
    int ret = 0;
    vector <string> wide(grid.size() + 2, string (grid[0].size() + 2, '0'));
    int i, j;

    for (i=0; i<grid.size(); i++)
      for (j=0; j<grid[0].size(); j++)
        wide[i+1][j+1] = grid[i][j];

    for (i=0; i<n+2; i++)
      for (j=0; j<m+2; j++) {
        int num = countAround(wide, x+i, y+j);
        if (wide[x+i][y+j] == '1') {
          if (2 <= num && num <= 3)
            ret++;
        } else if (wide[x+i][y+j] == '0') {
          if (num == 3)
            ret++;
        }
      }

    return ret;
  }

  int survivingCells(vector <string> grid) {
    int ret = 0;
    int i, j;
    int n = grid.size(), m = grid[0].size();

    for (i=0; i<n; i++)
      for (j=0; j<m; j++)
        if (grid[i][j] == '?') {
          grid[i][j] = '1';
          int one = calc(grid, i, j, 1, 1);
          grid[i][j] = '0';
          int zero = calc(grid, i, j, 1, 1);
          if (one > zero)
            grid[i][j] = '1';
          else
            grid[i][j] = '0';
        }

    ret = calc(grid, 0, 0, grid.size(), grid[0].size());
    
    return ret;
  }
   
  // BEGIN CUT HERE
public:
	void run_test(int Case) { 
    if ((Case == -1) || (Case == 0)) test_case_0();
    if ((Case == -1) || (Case == 1)) test_case_1();
    if ((Case == -1) || (Case == 2)) test_case_2();
    if ((Case == -1) || (Case == 3)) test_case_3();
    if ((Case == -1) || (Case == 4)) test_case_4();
    if ((Case == -1) || (Case == 5)) test_case_5();
    if ((Case == -1) || (Case == 6)) test_case_6();
    if ((Case == -1) || (Case == 7)) test_case_7();
  }
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { 
    string Arr0[] = {"011",
                     "0?1",
                     "100"}; 
    vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
    int Arg1 = 5; 
    verify_case(0, Arg1, survivingCells(Arg0)); }
	void test_case_1() { 
    string Arr0[] = {"101",
                     "0?0",
                     "101"}; 
    vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
    int Arg1 = 4; 
    verify_case(1, Arg1, survivingCells(Arg0)); }
	void test_case_2() { 
    string Arr0[] = {"11",
                     "11"}; 
    vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
    int Arg1 = 4; 
    verify_case(2, Arg1, survivingCells(Arg0)); }
	void test_case_3() { 
    string Arr0[] = {"111",
                     "1?1",
                     "111"}; 
    vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
    int Arg1 = 8; 
    verify_case(3, Arg1, survivingCells(Arg0)); }
	void test_case_4() { 
    string Arr0[] = {"?11?",
                     "0110",
                     "1001",
                     "?11?"}; 
    vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
    int Arg1 = 12; 
    verify_case(4, Arg1, survivingCells(Arg0)); }
	void test_case_5() { 
    string Arr0[] = {"00100",
                     "01010",
                     "10?01",
                     "01010",
                     "00100"}; 
    vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
    int Arg1 = 12; 
    verify_case(5, Arg1, survivingCells(Arg0)); }
	void test_case_6() { 
    string Arr0[] = {"0110", "?00?", "0110"}; 
    vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
    int Arg1 = 6; 
    verify_case(6, Arg1, survivingCells(Arg0)); }
	void test_case_7() { 
    string Arr0[] = {"011",
                     "0?1",
                     "100"}; 
    vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
    int Arg1 = 5; 
    verify_case(7, Arg1, survivingCells(Arg0)); }

  // END CUT HERE

};
// BEGIN CUT HERE
int main() {
FuzzyLife ___test;
___test.run_test(-1);
}
// END CUT HERE 
