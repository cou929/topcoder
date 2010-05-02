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
class Palindromize3 {
public:
  pair <int, string> ret;

  int r(string s, int pos, int num, vector <char> pushed) {
    if (pos > s.size() / 2) {
      if (ret > make_pair(num, s))
        ret = make_pair(num, s);
      return 0;
    }

    if (s[pos] == s[s.size() - 1 - pos]) {
      r(s, pos + 1, num, pushed);
    } else {
      char tmp = s[pos];
      s[pos] = s[s.size() - 1 - pos];
      if (find(pushed.begin(), pushed.end(), s[s.size() - 1 - pos]) == pushed.end()) {
        vector <char> tmpv = pushed;
        tmpv.push_back(s[s.size() - 1 - pos]);
        r(s, pos + 1, num + 1, tmpv);
      } else {
        r(s, pos + 1, num, pushed);
      }
      s[pos] = s[s.size() - 1 - pos] = tmp;
      if (find(pushed.begin(), pushed.end(), tmp) == pushed.end()) {
        vector <char> tmpv = pushed;
        tmpv.push_back(tmp);
        r(s, pos + 1, num + 1, tmpv);
      } else {
        r(s, pos + 1, num, pushed);
      }
    }

    return 0;
  }

  string getPalindrome(string s) {
    ret = make_pair(1000, string (s.size(), 'z'));

    r(s, 0, 0, vector <char> (0));

    return ret.second;
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
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { 
    string Arg0 = "aszsbsz"; 
    string Arg1 = "zszszsz"; 
    verify_case(0, Arg1, getPalindrome(Arg0)); }
	void test_case_1() { 
    string Arg0 = "ababab"; 
    string Arg1 = "aaaaaa"; 
    verify_case(1, Arg1, getPalindrome(Arg0)); }
	void test_case_2() { 
    string Arg0 = "topcoderopen"; 
    string Arg1 = "nepooeeoopen"; 
    verify_case(2, Arg1, getPalindrome(Arg0)); }
	void test_case_3() { 
    string Arg0 = "dfiuwifuqwieubaoiewhroiahw"; 
    string Arg1 = "wfiiwifueiieuueiieufiwiifw"; 
    verify_case(3, Arg1, getPalindrome(Arg0)); }
	void test_case_4() { 
    string Arg0 = "aszsbsz"; 
    string Arg1 = "zszszsz"; 
    verify_case(4, Arg1, getPalindrome(Arg0)); }
	void test_case_5() { 
    string Arg0 = "abcdefghijklmnopqrstuvwxyzabcde"; 
    string Arg1 = "zszszsz"; 
    verify_case(5, Arg1, getPalindrome(Arg0)); }

  // END CUT HERE

};
// BEGIN CUT HERE
int main() {
Palindromize3 ___test;
___test.run_test(-1);
}
// END CUT HERE 
