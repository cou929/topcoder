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
bool visited[50][50];
vector <string> maze;
int ret = 0;

class MazeWanderingEasy {
public:
  int r(int x, int y)
  {
    stack <pair <int, int> > s;
    s.push(make_pair(x, y));

    while (!s.empty())
      {
        pair <int, int> cur;
        cur = s.top();
        s.pop();
      }
  }

  int decisions(vector <string> m)
  {
    maze = m;
    memset(visited, false, sizeof(visited));
    int x = 0, y = 0;

    for (int i=0; i<maze.size(); i++)
      for (int j=0; j<maze[0].size(); j++)
        if (maze[i][j] == 'M')
          {
            x = i;
            y = j;
          }

    r(x, y);

    return ret;
  }
   
  // BEGIN CUT HERE
public:
  void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
private:
  template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
  void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
  void test_case_0() { string Arr0[] = {"*.M"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(0, Arg1, decisions(Arg0)); }
  void test_case_1() { string Arr0[] = {"*.M",
                                        ".X."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(1, Arg1, decisions(Arg0)); }
  void test_case_2() { string Arr0[] = {"...",
                                        "XMX",
                                        "..*"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(2, Arg1, decisions(Arg0)); }
  void test_case_3() { string Arr0[] = {".X.X......X",
                                        ".X*.X.XXX.X",
                                        ".XX.X.XM...",
                                        "......XXXX."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(3, Arg1, decisions(Arg0)); }
  void test_case_4() { string Arr0[] = {"..........*",
                                        ".XXXXXXXXXX",
                                        "...........",
                                        "XXXXXXXXXX.",
                                        "M.........."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(4, Arg1, decisions(Arg0)); }

  // END CUT HERE

};
// BEGIN CUT HERE
int main() {
MazeWanderingEasy ___test;
___test.run_test(-1);
}
// END CUT HERE 
