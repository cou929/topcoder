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
class MarblesRegroupingEasy {
public:
  int minMoves(vector <string> boxes)
  {
    int ret = 100000;

    for (int jorker=0; jorker<boxes.size(); jorker++)
      {
	int tmp = 0;
	bool flg[boxes[0].size()];
	memset(flg, false, sizeof(flg));
	for (int i=0; i<boxes.size(); i++)
	  if (i != jorker)
	    {
	      int counter = 0;
	      int pos = 0;
	      for (int j=0; j<boxes[i].size(); j++)
		if (boxes[i][j] != '0')
		  {
		    counter++;
		    pos = j;
		  }

	      if (counter > 1)
		tmp++;
	      else if (counter == 1)
		{
		  if (!flg[pos])
		    flg[pos] = true;
		  else
		    tmp++;
		}
	    }

	ret = min(tmp, ret);
      }

    return ret;
  }
   
  // BEGIN CUT HERE
public:
  void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
private:
  template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
  void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
  void test_case_0() { string Arr0[] = {"20",
					"11"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(0, Arg1, minMoves(Arg0)); }
  void test_case_1() { string Arr0[] = {"11",
					"11",
					"10"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(1, Arg1, minMoves(Arg0)); }
  void test_case_2() { string Arr0[] = {"10",
					"10",
					"01",
					"01"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(2, Arg1, minMoves(Arg0)); }
  void test_case_3() { string Arr0[] = {"11",
					"11",
					"11",
					"10",
					"10",
					"01"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(3, Arg1, minMoves(Arg0)); }
  void test_case_4() { string Arr0[] = {"020008000070",
					"000004000000",
					"060000600000",
					"006000000362",
					"000720000000",
					"000040000000", 
					"004009003000",
					"000800000000", 
					"020030003000",
					"000500200000",
					"000000300000"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; verify_case(4, Arg1, minMoves(Arg0)); }

  // END CUT HERE

};
// BEGIN CUT HERE
int main() {
MarblesRegroupingEasy ___test;
___test.run_test(-1);
}
// END CUT HERE 
