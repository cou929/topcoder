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

class PersistentNumber {
public:
  string toStr(int n) {ostringstream ss; ss << n; return ss.str();}

  int getPersistence(int n)
  {
    int ret = 0;
    int d = n;

    while (d > 9)
      {
	string s = toStr(d);
	int tmp = 1;
	for (int i=0; i<s.size(); i++)
	  tmp *= s[i] - '0';
	d = tmp;
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
  void test_case_0() { int Arg0 = 99; int Arg1 = 2; verify_case(0, Arg1, getPersistence(Arg0)); }
  void test_case_1() { int Arg0 = 268; int Arg1 = 4; verify_case(1, Arg1, getPersistence(Arg0)); }
  void test_case_2() { int Arg0 = 1999999999; int Arg1 = 0; verify_case(2, Arg1, getPersistence(Arg0)); }
  void test_case_3() { int Arg0 = 68889789; int Arg1 = 3; verify_case(3, Arg1, getPersistence(Arg0)); }
  void test_case_4() { int Arg0 = 86898; int Arg1 = 7; verify_case(4, Arg1, getPersistence(Arg0)); }

  // END CUT HERE

};

// BEGIN CUT HERE
int main() {
PersistentNumber ___test;
___test.run_test(-1);
}
// END CUT HERE 
