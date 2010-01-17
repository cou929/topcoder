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
class SpidersOnTheGrid {
public:
  // free cells そのセルをスタート地点にしない限りは絶対に訪れることができないセル?
  // N, S の方向は絶対間違える

  int find(vector <string> A) {
    int ret = 0;
    bool ok[A.size()][A[0].size()];
    memset(ok, false, sizeof(ok));
    int dirx[4] = {-1, 1, 0, 0}; // NSEW
    int diry[4] = {0, 0, 1, -1};
    string dir = "NSEW";

    for (int i=0; i<A.size(); i++)
      for (int j=0; j<A[0].size(); j++) {
        int k = 0;
        for (k=0; k<4; k++)
          if (A[i][j] == dir[k])
            break;
        int nextx = i + dirx[k], nexty = j + diry[k];
        if (0 <= nextx && nextx < A.size() && 0 <= nexty && nexty < A[0].size())
          ok[nextx][nexty] = true;
      }

    for (int i=0; i<A.size(); i++)
      for (int j=0; j<A[0].size(); j++)
        if (!ok[i][j])
          ret++;

    return ret;
  }
   
  // BEGIN CUT HERE
public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"EW","NN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(0, Arg1, find(Arg0)); }
	void test_case_1() { string Arr0[] = {"EEEEEEEEEEEEEEEEEEEEEEEEEEEEEW"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(1, Arg1, find(Arg0)); }
	void test_case_2() { string Arr0[] = {"EW"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(2, Arg1, find(Arg0)); }
	void test_case_3() { string Arr0[] = {"ESW","ENW"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(3, Arg1, find(Arg0)); }
	void test_case_4() { string Arr0[] = {"E"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(4, Arg1, find(Arg0)); }

  // END CUT HERE

};
// BEGIN CUT HERE
int main() {
SpidersOnTheGrid ___test;
___test.run_test(-1);
}
// END CUT HERE 
