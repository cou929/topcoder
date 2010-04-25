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
// BEGIN CUT HERE
#include "cout.hpp"
// END CUT HERE 
using namespace std;
class MazeOnFire {
public:
  bool inRange(int x, int y, int n, int m) {
    if (0 <= x && x < n && 0 <= y && y < m)
      return true;
    return false;
  }

  int maximumTurns(vector <string> maze) {
    //    int dirx[5] = {1, 0 -1, 0, 0};
    int dirx[5];
    dirx[0] = 1; dirx[1] = 0; dirx[2] = -1; dirx[3] = 0; dirx[4] = 0;
    //    int diry[5] = {0, 1, 0, -1, 0};
    int diry[5];
    diry[0] = 0; diry[1] = 1; diry[2] = 0; diry[3] = -1; diry[4] = 0;
    int i, j, k;
    int n = maze.size(), m = maze[0].size();
    int counter = 0;

    while (1) {
      counter++;


      vector <string> tmp = maze;
      for (i=0; i<n; i++)
        for (j=0; j<m; j++) {
          if (maze[i][j] == '.')
            for (k=0; k<4; k++)
              if (inRange(i + dirx[k], j + diry[k], n, m))
                if (maze[i + dirx[k]][j + diry[k]] == '$')
                  tmp[i][j] = '$';
          if (maze[i][j] == '.' || maze[i][j] == '$')
            for (k=0; k<4; k++)
              if (inRange(i + dirx[k], j + diry[k], n, m))
                if (maze[i + dirx[k]][j + diry[k]] == 'F')
                  tmp[i][j] = 'F';
        }

      if (tmp == maze)
        return -1;

      maze = tmp;

      bool flg = false;
      int numman = 0;
      for (i=0; i<n; i++)
        for (j=0; j<m; j++) {
          if (maze[i][j] == '.' || maze[i][j] == '$')
            flg = true;
          if (maze[i][j] == '$')
            numman++;
        }

      if (!flg || numman == 0)
        break;
    }

    return counter;
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
  }
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { 
    string Arr0[] = {"F..",
                     ".$.",
                     "..."}; 
    vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
    int Arg1 = 4; 
    verify_case(0, Arg1, maximumTurns(Arg0)); }
	void test_case_1() { 
    string Arr0[] = {".F#...",
                     "F....#",
                     ".F###.",
                     "F.#.$.",
                     "F.#..."}; 
    vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
    int Arg1 = -1; 
    verify_case(1, Arg1, maximumTurns(Arg0)); }
	void test_case_2() { 
    string Arr0[] = {"....#.",
                     "$##.#.",
                     ".#..#F",
                     ".F#.#.",
                     "..#..."}; 
    vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
    int Arg1 = 7; 
    verify_case(2, Arg1, maximumTurns(Arg0)); }
	void test_case_3() { 
    string Arr0[] = {"...$..",
                     "..#...",
                     "..###.",
                     "..#...",
                     "F.#.F."}; 
    vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
    int Arg1 = 7; 
    verify_case(3, Arg1, maximumTurns(Arg0)); }
	void test_case_4() { 
    string Arr0[] = {".F....F.",
                     ".#.##.#.",
                     ".#....#.",
                     "F.$##..F",
                     ".#....#.",
                     ".###.##.",
                     ".F....F."}; 
    vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
    int Arg1 = 4; 
    verify_case(4, Arg1, maximumTurns(Arg0)); }
	void test_case_5() { 
    string Arr0[] = {"F#....",
                     ".####.",
                     "......",
                     ".####.",
                     "$##..."}; 
    vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
    int Arg1 = 4; 
    verify_case(5, Arg1, maximumTurns(Arg0)); }
	void test_case_6() { 
    string Arr0[] = {"F..",
                     ".$.",
                     "..."}; 
    vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
    int Arg1 = 4; 
    verify_case(6, Arg1, maximumTurns(Arg0)); }

  // END CUT HERE

};
// BEGIN CUT HERE
int main() {
MazeOnFire ___test;
___test.run_test(-1);
}
// END CUT HERE 
