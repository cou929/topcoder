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
class CompetitionStatistics {
public:
  int consecutiveGrowth(vector <int> ratingChanges)
  {
    int ret = 0;
    int increase = 0;

    for (int i=0; i<ratingChanges.size(); i++)
      if (ratingChanges[i] > 0)
	increase++;
      else
	{
	  ret = max(ret, increase);
	  increase = 0;
	}

    if (increase > 0)
      ret = max(ret, increase);

    return ret;
  }
   
  // BEGIN CUT HERE
public:
  void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
private:
  template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
  void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
  void test_case_0() { int Arr0[] = {30, 5, -5, 3, 3, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(0, Arg1, consecutiveGrowth(Arg0)); }
  void test_case_1() { int Arr0[] = {-1, -5, -9}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(1, Arg1, consecutiveGrowth(Arg0)); }
  void test_case_2() { int Arr0[] = {12, 0, 15, 73}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(2, Arg1, consecutiveGrowth(Arg0)); }
  void test_case_3() { int Arr0[] = {12, 1, 15, 73}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(3, Arg1, consecutiveGrowth(Arg0)); }
  void test_case_4() { int Arr0[] = {-6, 13, 15, -11, 12, 12, 33, 12, -1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(4, Arg1, consecutiveGrowth(Arg0)); }

  // END CUT HERE

};
// BEGIN CUT HERE
int main() {
CompetitionStatistics ___test;
___test.run_test(-1);
}
// END CUT HERE 
