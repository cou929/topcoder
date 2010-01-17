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
class Arrows {
public:
  string s;
  int getArrowLength(int pos, int dir)
  {
    int ret = 1;

    if (dir == 0)
      {
	for (int i=pos+1; i<s.size(); i++)
	  {
	    if (s[i] == '<' || s[i] == '>')
	      break;

	    if (s[i] == s[pos+1])
	      ret++;
	    else
	      break;
	  }
      } 
    else if (dir == 1)
      {
	for (int i=pos-1; i>=0; i--)
	  {
	    if (s[i] == '<' || s[i] == '>')
	      break;

	    if (s[i] == s[pos-1])
	      ret++;
	    else
	      break;
	  }
      }

    return ret;
  }

  int longestArrow(string _s)
  {
    s = _s;
    int ret = -1;
    for (int i=0; i<s.size(); i++)
      if (s[i] == '<')
	ret = max(ret, getArrowLength(i, 0));
      else if (s[i] == '>')
	ret = max(ret, getArrowLength(i, 1));

    return ret;
  }
  // BEGIN CUT HERE
public:
  void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
private:
  template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
  void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
  void test_case_0() { string Arg0 = "<--->--==>"; int Arg1 = 4; verify_case(0, Arg1, longestArrow(Arg0)); }
  void test_case_1() { string Arg0 = "<<<<<<<<<<"; int Arg1 = 1; verify_case(1, Arg1, longestArrow(Arg0)); }
  void test_case_2() { string Arg0 = "----==-"; int Arg1 = -1; verify_case(2, Arg1, longestArrow(Arg0)); }
  void test_case_3() { string Arg0 = "<----=====>"; int Arg1 = 6; verify_case(3, Arg1, longestArrow(Arg0)); }

  // END CUT HERE
};
// BEGIN CUT HERE
int main() {
  Arrows ___test;
  ___test.run_test(-1);
}
// END CUT HERE 
