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
#include <numeric>
// BEGIN CUT HERE
#include "cout.hpp"
// END CUT HERE 
using namespace std;
class MegadiamondHunt {
public:
  map <string, int> memo;

  int getValue(string mine) {
    int ret = 0;
    vector <int> pos;
    int i, j;
    int n = mine.size();

    if (memo.find(mine) != memo.end())
      return memo[mine];

    for (i=0; i<n-1; i++)
      if (mine[i] == '<' && mine[i+1] == '>')
        pos.push_back(i);

    if (pos.size() == 0)
      return 0;

    for (i=0; i<pos.size(); i++) {
      int size = 1;
      int left = pos[i] - 1, right = pos[i] + 2;
      while (left >= 0 && right < n) {
        if (mine[left] == '<' && mine[right] == '>')
          size++;
        else
          break;
        left--, right++;
      }
      string tmp;
      for (j=0; j<n; j++)
        if (j < pos[i] - size + 1 || pos[i] + size < j)
          tmp.push_back(mine[j]);

      ret = max(ret, getValue(tmp) + size*size);
    }

    memo[mine] = ret;

    return ret;
  }
   
  // BEGIN CUT HERE
public:
	void run_test(int Case) { 
    if ((Case == -1) || (Case == 0)) test_case_0();
    if ((Case == -1) || (Case == 1)) test_case_1();
    if ((Case == -1) || (Case == 2)) test_case_2();
    if ((Case == -1) || (Case == 3)) test_case_3();
    if ((Case == -1) || (Case == 4)) test_case_4();
    if ((Case == -1) || (Case == 5)) test_case_5();
  }
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { 
    string Arg0 = "><<><>>><"; 
    int Arg1 = 5; 
    verify_case(0, Arg1, getValue(Arg0)); }
	void test_case_1() { 
    string Arg0 = "<<><<>><<>>>"; 
    int Arg1 = 14; 
    verify_case(1, Arg1, getValue(Arg0)); }
	void test_case_2() { 
    string Arg0 = ">>>>>><<<<<<<"; 
    int Arg1 = 0; 
    verify_case(2, Arg1, getValue(Arg0)); }
	void test_case_3() { 
    string Arg0 = "<<<<<<><><><<<<>>><><><<>><<<><<>><<<>>><<<<<>>>>>"; 
    int Arg1 = 57; 
    verify_case(3, Arg1, getValue(Arg0)); }
	void test_case_4() { 
    string Arg0 = "<<<<<<<<<<>><>>>><>>><<<>><>>>><<><<>><>>>>>>><>>>"; 
    int Arg1 = 124; 
    verify_case(4, Arg1, getValue(Arg0)); }
	void test_case_5() { 
    string Arg0 = "><<><>>><"; 
    int Arg1 = 5; 
    verify_case(5, Arg1, getValue(Arg0)); }

  // END CUT HERE

};
// BEGIN CUT HERE
int main() {
MegadiamondHunt ___test;
___test.run_test(-1);
}
// End CUT HERE 
