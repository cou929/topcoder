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
class LuckyTicketSubstring {
public:
  int maxLength(string s) {
    int ret = 0;

    for (int i=1; i<s.size(); i++) {
      int left_sum = 0, right_sum = 0;
      for (int j=1; i-j >= 0 && i+j-1 < s.size(); j++) {
        left_sum += s[i-j] - '0';
        right_sum += s[i+j-1] - '0';
        if (left_sum == right_sum)
          ret = max(ret, j*2);
      }
    }

    return ret;
  }
   
  // BEGIN CUT HERE
public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "123231"; int Arg1 = 6; verify_case(0, Arg1, maxLength(Arg0)); }
	void test_case_1() { string Arg0 = "74233285"; int Arg1 = 4; verify_case(1, Arg1, maxLength(Arg0)); }
	void test_case_2() { string Arg0 = "986561517416921217551395112859219257312"; int Arg1 = 36; verify_case(2, Arg1, maxLength(Arg0)); }
	void test_case_3() { string Arg0 = "11"; int Arg1 = 2; verify_case(3, Arg1, maxLength(Arg0)); }
	void test_case_4() { string Arg0 = "112"; int Arg1 = 2; verify_case(4, Arg1, maxLength(Arg0)); }

  // END CUT HERE

};
// BEGIN CUT HERE
int main() {
LuckyTicketSubstring ___test;
___test.run_test(-1);
}
// END CUT HERE 
