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
class LoveCalculator {
public:
  string findBoy(string girl, vector <string> boys)
  {
    int gL = 0; 
    int gO = 0; 
    int gV = 0;
    int gE = 0; 
    int maxi = 0;
    int ind = 0;

    sort(boys.begin(), boys.end());

    for (int i=0; i<girl.size(); i++)
      {
	if (girl[i] == 'L')
	  gL++;
	if (girl[i] == 'V')
	  gO++;
	if (girl[i] == 'O')
	  gV++;
	if (girl[i] == 'E')
	  gE++;
      }

    for (int i=0; i<boys.size(); i++)
      {
	int bL = 0;
	int bO = 0;
	int bV = 0;
	int bE = 0;

	for (int j=0; j<boys[i].size(); j++)
	  {
	    if (boys[i][j] == 'L')
	      bL++;
	    if (boys[i][j] == 'V')
	      bO++;
	    if (boys[i][j] == 'O')
	      bV++;
	    if (boys[i][j] == 'E')
	      bE++;
	  }

	int L = gL + bL;
	int O = gO + bO;
	int V = gV + bV;
	int E = gE + bE;

	int prob = ((L+O)*(L+V)*(L+E)*(O+V)*(O+E)*(V+E))%100;

	if (maxi < prob)
	  {
	    maxi = prob;
	    ind = i;
	  }
      }
    return boys[ind];
  }
   
  // BEGIN CUT HERE
public:
  void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
private:
  template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
  void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
  void test_case_0() { string Arg0 = "LOVE"; string Arr1[] = {"JACOB","FRANK","DANO"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "FRANK"; verify_case(0, Arg2, findBoy(Arg0, Arg1)); }
  void test_case_1() { string Arg0 = "JANE"; string Arr1[] = {"THOMAS","MICHAEL","INDY","LIU"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "INDY"; verify_case(1, Arg2, findBoy(Arg0, Arg1)); }
  void test_case_2() { string Arg0 = "LILLY"; string Arr1[] = {"PIERRE"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "PIERRE"; verify_case(2, Arg2, findBoy(Arg0, Arg1)); }
  void test_case_3() { string Arg0 = "MERYLOV"; string Arr1[] = {"JOHN","DAVE","STEVE","JOHN","DAVE"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "DAVE"; verify_case(3, Arg2, findBoy(Arg0, Arg1)); }
  void test_case_4() { string Arg0 = "LLOL"; string Arr1[] = {"BVERON","CVERON","AVERON","DVERON"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "AVERON"; verify_case(4, Arg2, findBoy(Arg0, Arg1)); }
  void test_case_5() { string Arg0 = "VELYLEOCEVE"; string Arr1[] = {"YVXHOVE","LCOKO","OGWSJVEVEDLE","WGFVSJEL","VLOLUVCBLLQVESWHEEKC"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "VLOLUVCBLLQVESWHEEKC"; verify_case(5, Arg2, findBoy(Arg0, Arg1)); }

  // END CUT HERE

};
// BEGIN CUT HERE
int main() {
LoveCalculator ___test;
___test.run_test(-1);
}
// END CUT HERE 
