// BEGIN CUT HERE
// todo: row/col
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
const int INF = 2000000000;
class LumberjackHack {
public:
  vector <string> river;
  int visited[51][51];

  bool isInRange(int a, int b) {
    if (0 <= a && a < river.size() && 0 <= b && b < river[0].size())
      return true;
    return false;
  }

  int search(int row, int col, bool can_water) {
    int ret = INF;
    int dr[4] = {0, -1, 0, 1};
    int dc[4] = {-1, 0, 1, 0};
    int nr = 0;
    int nc = 0;
    int i;

    if (col == 0 || col + 1 == river[0].size())
      return 0;

    visited[row][col] = 1;
    for (i=0; i<4; i++) {
      nr = row + dr[i], nc = col + dc[i];
     
      if (isInRange(nr, nc) && visited[nr][nc] == 0) {
        if (river[nr][nc] == '|') {
          if (i == 0 || i == 2)
            ret = min(ret, 2 + search(nr, nc, can_water));
          else if (i == 1 || i == 3)
            ret = min(ret, 1 + search(nr, nc, can_water));
        } else if (river[nr][nc] == '.') {
          if (can_water)
            ret = min(ret, 3 + search(nr, nc, false));
        }
      }
    }

    visited[row][col] = 0;

    return ret;
  }

  int timeToShore(vector <string> riverMap) {
    int ret;
    int startr = 0, startc = 0;
    int i, j;
    river = riverMap;
    memset(visited, 0, sizeof(visited));

    for (i=0; i<riverMap.size(); i++)
      for (j=0; j<riverMap[0].size(); j++)
        if (riverMap[i][j] == '+')
          startr = i, startc = j;

    visited[startr][startc] = 1;

    ret = search(startr, startc, true);

    if (ret == INF)
      ret = -1;
        
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
	if ((Case == -1) || (Case == 8)) test_case_8();
}
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { 
	string Arr0[] = {".+.",
 "||."}; 
	vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
	int Arg1 = 3; 
	verify_case(0, Arg1, timeToShore(Arg0)); }
	void test_case_1() { 
	string Arr0[] = {"..+",
 "||."}; 
	vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
	int Arg1 = 0; 
	verify_case(1, Arg1, timeToShore(Arg0)); }
	void test_case_2() { 
	string Arr0[] = {"....|||",
 "....|..",
 "...||..",
 "||.+...",
 "...|...",
 "...||||"}; 
	vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
	int Arg1 = 7; 
	verify_case(2, Arg1, timeToShore(Arg0)); }
	void test_case_3() { 
	string Arr0[] = {"||.|....",
 "........",
 ".|.+|..|",
 "...|....",
 "|..|.|.|"}; 
	vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
	int Arg1 = -1; 
	verify_case(3, Arg1, timeToShore(Arg0)); }
	void test_case_4() { 
	string Arr0[] = {".........|.|.|.|.|..||...||.|..|.||...|.|.|||...||",
 ".||.||...||..|||.....|.||||...|.|.|.|.|..|...|.|||",
 "||.|.|..||.||....|.....|.||.|||||.|.|.||.|||||.|..",
 "|.....|.|.||||.||..|.|..|..|.|||||.....||.|.||....",
 "..|..||...||.|.......|||+||.||||....||||.....|..||",
 "...||..||||.|......||..|.|||||.|.|||||.||..|||...|",
 "|||...|..|..|.|||.||.|..|...||.|||..|..||.|.||....",
 "|..|||||||||.||.....|..|.|.|||||...||...|.|.|||||.",
 ".|..||...|||............|.|..|||.||.|||.||..||.|||",
 ".|.|||...||..|..|...||.||..|..|||||.|.|...||..||.|",
 "||||.|||.|..||||..|..||...|..||.|.||||...|...|.|..",
 ".||..||...|.....|||.|||||..||......|.||.||.|..||..",
 "|.|||....|||||.|..|..|.|||..|.||.||.|.|.|.|..||...",
 ".||.||||||...||||||..||....|..||.|||..||...|.|||||",
 ".||||.|....|...|.||..||..|||.|||||....|...||.|.||.",
 ".|...|..||....||...|.||||.....||||.||.|||||||..|||",
 ".||||...|...|..||...|...|...|.|..|.|.|..|..|||.||.",
 ".|.|||..||||||||........|||||||||.|.|........|||||",
 ".....|...||.||...|||...||||..|||...||....||..||.||",
 "||...||..||.||...||...||||..|.|..|...|||..||..|||.",
 "|..||||.||..|...|....||||||...|||.|.|||||..|||...|",
 ".....|||..||.|||.....||..||||...|||||.||.|.||..|||",
 "|..|.||..|..||..||..|...|..|.||..||||..|...||..|..",
 "||.|..|.|||||...|...|.|..|||||...|.......|.||.||||",
 ".|.....|.|||||.....|||...|..|||||...|.||..||.|||.|",
 ".|...||....|||...|||.||.|.|......|........|.||||||",
 "..|.|.|.|||||..|||..|.........|...|.|.|...||.....|",
 ".|.|.|.|..|.|||||||||||.|.|||....|||||...|.||||.|.",
 "|.|||....|.||||..||......|..|||||.....||.|..||..|.",
 "||.||.|||.|......|..|.|...|..||.|||..||.....|.|..|",
 ".||||..|.|.||||.|||.||.||.....|....|....||...|..||",
 ".....|||...||.||.||....|.||..||....|....|||||.|..|",
 "|.|.|||||...|.||..|..|..|.|..|.|........||..|.|.||",
 "....|..|.|..|.||||||....||||.|.||||||.|.|.|.......",
 "||||....|..|...||..||||||||...|.|||||.|.|||.|...||",
 "|...|.|..|..|..|....|..||..|||....||..||..|..|..|.",
 "|||||....|.||.|..|.||..|||..|.|.|..||.|...|.|..||.",
 "..|.|||.|.||..|...|||.|..|||..||...||...||||.....|",
 "..||||.|.|.....|||..||||..|.||||..|..|||.....||.||",
 "|..|||||....|........|.||||.||..||||.|....|||||||.",
 ".|...||.|.||..|.|....|.||..|.|....|.|.||.||.||.|..",
 ".|..|..|.||||.||||....|||.....|.|...|.|...|...||..",
 "|..|||..|.||.|||..||.....|.|..|.|.|...|.....|.....",
 "||..||.|...|.||...|..|..||.|||.||.|.||...|....|||.",
 ".|....|.|||.|..|||..|.....|.||.||...|...||.......|",
 ".||..|||.|.|....|||...|..|.||.||.|.|...|||||.|.|.|",
 "|.|.||.||.|.|.||.|||.||....||.|||||.||.|.|||......",
 "|...|||...|.||||....|.||.||.|.........|..||.|..||.",
 ".|.....|.|.|....||.||...|||.|..||...||.|||.||.|.|.",
 "||.||.|||.|||..||......|......||..||||.|..||.||||."}; 
	vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
	int Arg1 = 63; 
	verify_case(4, Arg1, timeToShore(Arg0)); }
	void test_case_5() { 
	string Arr0[] = {".+."}; 
	vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
	int Arg1 = 3; 
	verify_case(5, Arg1, timeToShore(Arg0)); }
	void test_case_6() { 
	string Arr0[] = {"..+.."}; 
	vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
	int Arg1 = -1; 
	verify_case(6, Arg1, timeToShore(Arg0)); }
	void test_case_7() { 
	string Arr0[] = {".+.",
 "||."}; 
	vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
	int Arg1 = 3; 
	verify_case(7, Arg1, timeToShore(Arg0)); }
	void test_case_8() { 
	string Arr0[] = {".+.",
 "||."}; 
	vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
	int Arg1 = 3; 
	verify_case(8, Arg1, timeToShore(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
LumberjackHack ___test;
___test.run_test(4);
}
// END CUT HERE 
