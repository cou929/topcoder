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
class TheTournamentDivOne {
public:
  int find(vector <int> points, int w, int d) {
    int ret = 0;

    for (int i=0; i<points.size(); i++) {
      int count = points[i] / w;
      for (int j=count; j>=0; j--)
        if ((points[i] - j * w) % d == 0) {
          ret += j;
          points[i] -= j * w;
          break;
        }
    }

    sort(points.rbegin(), points.rend());

    int count = 0;
    for (int i=0; i<points.size(); i++) {
      if (points[i] % d != 0)
        return -1;
      count += points[i];
      if (points[i] == 0)
        points.erase(points.begin() + i);
    }
    if (count % 2 == 1)
      return -1;

    while (!points.empty()) {
      int p = points[0];
      for (int i=1; i<points.size() && p > 0; i++) {
        if (points[i] == 0) {
          points.erase(points.begin() + i);
          break;
        }
        int next = abs(points[i] - p);
        p = points[i] = next;
        if (points[i] == 0)
          points.erase(points.begin() + i);
      }
      sort(points.rbegin(), points.rend());
    }

    ret += count / 2;

    return ret;
  }
   
  // BEGIN CUT HERE
public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {10, 1, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 1; int Arg3 = 6; verify_case(0, Arg3, find(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {1, 1, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 1; int Arg3 = -1; verify_case(1, Arg3, find(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {1, 4, 0, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 1; int Arg3 = 3; verify_case(2, Arg3, find(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = {8, 3, 8, 5, 9, 2, 7, 11}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 2; int Arg3 = 15; verify_case(3, Arg3, find(Arg0, Arg1, Arg2)); }

  // END CUT HERE

};
// BEGIN CUT HERE
int main() {
TheTournamentDivOne ___test;
___test.run_test(-1);
}
// END CUT HERE 
