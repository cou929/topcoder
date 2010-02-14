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
class IdealString {
public:
  int len;
  int x[100];
  string ret;

  int dfs(int i, int last, int sum) {
    if (sum == len) {
      char s[101];
      memset(s, 0, sizeof(s));
      queue <char> unused;

      for (int j=0; j<i; j++) {
        s[x[j] - 1] = 'A' + j;
        for (int k=0; k<x[j]-1; k++)
          unused.push('A' + j);
      }
      
      for (int j=0; j<len; j++)
        if (s[j] == 0) {
          s[j] = unused.front();
          unused.pop();
        }
      s[len] = '\0';
      if (ret == "" || ret > string(s))
        ret = string(s);
    } else {
      for (x[i] = last + 1; x[i] <= sum+1 && sum + x[i] <= len; x[i]++)
        dfs(i+1, x[i], sum + x[i]);
    }
    return 0;
  }

  string construct(int length) {
    ret = "";
    len = length;
    dfs(0, 0, 0);

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
    if ((Case == -1) || (Case == 7)) test_case_7();
  }
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { 
    int Arg0 = 1; 
    string Arg1 = "A"; 
    verify_case(0, Arg1, construct(Arg0)); }
	void test_case_1() { 
    int Arg0 = 3; 
    string Arg1 = "ABB"; 
    verify_case(1, Arg1, construct(Arg0)); }
	void test_case_2() { 
    int Arg0 = 2; 
    string Arg1 = ""; 
    verify_case(2, Arg1, construct(Arg0)); }
	void test_case_3() { 
    int Arg0 = 6; 
    string Arg1 = "ABCBCC"; 
    verify_case(3, Arg1, construct(Arg0)); }
	void test_case_4() { 
    int Arg0 = 7; 
    string Arg1 = "ABBCCCC"; 
    verify_case(4, Arg1, construct(Arg0)); }
	void test_case_5() { 
    int Arg0 = 5; 
    string Arg1 = ""; 
    verify_case(5, Arg1, construct(Arg0)); }
	void test_case_6() { 
    int Arg0 = 1; 
    string Arg1 = "A"; 
    verify_case(6, Arg1, construct(Arg0)); }
	void test_case_7() { 
    int Arg0 = 1; 
    string Arg1 = "A"; 
    verify_case(7, Arg1, construct(Arg0)); }

  // END CUT HERE

};
// BEGIN CUT HERE
int main() {
IdealString ___test;
___test.run_test(-1);
}
// END CUT HERE 
