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
class CubeWalking {
public:
  string finalPosition(string movement)
  {
    string color[3][3] = {{"RED", "BLUE", "RED"}, 
			  {"BLUE", "GREEN", "BLUE"}, 
			  {"RED", "BLUE", "RED"}};
    int walk[4][2] = {{0, 2}, {1, 0}, {0, 1}, {2, 0}};
    int x = 1, y = 1;
    int dir = 0;

    for (int i=0; i<movement.size(); i++)
      {
	if (movement[i] == 'L')
	  dir = (dir + 1) % 4;
	else if (movement[i] == 'R')
	  dir = (dir + 3) % 4;
	else
	  {
	    x = (x + walk[dir][0]) % 3;
	    y = (y + walk[dir][1]) % 3;
	  }
      }

    return color[x][y];
  }
   
  // BEGIN CUT HERE
public:
  void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
private:
  template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
  void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
  void test_case_0() { string Arg0 = "LLRR"; string Arg1 = "GREEN"; verify_case(0, Arg1, finalPosition(Arg0)); }
  void test_case_1() { string Arg0 = "WWWWWWWWWWWW"; string Arg1 = "GREEN"; verify_case(1, Arg1, finalPosition(Arg0)); }
  void test_case_2() { string Arg0 = "WLWRW"; string Arg1 = "RED"; verify_case(2, Arg1, finalPosition(Arg0)); }
  void test_case_3() { string Arg0 = "WWLLWRWLWLLRWW"; string Arg1 = "BLUE"; verify_case(3, Arg1, finalPosition(Arg0)); }

  // END CUT HERE

};
// BEGIN CUT HERE
int main() {
CubeWalking ___test;
___test.run_test(-1);
}
// END CUT HERE 
