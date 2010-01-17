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
class CollectingRiders {
public:
  int minimalMoves(vector <string> board) {
    const int INF = 100000;
    int ret = INF;
    int steps[board.size()][board[0].size()];
    int dirx[8] = {-2, -2, -1, 1, 2, 2, 1, -1};
    int diry[8] = {-1, 1, 2, 2, 1, -1, -2 ,-2};

    for (int row=0; row<board.size(); row++)
      for (int col=0; col<board[0].size(); col++) {
        queue <pair <int, int> > q;
        for (int i=0; i<board.size(); i++)
          for (int j=0; j<board[0].size(); j++)
            steps[i][j] = INF;
        q.push(make_pair(row, col));
        steps[row][col] = 0;

        while (!q.empty()) {
          pair <int, int> cur = q.front();
          q.pop();
          int cur_row = cur.first, cur_col = cur.second;

          for (int i=0; i<8; i++) {
            int next_row = cur_row + dirx[i], next_col = cur_col + diry[i];
            if (0 <= next_row && next_row < board.size() && 0 <= next_col && next_col < board[0].size() && steps[next_row][next_col] == INF) {
              steps[next_row][next_col] = steps[cur_row][cur_col] + 1;
              q.push(make_pair(next_row, next_col));
            }
          }
        }

        int number_of_step = 0;
        for (int i=0; i<board.size(); i++)
          for (int j=0; j<board[0].size(); j++)
            if (board[i][j] != '.')
              number_of_step += (steps[i][j] == INF) ? INF : ceil((double)steps[i][j] / (double)(board[i][j] - '0'));

        ret = min(ret, number_of_step);
      }

    if (ret >= INF) ret = -1;

    return ret;
  }
   
  // BEGIN CUT HERE
public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"1...1",
                                        "....."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(0, Arg1, minimalMoves(Arg0)); }
	void test_case_1() { string Arr0[] = {"........",
                                        ".1......",
                                        "........",
                                        "....3...",
                                        "........",
                                        "........",
                                        ".7......",
                                        "........"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(1, Arg1, minimalMoves(Arg0)); }
	void test_case_2() { string Arr0[] = {"..",
                                        "2.",
                                        ".."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(2, Arg1, minimalMoves(Arg0)); }
	void test_case_3() { string Arr0[] = {".1....1."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -1; verify_case(3, Arg1, minimalMoves(Arg0)); }
	void test_case_4() { string Arr0[] = {"9133632343",
                                        "5286698232",
                                        "8329333369",
                                        "5425579782",
                                        "4465864375",
                                        "8192124686",
                                        "3191624314",
                                        "5198496853",
                                        "1638163997",
                                        "6457337215"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 121; verify_case(4, Arg1, minimalMoves(Arg0)); }

  // END CUT HERE

};
// BEGIN CUT HERE
int main() {
CollectingRiders ___test;
___test.run_test(-1);
}
// END CUT HERE 
