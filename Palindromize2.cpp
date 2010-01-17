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

using namespace std;

class Palindromize2 {
public:
  string minChanges(string s)
  {
    for (int i=0; i<s.size()/2; i++)
      {
	if (s[i] > s[s.size() - 1 - i])
	  s[i] = s[s.size() - 1 - i];
	else if (s[i] < s[s.size() - 1 - i])
	  s[s.size() - 1 - i] = s[i];
      }
    return s;
  }

   
  // BEGIN CUT HERE
public:
  void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
private:
  template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
  void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
  void test_case_0() { string Arg0 = "ameba"; string Arg1 = "abeba"; verify_case(0, Arg1, minChanges(Arg0)); }
  void test_case_1() { string Arg0 = "cigartragic"; string Arg1 = "cigartragic"; verify_case(1, Arg1, minChanges(Arg0)); }
  void test_case_2() { string Arg0 = "abcdef"; string Arg1 = "abccba"; verify_case(2, Arg1, minChanges(Arg0)); }
  void test_case_3() { string Arg0 = "cxbpaxz"; string Arg1 = "cxapaxc"; verify_case(3, Arg1, minChanges(Arg0)); }

  // END CUT HERE

};

// BEGIN CUT HERE
int main() {
Palindromize2 ___test;
___test.run_test(-1);
}
// END CUT HERE 
