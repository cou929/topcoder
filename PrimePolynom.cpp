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
class PrimePolynom {
public:
  int MAX;
  bool primeTable[1000000];

  bool isPrime(int n)
  {
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

  int reveal(int A, int B, int C)
  {
    int ret = 0;

    for (int i=0; i<=80; i++)
      if (!isPrime(i*i*A + i*B + C))
	{
	  ret = i;
	  break;
	}

    return ret;
  }
   
  // BEGIN CUT HERE
public:
  void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
private:
  template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
  void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
  void test_case_0() { int Arg0 = 1; int Arg1 = -1; int Arg2 = 41; int Arg3 = 41; verify_case(0, Arg3, reveal(Arg0, Arg1, Arg2)); }
  void test_case_1() { int Arg0 = 1; int Arg1 = 1; int Arg2 = 41; int Arg3 = 40; verify_case(1, Arg3, reveal(Arg0, Arg1, Arg2)); }
  void test_case_2() { int Arg0 = 1; int Arg1 = 1; int Arg2 = -13; int Arg3 = 0; verify_case(2, Arg3, reveal(Arg0, Arg1, Arg2)); }
  void test_case_3() { int Arg0 = 1; int Arg1 = -15; int Arg2 = 97; int Arg3 = 48; verify_case(3, Arg3, reveal(Arg0, Arg1, Arg2)); }
  void test_case_4() { int Arg0 = 8664; int Arg1 = -4260; int Arg2 = 113; int Arg3 = 11; verify_case(4, Arg3, reveal(Arg0, Arg1, Arg2)); }
  // 8664, -4260, 113

  // END CUT HERE

};
// BEGIN CUT HERE
int main() {
PrimePolynom ___test;
 ___test.run_test(-1);
}
// END CUT HERE 
