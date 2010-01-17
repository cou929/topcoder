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
class KDoubleSubstrings {
public:
  int how(string str)
  {
    int ret = 0;
    int halfLen = str.size()/2;

    for (int i=0; i<halfLen; i++)
      if (str[i] != str[i + halfLen])
	ret++;

    return ret;
  }

  int howMuch(vector <string> str, int k)
  {
    int ret = 0;
    string whole;

    for (int i=0; i<str.size(); i++)
      whole += str[i];

    for (int i=2; i<=whole.size(); i+= 2)
      for (int j=0; j+i<=whole.size(); j++)
	{
	  string sub = whole.substr(j, i);
	  if (how(sub) <= k)
	    ret++;
	}

    return ret;
  }
   
  // BEGIN CUT HERE
public:
  void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
private:
  template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
  void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
  void test_case_0() { string Arr0[] = {"aa"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; int Arg2 = 1; verify_case(0, Arg2, howMuch(Arg0, Arg1)); }
  void test_case_1() { string Arr0[] = {"aaaa"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; int Arg2 = 4; verify_case(1, Arg2, howMuch(Arg0, Arg1)); }
  void test_case_2() { string Arr0[] = {"contest", "kontest"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 14; verify_case(2, Arg2, howMuch(Arg0, Arg1)); }
  void test_case_3() { string Arr0[] = {"abacaba", "d", "abacaba"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 34; verify_case(3, Arg2, howMuch(Arg0, Arg1)); }
  void test_case_4() { string Arr0[] = {"areyouready"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 18; verify_case(4, Arg2, howMuch(Arg0, Arg1)); }

  // END CUT HERE

};
// BEGIN CUT HERE
int main() {
KDoubleSubstrings ___test;
___test.run_test(-1);
}
// END CUT HERE 
