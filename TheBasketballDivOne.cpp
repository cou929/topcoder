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
class TheBasketballDivOne {
public:
  int table[5][5];
  int N, M;
  set <vector <int> > seq;

  int calcWins() {
    vector <int> results;

    for (int i=0; i<N; i++) {
      int wins = 0;
      for (int j=0; j<N; j++)
        if (i != j) {
          if (table[i][j] == 1) wins++;
          if (table[j][i] == 0) wins++;
        }
      results.push_back(wins);
    }

    sort (results.begin(), results.end());

    if (results[results.size()-1] == M)
      seq.insert(results);

    return 0;
  }

  int r(int row, int col) {
    int next_row = row, next_col = col + 1;
    if (row +1 == N && col + 1 == N) {
      calcWins();
      return 0;
    }
    if (col + 1 == N) {
      next_row = row + 1;
      next_col = 0;
    }
    if (row != col) {
      r(next_row, next_col);
      table[row][col] = 1;
    }
    r(next_row, next_col);
    table[row][col] = 0;

    return 0;
  }

  int find(int n, int m) {
    memset(table, 0, sizeof(table));
    seq.clear();
    N = n, M = m;

    r(0, 0);

    return seq.size();
  }
   
  // BEGIN CUT HERE
public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 1; int Arg2 = 1; verify_case(0, Arg2, find(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 1; int Arg2 = 0; verify_case(1, Arg2, find(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 3; int Arg1 = 3; int Arg2 = 2; verify_case(2, Arg2, find(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 4; int Arg1 = 6; int Arg2 = 5; verify_case(3, Arg2, find(Arg0, Arg1)); }

  // END CUT HERE

};
// BEGIN CUT HERE
int main() {
TheBasketballDivOne ___test;
___test.run_test(-1);
}
// END CUT HERE 
