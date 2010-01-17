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
class MarbleCollectionGame {
public:
  int memo[20][20];
  vector <string> b;

  int r(int x, int y, int score)
  {
    if (b[x][y] == '#')
      return -1;

    int curscore = 0;

    if (b[x][y] != 'L' && b[x][y] != 'U')
      curscore = b[x][y] - '0';

    if (memo[x][y] <= score + curscore)
      {
	memo[x][y] = max(score + curscore, memo[x][y]);

	if (b[x][y] == 'U')
	  {
	    if (x-1 >= 0 && b[x-1][y] != '#')
	      r(x-1, y, score + curscore);
	  }
	else if (b[x][y] == 'L')
	  {
	    if (y-1 >= 0 && b[x][y-1] != '#')
	      r(x, y-1, score + curscore);
	  }

	if (x+1 < b.size() && b[x+1][y] != '#' && b[x+1][y] != 'U')
	  r(x+1, y, score + curscore);
	if (y+1 < b[0].size() && b[x][y+1] != '#' && b[x][y+1] != 'L')
	  r(x, y+1, score + curscore);

      }

    return 0;
  }

  int collectMarble(vector <string> board)
  {
    int ret = 0;
    memset(memo, -1, sizeof(memo));
    b = board;

    r(0, 0, 0);

    for (int i=0; i<20; i++)
      for (int j=0; j<20; j++)
	ret = max(ret, memo[i][j]);

    return ret;
  }
   
  // BEGIN CUT HERE
public:
  void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
private:
  template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
  void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
  void test_case_0() { string Arr0[] = {"7"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 7; verify_case(0, Arg1, collectMarble(Arg0)); }
  void test_case_1() { string Arr0[] = {"0",
					"8"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 8; verify_case(1, Arg1, collectMarble(Arg0)); }
  void test_case_2() { string Arr0[] = {"264",
					"3LL"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 15; verify_case(2, Arg1, collectMarble(Arg0)); }
  void test_case_3() { string Arr0[] = {"8U4L9",
					"0183U",
					"U8#38",
					"2158#",
					"L65U7"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 44; verify_case(3, Arg1, collectMarble(Arg0)); }
  void test_case_4() { string Arr0[] = {"039LLLU",
					"953348#",
					"0L87#29",
					"718#4#U",
					"594U196"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 55; verify_case(4, Arg1, collectMarble(Arg0)); }

  // END CUT HERE

};
// BEGIN CUT HERE
int main() {
MarbleCollectionGame ___test;
___test.run_test(-1);
}
// END CUT HERE 
