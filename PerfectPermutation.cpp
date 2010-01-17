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
class PerfectPermutation {
public:
  vector <int> P;
  int visited[50];

  int dfs(int pos) {
    if (visited[pos] == 0) {
      visited[pos] = 1;
      dfs(P[pos]);
    }
    return 0;
  }

  int reorder(vector <int> _P) {
    int ret = 0;
    P = _P;
    memset(visited, 0, sizeof(visited));

    for (int i=0; i<P.size(); i++)
      if (visited[i] == 0) {
        dfs(i);
        ret++;
      }
    
    if (ret == 1) ret--;
    return ret;
  }
   
  // BEGIN CUT HERE
public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {2, 0, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(0, Arg1, reorder(Arg0)); }
	void test_case_1() { int Arr0[] = {2, 0, 1, 4, 3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(1, Arg1, reorder(Arg0)); }
	void test_case_2() { int Arr0[] = {2, 3, 0, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(2, Arg1, reorder(Arg0)); }
	void test_case_3() { int Arr0[] = {0, 5, 3, 2, 1, 4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(3, Arg1, reorder(Arg0)); }
	void test_case_4() { int Arr0[] = {4, 2, 6, 0, 3, 5, 9, 7, 8, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; verify_case(4, Arg1, reorder(Arg0)); }

  // END CUT HERE

};
// BEGIN CUT HERE
int main() {
PerfectPermutation ___test;
___test.run_test(-1);
}
// END CUT HERE 
