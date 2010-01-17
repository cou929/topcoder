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
class BattleshipChecker {
public:
#define NONE 0
#define RIGHT 1
#define DOWN 2

  bool occpied[10][10];
  vector <string> board;
  int dirs[8][2];

  bool inRange(int x, int y)
  {
    bool ret = false;

    if (0 <= x && x < board.size() && 0 <= y && y < board[0].size())
      ret = true;

    return ret;
  }

  int s(int x, int y, int dir)
  {
    occpied[x][y] = true;

    for (int i=0; i<8; i++)
      {
	if ( inRange(x+dirs[i][0], y+dirs[i][1]) && board[x+dirs[i][0]][y+dirs[i][1]] == 'X')
	  {
	    if ((i == 0 || i == 4) && dir == DOWN)
	      continue;
	    else if ((i == 2 || i == 6) && dir == RIGHT)
	      continue;

	    return -11;
	  }
      }

    bool isEnd = false;
    if (dir == RIGHT && inRange(x, y+1) && board[x][y+1] == '.' ||
	dir == DOWN && inRange(x+1, y) && board[x+1][y] == '.' ||
	((dir == RIGHT && !inRange(x, y+1)) || (dir == DOWN && !inRange(x+1, y))) ||
	dir == NONE )
      isEnd = true;

    if (isEnd)
      return 1;
    else
      {
	int nextx = x, nexty = y;
	if (dir == RIGHT)
	  nexty++;
	else
	  nextx++;

	return 1 + s(nextx, nexty, dir);
      }
  }

  int search(int x, int y)
  {
    int dir = NONE;

    if (inRange(x, y+1) && board[x][y+1] == 'X')
      dir = RIGHT;
    if (inRange(x+1, y) && board[x+1][y] == 'X')
      dir = DOWN;

    return s(x, y, dir);
  }

  string checkBoard(vector <string> _board)
  {
    int ret = 0;
    int ships[4];
    memset(ships, 0, sizeof(ships));
    memset(occpied, false, sizeof(occpied));
    board = _board;
    dirs[0][0] =  1; dirs[0][1] = 0;
    dirs[1][0] =  1; dirs[1][1] = 1;
    dirs[2][0] =  0; dirs[2][1] = 1;
    dirs[3][0] = -1; dirs[3][1] = 1;
    dirs[4][0] = -1; dirs[4][1] = 0;
    dirs[5][0] = -1; dirs[5][1] = -1;
    dirs[6][0] =  0; dirs[6][1] = -1;
    dirs[7][0] =  1; dirs[7][1] = -1;

    for (int i=0; i<board.size(); i++)
      for (int j=0; j<board[0].size(); j++)
	if (board[i][j] == 'X' && !occpied[i][j])
	  {
	    int res = search(i, j);

	    if (res <= 0 || 4 < res)
	      return "REJECTED";
	    else
	      ships[res-1]++;
	  }

    for (int i=0; i<4; i++)
      if (ships[i] != 4-i)
	return "REJECTED";

    for (int i=0; i<board.size(); i++)
      {
	int c1 = 0, c2 = 0;
      for (int j=0; j<board[0].size(); j++)
	{
	  if (board[i][j] == 'X')
	    c1++;
	  if (board[j][i] == 'X')
	    c2++;
	}

      if (c1 == 0)
	ret++;
      if (c2 == 0)
	ret++;
      }

    char c[100];
    sprintf(c, "ACCEPTED, %d POINTS", ret);
    string strRet = c;
    return strRet;
  }
   
  // BEGIN CUT HERE
public:
  void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
private:
  template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
  void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
  void test_case_0() { string Arr0[] = {"......X...",
					".XXX..X...",
					"......X...",
					"X.X...X...",
					"X.........",
					"...XX.X...",
					"......X...",
					".XX...X...",
					"..........",
					".X.X..X..."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "ACCEPTED, 5 POINTS"; verify_case(0, Arg1, checkBoard(Arg0)); }
  void test_case_1() { string Arr0[] = {"X.X.X.X...",
					"......X...",
					".XX...X...",
					"......X...",
					"......X..X",
					"...X..X...",
					"...X..X...",
					"......X...",
					"..XX..X...",
					"......X..."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "REJECTED"; verify_case(1, Arg1, checkBoard(Arg0)); }
  void test_case_2() { string Arr0[] = {".....XX...",
					".XX.......",
					"..........",
					".X....XXX.",
					".X........",
					".....X....",
					"..X..X....",
					".....X....",
					"...X......",
					"X.....XXXX"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "REJECTED"; verify_case(2, Arg1, checkBoard(Arg0)); }
  void test_case_3() { string Arr0[] = {".....XX..X",
					".XX......X",
					"..........",
					".X....XXX.",
					".X........",
					".....X..X.",
					"..X..X....",
					".....X....",
					"...X......",
					"X.....XXXX"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "REJECTED"; verify_case(3, Arg1, checkBoard(Arg0)); }
  void test_case_4() { string Arr0[] = {"X.......X.",
					"...XXXX...",
					".X......X.",
					"....XX....",
					".........X",
					".........X",
					".....XXX..",
					".........X",
					"..X......X",
					"..X......X"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "ACCEPTED, 0 POINTS"; verify_case(4, Arg1, checkBoard(Arg0)); }
  void test_case_5() { string Arr0[] = {"X.......X.",
					"...XXXX...",
					".X......X.",
					"....XX....",
					"...X.....X",
					"...X.....X",
					".....XXX..",
					".........X",
					".........X",
					".........X"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "REJECTED"; verify_case(5, Arg1, checkBoard(Arg0)); }

  // END CUT HERE

};
// BEGIN CUT HERE
int main() {
BattleshipChecker ___test;
___test.run_test(-1);
}
// END CUT HERE 
