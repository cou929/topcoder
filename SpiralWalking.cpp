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
class SpiralWalking {
public:
  vector <string> LM;

  bool inRange(int x, int y)
  {
    if (0 <= x && x < LM.size() && 0 <= y && y < LM[0].size())
      return true;
    return false;
  }

  int totalPoints(vector <string> levelMap)
  {
    LM = levelMap;
    int ret = 0;
    int x = 0, y = 0;
    int dirx[4] = {0, 1, 0, -1};
    int diry[4] = {1, 0, -1, 0};
    int dirindex = 0;
    bool visited[levelMap.size()][levelMap[0].size()];
    memset(visited, false, sizeof(visited));

    while (1)
      {
	visited[x][y] = true;

	int i = 0;
	if (inRange(x + dirx[(dirindex)%4], y + diry[(dirindex)%4]) && !visited[x + dirx[(dirindex)%4]][ y + diry[(dirindex)%4]])
	  ret += levelMap[x][y] - '0';
	else if (inRange(x + dirx[(1 + dirindex)%4], y + diry[(1 + dirindex)%4]) && !visited[x + dirx[(1 + dirindex)%4]][ y + diry[(1 + dirindex)%4]])
	  i = 1;
	else
	  break;

	dirindex = (dirindex + i) % 4;
	x += dirx[dirindex];
	y += diry[dirindex];
      }

    ret += levelMap[x][y] - '0';

    return ret;
  }
   
  // BEGIN CUT HERE
public:
  void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
private:
  template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
  void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
  void test_case_0() { string Arr0[] = {"111",
					"111",
					"111"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; verify_case(0, Arg1, totalPoints(Arg0)); }
  void test_case_1() { string Arr0[] = {"101",
					"110"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(1, Arg1, totalPoints(Arg0)); }
  void test_case_2() { string Arr0[] = {"00",
					"10"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(2, Arg1, totalPoints(Arg0)); }
  void test_case_3() { string Arr0[] = {"86850",
					"76439",
					"15863",
					"24568",
					"45679",
					"71452",
					"05483"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 142; verify_case(3, Arg1, totalPoints(Arg0)); }

  // END CUT HERE

};
// BEGIN CUT HERE
int main() {
SpiralWalking ___test;
___test.run_test(-1);
}
// END CUT HERE 
