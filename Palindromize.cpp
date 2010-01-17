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

class Palindromize {
public:
  bool isPalindrome(string s)
  {
    for (int i=0; i<s.size()/2; i++)
      if (s[i] != s[s.size() - 1 - i])
	return false;

    return true;
  }

  string minAdds(string s)
  {
    string ret;

    for (int i=0; i<s.size(); i++)
      {
	string sub = s.substr(0, i);
	reverse(sub.begin(), sub.end());
	if (isPalindrome(s + sub))
	  {
	    ret = s + sub;
	    break;
	  }
      }

    return ret;
  }

   
  // BEGIN CUT HERE
public:
  void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
private:
  template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
  void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
  void test_case_0() { string Arg0 = "add"; string Arg1 = "adda"; verify_case(0, Arg1, minAdds(Arg0)); }
  void test_case_1() { string Arg0 = "cigartragic"; string Arg1 = "cigartragic"; verify_case(1, Arg1, minAdds(Arg0)); }
  void test_case_2() { string Arg0 = "redocpot"; string Arg1 = "redocpotopcoder"; verify_case(2, Arg1, minAdds(Arg0)); }
  void test_case_3() { string Arg0 = "acaba"; string Arg1 = "acabaca"; verify_case(3, Arg1, minAdds(Arg0)); }
  void test_case_4() { string Arg0 = "abczyxyz"; string Arg1 = "abczyxyzcba"; verify_case(4, Arg1, minAdds(Arg0)); }

  // END CUT HERE

};

// BEGIN CUT HERE
int main() {
Palindromize ___test;
___test.run_test(-1);
}
// END CUT HERE 
