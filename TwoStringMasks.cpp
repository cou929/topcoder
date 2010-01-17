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
class TwoStringMasks {
public:
  string shortestCommon(string s1, string s2)
  {
    string ret;
    int ast1 = 0, ast2 = 0;
    for (int i=0; i<s1.size(); i++)
      if (s1[i] == '*')
	{
	  ast1 = i;
	  break;
	}
    for (int i=0; i<s2.size(); i++)
      if (s2[i] == '*')
	{
	  ast2 = i;
	  break;
	}

    int lim = min(ast1, ast2);
    for (int i=0; i<lim; i++)
      if (s1[i] != s2[i])
	return "impossible";
    lim = min(s1.size() - ast1 - 1, s2.size() - ast2 - 1);
    for (int i=1; i<=lim; i++)
      if (s1[s1.size() - i] != s2[s2.size() - i])
	return "impossible";

    string head, tail;
    string s, ss;
    int pos = 0;
    if (ast1 < ast2)
      s = s1;
    else
      s = s2;

    if (s1.size() - ast1 - 1 < s2.size() - ast2 - 1)
      {
	ss = s1;
	pos = ast1;
      }
    else
      {
	ss = s2;
	pos = ast2;
      }

    head = s.substr(0, min(ast1, ast2));
    tail = ss.substr(pos+1);

    s1.erase(0, min(ast1, ast2));
    s1.erase(s1.size() - tail.size());
    s2.erase(0, min(ast1, ast2));
    s2.erase(s2.size() - tail.size());

    for (int i=0; i<s1.size(); i++)
      if (s1[i] == '*')
	s1.erase(i, 1);

    for (int i=0; i<s2.size(); i++)
      if (s2[i] == '*')
	s2.erase(i, 1);

    if (ast1 < ast2)
      {
	string tmp = s1;
	s1 = s2;
	s2 = tmp;
      }
      
    int samepos = 0;
    for (int i=1; i<=min(s1.size(), s2.size()); i++)
      {
	string st1, st2;
	st1 = s1.substr(s1.size() - i);
	st2 = s2.substr(0, i);
	if (st1 == st2)
	  samepos = i;
      }

    ret += head;
    ret += s1;
    ret += s2.substr(samepos);
    ret += tail;

    return ret;
  }
   
  // BEGIN CUT HERE
public:
  void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); if ((Case == -1) || (Case == 7)) test_case_7(); }
private:
  template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
  void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
  void test_case_0() { string Arg0 = "TOPC*DER"; string Arg1 = "T*PCODER"; string Arg2 = "TOPCODER"; verify_case(0, Arg2, shortestCommon(Arg0, Arg1)); }
  void test_case_1() { string Arg0 = "HELLO*"; string Arg1 = "HI*"; string Arg2 = "impossible"; verify_case(1, Arg2, shortestCommon(Arg0, Arg1)); }
  void test_case_2() { string Arg0 = "GOOD*LUCK"; string Arg1 = "*"; string Arg2 = "GOODLUCK"; verify_case(2, Arg2, shortestCommon(Arg0, Arg1)); }
  void test_case_3() { string Arg0 = "*SAMPLETEST"; string Arg1 = "THIRDSAMPLE*"; string Arg2 = "THIRDSAMPLETEST"; verify_case(3, Arg2, shortestCommon(Arg0, Arg1)); }
  void test_case_4() { string Arg0 = "*TOP"; string Arg1 = "*CODER"; string Arg2 = "impossible"; verify_case(4, Arg2, shortestCommon(Arg0, Arg1)); }
  void test_case_5() { string Arg0 = "*"; string Arg1 = "A*"; string Arg2 = "A"; verify_case(5, Arg2, shortestCommon(Arg0, Arg1)); }
  void test_case_6() { string Arg0 = "*A"; string Arg1 = "B*"; string Arg2 = "BA"; verify_case(6, Arg2, shortestCommon(Arg0, Arg1)); }
  void test_case_7() { string Arg0 = "LASTCASE*"; string Arg1 = "*LASTCASE"; string Arg2 = "LASTCASE"; verify_case(7, Arg2, shortestCommon(Arg0, Arg1)); }

  // END CUT HERE

};
// BEGIN CUT HERE
int main() {
TwoStringMasks ___test;
___test.run_test(-1);
}
// END CUT HERE 
