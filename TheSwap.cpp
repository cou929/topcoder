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
class TheSwap {
public:
  int toInt(string s) {int r = 0; istringstream ss(s); ss >> r; return r;}
  string toStr(int n) {ostringstream ss; ss << n; return ss.str();}
  map <pair <int, int>, int> memo;

  int r(string digits, int k) {
    int ret = -1;
    int n = toInt(digits);

    if (k == 0)
      return n;

    if (memo.count(make_pair(n, k)))
      return memo[make_pair(n, k)];

    for (int i=0; i<digits.size(); i++)
      for (int j=i+1; j<digits.size(); j++) {
        if (i == 0 && digits[j] == 0) continue;
        swap(digits[i], digits[j]);
        ret = max(ret, r(digits, k-1));
        swap(digits[i], digits[j]);
      }

    memo[make_pair(n, k)] = ret;
    return ret;
  }

  int findMax(int n, int k) {
    int ret = 0;
    string digits = toStr(n);

    if (digits.size() == 1 || digits.size() == 2 && digits[1] == '0') return -1;

    ret = r(digits, k);
    
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
    if ((Case == -1) || (Case == 5)) test_case_6();
  }
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { 
    int Arg0 = 16375; 
    int Arg1 = 1; 
    int Arg2 = 76315; 
    verify_case(0, Arg2, findMax(Arg0, Arg1)); }
	void test_case_1() { 
    int Arg0 = 432; 
    int Arg1 = 1; 
    int Arg2 = 423; 
    verify_case(1, Arg2, findMax(Arg0, Arg1)); }
	void test_case_2() { 
    int Arg0 = 90; 
    int Arg1 = 4; 
    int Arg2 = -1; 
    verify_case(2, Arg2, findMax(Arg0, Arg1)); }
	void test_case_3() { 
    int Arg0 = 5; 
    int Arg1 = 2; 
    int Arg2 = -1; 
    verify_case(3, Arg2, findMax(Arg0, Arg1)); }
	void test_case_4() { 
    int Arg0 = 436659; 
    int Arg1 = 2; 
    int Arg2 = 966354; 
    verify_case(4, Arg2, findMax(Arg0, Arg1)); }
	void test_case_5() { 
    int Arg0 = 900; 
    int Arg1 = 1;
    int Arg2 = 900; 
    verify_case(5, Arg2, findMax(Arg0, Arg1)); }
	void test_case_6() { 
    int Arg0 = 90101099; 
    int Arg1 = 10;
    int Arg2 = 99911000; 
    verify_case(5, Arg2, findMax(Arg0, Arg1)); }

  // END CUT HERE

};
// BEGIN CUT HERE
int main() {
TheSwap ___test;
___test.run_test(-1);
}
// END CUT HERE 
