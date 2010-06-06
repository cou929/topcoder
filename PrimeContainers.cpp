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

  bool isPrime(int n) {
    if (n < 2)
      return false;

    if (n != 2 && n % 2 == 0)
      return false;

    int s = (int)sqrt(n);

    for (int i=3; i<=s; i++)
      if (n % i == 0)
        return false;

    return true;
  }

class PrimeContainers {
public:
  int containerSize(int N) {
    int ret = 0;

    while (N > 0) {
      if (isPrime(N))
        ret++;
      N /= 2;
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
    int Arg0 = 10; 
    int Arg1 = 2; 
    verify_case(0, Arg1, containerSize(Arg0)); }
	void test_case_1() { 
    int Arg0 = 42; 
    int Arg1 = 2; 
    verify_case(1, Arg1, containerSize(Arg0)); }
	void test_case_2() { 
    int Arg0 = 47; 
    int Arg1 = 5; 
    verify_case(2, Arg1, containerSize(Arg0)); }
	void test_case_3() { 
    int Arg0 = 959; 
    int Arg1 = 6; 
    verify_case(3, Arg1, containerSize(Arg0)); }
	void test_case_4() { 
    int Arg0 = 421337; 
    int Arg1 = 2; 
    verify_case(4, Arg1, containerSize(Arg0)); }
	void test_case_5() { 
    int Arg0 = 10; 
    int Arg1 = 2; 
    verify_case(5, Arg1, containerSize(Arg0)); }
	void test_case_6() { 
    int Arg0 = 10; 
    int Arg1 = 2; 
    verify_case(6, Arg1, containerSize(Arg0)); }

  // END CUT HERE

};
// BEGIN CUT HERE
int main() {
PrimeContainers ___test;
___test.run_test(-1);
}
// END CUT HERE 
