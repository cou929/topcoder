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
class ThePalindrome {
public:
  int find(string s)
  {
    string rest = "";

    for (int i=1; i<s.size(); i++)
      {
	if (rest == "")
	  {
	    rest = s.substr(0, i);
	    reverse(rest.begin(), rest.end());
	  }
	else
	  {
	    if (s[i] == rest[0])
	      rest.erase(0, 1);
	    else
	      rest.insert(0, 1, s[i-1]);
	  }

	for (int j=0; j<=i; j++)
	  cout << s[j];
	cout << " " << rest << endl;
      }

    return s.size() + rest.size();
  }
   
  // BEGIN CUT HERE
public:
  void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
private:
  template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
  void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
  void test_case_0() { string Arg0 = "abab"; int Arg1 = 5; verify_case(0, Arg1, find(Arg0)); }
  void test_case_1() { string Arg0 = "abacaba"; int Arg1 = 7; verify_case(1, Arg1, find(Arg0)); }
  void test_case_2() { string Arg0 = "qwerty"; int Arg1 = 11; verify_case(2, Arg1, find(Arg0)); }
  void test_case_3() { string Arg0 = "abdfhdyrbdbsdfghjkllkjhgfds"; int Arg1 = 38; verify_case(3, Arg1, find(Arg0)); }

  // END CUT HERE

};
// BEGIN CUT HERE
int main() {
ThePalindrome ___test;
___test.run_test(0);
}
// END CUT HERE 
