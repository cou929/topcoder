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
class BitStrings {
public:
  int maxStrings(vector <string> list, int numZeroes, int numOnes)
  {
    int ret = 0;
    int dp[numZeroes+1][numOnes+1];
    int tmpdp[numZeroes+1][numOnes+1];
    vector <vector <int> > items;

    memset(dp, 0, sizeof(dp));

    for (unsigned int i=0; i<list.size(); i++)
      {
	vector <int> tmp(2, 0);
	for (unsigned int j=0; j<list[i].size(); j++)
	  if (list[i][j] == '0')
	    tmp[0]++;
	  else
	    tmp[1]++;
	items.push_back(tmp);
      }

    for (unsigned int i=0; i<list.size(); i++)
      {
	memset(tmpdp, 0, sizeof(tmpdp));

	if (items[i][0] <= numZeroes && items[i][1] <= numOnes && dp[items[i][0]][items[i][1]] < 1)
	  tmpdp[items[i][0]][items[i][1]] = 1;

	for (int nz=0; nz<=numZeroes; nz++)
	  for (int no=0; no<=numOnes; no++)
	    if (dp[nz][no] > 0)
	      {
		if (nz + items[i][0] <= numZeroes &&
		    no + items[i][1] <= numOnes &&
		    dp[nz][no] + 1 > dp[nz + items[i][0]][no+items[i][1]])
		  tmpdp[nz + items[i][0]][no + items[i][1]] = dp[nz][no] + 1;
	      }

	for (int j=0; j<=numZeroes; j++)
	  for (int k=0; k<=numOnes; k++)
	    if (tmpdp[j][k] > 0)
	      dp[j][k] = max(tmpdp[j][k], dp[j][k]);
      }

    for (int i=0; i<=numZeroes; i++)
      for (int j=0; j<=numOnes; j++)
	ret = max(dp[i][j], ret);

    return ret;
  }
   
  // BEGIN CUT HERE
public:
  void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
private:
  template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
  void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
  void test_case_0() { string Arr0[] = {"1", "00", "100"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 1; int Arg3 = 2; verify_case(0, Arg3, maxStrings(Arg0, Arg1, Arg2)); }
  void test_case_1() { string Arr0[] = {"00", "110", "101"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 4; int Arg3 = 2; verify_case(1, Arg3, maxStrings(Arg0, Arg1, Arg2)); }
  void test_case_2() { string Arr0[] = {"111", "01", "11", "10", "101"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 9; int Arg3 = 5; verify_case(2, Arg3, maxStrings(Arg0, Arg1, Arg2)); }
  void test_case_3() { string Arr0[] = {"10101010101010101010101010101010101010101010101010",
					"10101010101010101010101010101010101010101010101010",
					"10101010101010101010101010101010101010101010101010",
					"10101010101010101010101010101010101010101010101010",
					"10101010101010101010101010101010101010101010101010",
					"10101010101010101010101010101010101010101010101010",
					"10101010101010101010101010101010101010101010101010",
					"10101010101010101010101010101010101010101010101010",
					"10101010101010101010101010101010101010101010101010",
					"10101010101010101010101010101010101010101010101010",
					"10101010101010101010101010101010101010101010101010",
					"10101010101010101010101010101010101010101010101010",
					"10101010101010101010101010101010101010101010101010",
					"10101010101010101010101010101010101010101010101010",
					"10101010101010101010101010101010101010101010101010",
					"10101010101010101010101010101010101010101010101010",
					"10101010101010101010101010101010101010101010101010",
					"10101010101010101010101010101010101010101010101010",
					"10101010101010101010101010101010101010101010101010",
					"10101010101010101010101010101010101010101010101010"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 500; int Arg2 = 500; int Arg3 = 20; verify_case(3, Arg3, maxStrings(Arg0, Arg1, Arg2)); }

  // END CUT HERE

};
// BEGIN CUT HERE
int main() {
BitStrings ___test;
___test.run_test(-1);
}
// END CUT HERE 
