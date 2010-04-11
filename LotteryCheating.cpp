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
class LotteryCheating {
public:
  string toStr(long long n) {ostringstream ss; ss << n; return ss.str();}

  string fillZero(string s, int len) {
    string ret(len, '0');
    int i, n = s.size();

    for (i=0; i<n; i++)
      ret[ret.size() - 1 - i] = s[n - 1 - i];

    return ret;
  }

  int minimalChange(string ID) {
    int ret = 10;
    long long i, j;
    int place = ID.size();
    long long n = (long long)pow(10.0, place);
    
    for (i=0; i*i<n; i++) {
      string candidate = toStr(i*i);
      int distance = 0;

      candidate = fillZero(candidate, place);

      for (j=0; j<place; j++)
        if (candidate[j] != ID[j])
          distance++;

      ret = min(ret, distance);
    }

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
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { 
    string Arg0 = "1"; 
    int Arg1 = 0; 
    verify_case(0, Arg1, minimalChange(Arg0)); }
	void test_case_1() { 
    string Arg0 = "1234"; 
    int Arg1 = 2; 
    verify_case(1, Arg1, minimalChange(Arg0)); }
	void test_case_2() { 
    string Arg0 = "9000000000"; 
    int Arg1 = 1; 
    verify_case(2, Arg1, minimalChange(Arg0)); }
	void test_case_3() { 
    string Arg0 = "4294967296"; 
    int Arg1 = 0; 
    verify_case(3, Arg1, minimalChange(Arg0)); }
	void test_case_4() { 
    string Arg0 = "7654321"; 
    int Arg1 = 3; 
    verify_case(4, Arg1, minimalChange(Arg0)); }
	void test_case_5() { 
    string Arg0 = "49637"; 
    int Arg1 = 3; 
    verify_case(5, Arg1, minimalChange(Arg0)); }
	void test_case_6() { 
    string Arg0 = "1"; 
    int Arg1 = 0; 
    verify_case(6, Arg1, minimalChange(Arg0)); }

  // END CUT HERE

};
// BEGIN CUT HERE
int main() {
LotteryCheating ___test;
___test.run_test(-1);
}
// END CUT HERE 
