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
class NextPalindromicNumber {
public:
  bool isPal(string s)
  {
    if (s.size() == 1)
      return true;

    for (int i=0; i<s.size()/2; i++)
      if (s[i] != s[s.size() - 1 - i])
	return false;

    return true;
  }

  string plusone(string s)
  {
    bool up = true;
    for (int i=1; i<=s.size(); i++)
      {
	if (s[s.size()-i] != '9')
	  {
	    int c = s[s.size()-i] - '0';
	    s[s.size()-i] = c + 1 + '0';
	    up = false;
	    break;
	  }
	else
	  s[s.size()-i] = '0';
      }

    if (up)
      s.insert(s.begin(), '1');

    return s;
  }

  string getNext(string n)
  {
    while (1)
      {
	n = plusone(n);
	if (isPal(n))
	  break;
      }

    return n;
  }
   
  // BEGIN CUT HERE
public:
  void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
private:
  template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
  void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
  void test_case_0() { string Arg0 = "12345"; string Arg1 = "12421"; verify_case(0, Arg1, getNext(Arg0)); }
  void test_case_1() { string Arg0 = "858"; string Arg1 = "868"; verify_case(1, Arg1, getNext(Arg0)); }
  void test_case_2() { string Arg0 = "1999"; string Arg1 = "2002"; verify_case(2, Arg1, getNext(Arg0)); }
  void test_case_3() { string Arg0 = "1"; string Arg1 = "2"; verify_case(3, Arg1, getNext(Arg0)); }
  void test_case_4() { string Arg0 = "9999"; string Arg1 = "10001"; verify_case(4, Arg1, getNext(Arg0)); }
  void test_case_5() { string Arg0 = "1234567890123456789012345678901234567890"; string Arg1 = "10001"; verify_case(4, Arg1, getNext(Arg0)); }

  // END CUT HERE

};
// BEGIN CUT HERE
int main() {
NextPalindromicNumber ___test;
___test.run_test(-1);
}
// END CUT HERE 
