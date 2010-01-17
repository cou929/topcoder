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
class TheCardLineDivTwo {
public:
  int size;
  long long memo[16][1<<16];
  int graph[16][16];

  long long r(int pos, int flg) {
    long long ret = 0;
    if (memo[pos][flg] != -1)
      return memo[pos][flg];

    if (flg == (1 << size)-1)
      return 1;

    for (int i=0; i<size; i++)
      if (graph[pos][i] == 1 && !(flg & (1 << i))) {
        int next_flg = (flg | (1 << i));
        ret += r(i, next_flg);
      }

    return memo[pos][flg] = ret % 1234567891;
  }

  int count(vector <string> cards) {
    int ret = 0;
    size = cards.size();
    memset(memo, -1, sizeof(memo));
    memset(graph, 0, sizeof(graph));

    for (int i=0; i<cards.size(); i++)
      if (cards[i][1] == 'S' || cards[i][1] == 'C')
        cards[i][1] = 'B';
      else
        cards[i][1] = 'R';

    for (int i=0; i<cards.size(); i++)
      for (int j=0; j<cards.size(); j++)
        if (i != j && (cards[i][0] == cards[j][0] || cards[i][1] == cards[j][1]))
          graph[i][j] = 1;

    for (int i=0; i<cards.size(); i++)
      ret = (ret + r(i, (1 << i))) % 1234567891;

    return ret;
  }
   
  // BEGIN CUT HERE
public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"AS", "1S", "2S", "3S", "4S", "5S", "6S", "6S", "8S", "AC", "2C", "3C", "4C", "5C", "6C", "7C", "8C"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(0, Arg1, count(Arg0)); }
	void test_case_1() { string Arr0[] = {"JS", "JC", "JD", "JH"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 24; verify_case(1, Arg1, count(Arg0)); }
	void test_case_2() { string Arr0[] = {"2S", "3C", "4C", "5S", "6C", "7S", "8S", "9H"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(2, Arg1, count(Arg0)); }
	void test_case_3() { string Arr0[] = {"KD", "KC", "AD", "7C", "AH", "9C", "4H", "4S", "AS"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2416; verify_case(3, Arg1, count(Arg0)); }

  // END CUT HERE

};
// BEGIN CUT HERE
int main() {
TheCardLineDivTwo ___test;
___test.run_test(-1);
}
// END CUT HERE 
