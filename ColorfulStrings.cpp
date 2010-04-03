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
// BEGIN CUT HERE
#include "cout.hpp"
// END CUT HERE 
using namespace std;
class ColorfulStrings {
public:
  string toStr(int n) {ostringstream ss; ss << n; return ss.str();}
  int N, K, counter;
  string ret;

  bool isColorful(string s) {
    int i, j, k;
    int n = s.size();
    vector <int> digits(10, 0);
    set <int> used;

    if (n == 1)
      return true;

    for (i=0; i<n; i++) {
      for (j=0; j<n-i; j++) {
        int tmp = 1;
        for (k=j; k<=j+i; k++)
          tmp *= (s[k] - '0');
        if (used.find(tmp) != used.end())
          return false;
        else
          used.insert(tmp);
      }
    }

    return true;
  }

  int r(string seq) {
    int i;
    int n = seq.size();
    vector <int> used(10, 0);

    for (i=0; i<n; i++)
      used[seq[i] - '0'] = 1;

    if (n == N) {
      if (isColorful(seq)) counter++;
      if (counter == K) {
        ret = seq;
        return 1;
      }
    } else {
      for (i=2; i<10; i++)
        if (used[i] == 0) {
          string t = seq;
          t += i + '0';
          int res = r(t);
          if (res == 1) return 1;
        }
    }

    return 0;
  }

  string getKth(int n, int k) {
    ret = "";
    N = n, K = k, counter = 0;

    if (n >= 9)
      return ret;

    if (n == 1)
      if (k <= 10)
        return toStr(k - 1);
      else
        return ret;

    r("");

    return ret;
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
    if ((Case == -1) || (Case == 6)) test_case_6();
  }
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { 
    int Arg0 = 3; 
    int Arg1 = 4; 
    string Arg2 = "238"; 
    verify_case(0, Arg2, getKth(Arg0, Arg1)); }
	void test_case_1() { 
    int Arg0 = 4; 
    int Arg1 = 2000; 
    string Arg2 = ""; 
    verify_case(1, Arg2, getKth(Arg0, Arg1)); }
	void test_case_2() { 
    int Arg0 = 5; 
    int Arg1 = 1; 
    string Arg2 = "23457"; 
    verify_case(2, Arg2, getKth(Arg0, Arg1)); }
	void test_case_3() { 
    int Arg0 = 2; 
    int Arg1 = 22; 
    string Arg2 = "52"; 
    verify_case(3, Arg2, getKth(Arg0, Arg1)); }
	void test_case_4() { 
    int Arg0 = 6; 
    int Arg1 = 464; 
    string Arg2 = "257936"; 
    verify_case(4, Arg2, getKth(Arg0, Arg1)); }
	void test_case_5() { 
    int Arg0 = 7; 
    int Arg1 = 100000000; 
    string Arg2 = ""; 
    verify_case(5, Arg2, getKth(Arg0, Arg1)); }
	void test_case_6() { 
    int Arg0 = 8; 
    int Arg1 = 10000000; 
    string Arg2 = ""; 
    verify_case(6, Arg2, getKth(Arg0, Arg1)); }

  // END CUT HERE

};
// BEGIN CUT HERE
int main() {
ColorfulStrings ___test;
___test.run_test(-1);
}
// END CUT HERE 
