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
class CrazyBot {
public:
  map <pair <int, int>, bool> visited;
  int N;
  double ret;
  double ea, we, so, no;

  int s(double p, int walk, pair <int, int> cur)
  {
    if (visited.find(cur) != visited.end())
      return 0;

    if (walk == N)
      {
	ret += p;
	return 0;
      }

    visited[cur] = true;
    pair <int, int> tmp = cur;
    if (ea != 0)
      {
	tmp = cur;
	tmp.first++;
	s(p*ea, walk+1, tmp);
      }

    if (we != 0)
      {
	tmp = cur;
	tmp.first--;
	s(p*we, walk+1, tmp);
      }

    if (so != 0)
      {
	tmp = cur;
	tmp.second--;
	s(p*so, walk+1, tmp);
      }

    if (no != 0)
      {
	tmp = cur;
	tmp.second++;
	s(p*no, walk+1, tmp);
      }

    visited.erase(cur);

    return 0;
  }

  double getProbability(int n, int east, int west, int south, int north)
  {
    N = n;
    ret = 0;
    ea = east/100.0, we = west/100.0, so = south/100.0, no = north/100.0;

    pair <int, int> start;
    start.first = 0;
    start.second = 0;
    s(1, 0, start);    

    return ret;
  }
   
  // BEGIN CUT HERE
public:
  void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
private:
  template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
  void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
  void test_case_0() { int Arg0 = 1; int Arg1 = 25; int Arg2 = 25; int Arg3 = 25; int Arg4 = 25; double Arg5 = 1.0; verify_case(0, Arg5, getProbability(Arg0, Arg1, Arg2, Arg3, Arg4)); }
  void test_case_1() { int Arg0 = 2; int Arg1 = 25; int Arg2 = 25; int Arg3 = 25; int Arg4 = 25; double Arg5 = 0.75; verify_case(1, Arg5, getProbability(Arg0, Arg1, Arg2, Arg3, Arg4)); }
  void test_case_2() { int Arg0 = 7; int Arg1 = 50; int Arg2 = 0; int Arg3 = 0; int Arg4 = 50; double Arg5 = 1.0; verify_case(2, Arg5, getProbability(Arg0, Arg1, Arg2, Arg3, Arg4)); }
  void test_case_3() { int Arg0 = 14; int Arg1 = 50; int Arg2 = 50; int Arg3 = 0; int Arg4 = 0; double Arg5 = 1.220703125E-4; verify_case(3, Arg5, getProbability(Arg0, Arg1, Arg2, Arg3, Arg4)); }
  void test_case_4() { int Arg0 = 14; int Arg1 = 25; int Arg2 = 25; int Arg3 = 25; int Arg4 = 25; double Arg5 = 0.008845493197441101; verify_case(4, Arg5, getProbability(Arg0, Arg1, Arg2, Arg3, Arg4)); }

  // END CUT HERE

};
// BEGIN CUT HERE
int main() {
CrazyBot ___test;
___test.run_test(-1);
}
// END CUT HERE 
