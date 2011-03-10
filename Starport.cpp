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
class Starport {
public:
  int gcd(const int _a, const int _b) {
    int a = max(_a, _b);
    int b = min(_a, _b);

    while (b) {
      int tmp = a % b;
      a = b;
      b = tmp;
    }

    return a;
  }

  double getExpectedTime(int N, int M) {
    return (N - gcd(N, M)) / 2.0;

    // double ret = 0;
    // long long lcm = N * M;
    // long long total = 0;
    // long long counter = 0;
    // int i;

    // for (i=1; i*M<=lcm; i++) {
    //   total += (i*M % N == 0) ? 0 : (N - i*M % N);
    //   counter++;
    // }

    // ret = (double)total / (double)counter;

    // return ret;
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
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { 
    int Arg0 = 4; 
    int Arg1 = 2; 
    double Arg2 = 1.0; 
    verify_case(0, Arg2, getExpectedTime(Arg0, Arg1)); }
	void test_case_1() { 
    int Arg0 = 5; 
    int Arg1 = 3; 
    double Arg2 = 2.0; 
    verify_case(1, Arg2, getExpectedTime(Arg0, Arg1)); }
	void test_case_2() { 
    int Arg0 = 6; 
    int Arg1 = 1; 
    double Arg2 = 2.5; 
    verify_case(2, Arg2, getExpectedTime(Arg0, Arg1)); }
	void test_case_3() { 
    int Arg0 = 18; 
    int Arg1 = 25; 
    double Arg2 = 6170.0; 
    verify_case(3, Arg2, getExpectedTime(Arg0, Arg1)); }
	void test_case_4() { 
    int Arg0 = 1000000000; 
    int Arg1 = 1; 
    double Arg2 = 1.0; 
    verify_case(4, Arg2, getExpectedTime(Arg0, Arg1)); }
	void test_case_5() { 
    int Arg0 = 1; 
    int Arg1 = 1000000000; 
    double Arg2 = 1.0; 
    verify_case(5, Arg2, getExpectedTime(Arg0, Arg1)); }

  // END CUT HERE

};
// BEGIN CUT HERE
int main() {
Starport ___test;
___test.run_test(-1);
}
// END CUT HERE 
