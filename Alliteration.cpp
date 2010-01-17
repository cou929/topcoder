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
class Alliteration {
public:
  int count(vector <string> words)
  {
    int ret = 0;
    char c = words[0][0];
    bool flg = false;

    for (int i=1; i<words.size(); i++)
      {
	char cc = words[i][0];
	if (c  == cc || c - 'a' == cc - 'A' || c - 'A' == cc - 'a')
	  flg = true;
	else
	  {
	    if (flg)
	      ret++;
	    flg = false;
	  }
	c = cc;
      }

    if (flg)
      ret++;

    return ret;
  }
  // BEGIN CUT HERE
public:
  void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
private:
  template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
  void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
  void test_case_0() { string Arr0[] = {"He", "has", "four", "fanatic", "fantastic", "fans"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(0, Arg1, count(Arg0)); }
  void test_case_1() { string Arr0[] = {"There", "may", "be", "no", "alliteration", "in", "a", "sequence"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(1, Arg1, count(Arg0)); }
  void test_case_2() { string Arr0[] = {"Round", "the", "rugged", "rock", "the", "ragged", "rascal", "ran"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(2, Arg1, count(Arg0)); }

  // END CUT HERE
};
// BEGIN CUT HERE
int main() {
Alliteration ___test;
___test.run_test(-1);
}
// END CUT HERE 
