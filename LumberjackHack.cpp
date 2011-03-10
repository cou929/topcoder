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

  bool isInRange(int x, int y) {
    if (0 <= x && x < river.size() && 0 <= y && y < river[0].size())
      return true;
    return false;
  }

  int search(int x, int y, bool can_jump) {
    int ret = INF;
    int dx[8] = {-1 , 0, 1, 0, -2, 0, 2, 0};
    int dy[8] = {0 , -1, 0, 1, 0, -2, 0, 2};
    int nextx = 0, nexty = 0;
    int i;

    cout << "[head] " << y << ", " << x << ", " << can_jump << endl;

    // for (i=0; i<river.size(); i++) {
    //   for (int j=0; j<river[0].size(); j++) {
    //     cout << visited[i][j];
    //   }
    //   cout << endl;
    // }
    // cout << endl;

    if (y == 0 || y + 1 == river[0].size())
      return 0;

    for (i=0; i<4; i++) {
      nextx = x + dx[i], nexty = y + dy[i];
      cout << nexty << " " << nextx << " " << y << " " << x << " " << i << endl;
      if (isInRange(nextx, nexty) &&
          !visited[nextx][nexty]) {
        visited[nextx][nexty] = 1;
        if (river[nextx][nexty] == '|') {
          if (i == 0 || i == 2) {
            ret = min(ret, 1 + search(nextx, nexty, can_jump));  // move vertically
            //            cout << "[move1] " << ret << " " << nexty << " " << nextx << endl;
          } else if (i == 1 || i == 3) {
            ret = min(ret, 2 + search(nextx, nexty, can_jump));  // move horizonally
            //            cout << "[move2] " << ret << " " << nexty << " " << nextx << endl;
          }
        } else {
          if (can_jump)
            ret = min(ret, 3 + search(nextx, nexty, false));
        }
        visited[nextx][nexty] = 1;
      }
      // if (!isInRange(nextx, nexty) &&
      //     i % 2 == 1) {
      //   if (i == 1 || i == 3) {
      //     ret = min(ret, 0);  // goal one step
      //     cout << "[goal1] " << ret << " " << nexty << " " << nextx << endl;
      //   } else if ((i == 5 || i == 7) &&
      //              river[nextx - (nextx / 2)][nexty - (nexty / 2)] != '|' &&
      //              can_jump == true) {
      //     cout << "[goal2] " << ret << " " << nexty << " " << nextx << " | " << y << " " << x << ", " << can_jump << endl;
      //     ret = min(ret, 3);  // goal with jump
      //     cout << "[goal2] " << ret << " " << nexty << " " << nextx << " | " << y << " " << x << ", " << can_jump << endl;
      //   }
      // }
    }

    //    cout << ret << endl;

    return ret;
  }

  int timeToShore(vector <string> riverMap) {
    int ret;
    int startx = 0, starty = 0;
    int i, j;
    river = riverMap;
    memset(visited, 0, sizeof(visited));


    for (i=0; i<riverMap.size(); i++)
      for (j=0; j<riverMap[0].size(); j++)
        if (riverMap[i][j] == '+')
          startx = i, starty = j;

    visited[startx][starty] = 1;

    for (i=0; i<river.size(); i++) {
      cout << river[i] << endl;
    }

    ret = search(startx, starty, true);

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
___test.run_test(2);
}
// END CUT HERE 
