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
const int MAX = 10000000;
bool primes[MAX + 1];

class PrimeSequences {
public:

  map <int, bool> memo;
  map <int, int> memo2;

  bool isPrime(int n) {
    if (memo.find(n) != memo.end())
      return memo[n];
    
    if (n < 2)
      return memo[n] = false;

    if (n != 2 && n % 2 == 0)
      return memo[n] = false;

    int s = (int)sqrt(n);

    for (int i=3; i<=s; i++)
      if (n % i == 0)
        return memo[n] = false;

    return memo[n] = true;
  }

  void generatePrimes() {
    memset(primes, true, sizeof(primes));
    primes[0] = primes[1] = false;
    for (int i=2; i*i<=MAX; i++)
      if (isPrime(i))
        for (int j=2; j*i<=MAX; j++)
          primes[i*j] = false;
    return;
  }

  int check(int n) {
    int ret = 0;
    while (n > 0 && isPrime(n)) {
      ret++;
      n /= 2;
    }
    return ret;
  }

  int check2(int n) {
    if (memo2.find(n) != memo2.end())
      return memo2[n];

    if (isPrime(n))
      return memo2[n] = (1 + check2(n/2));
    return memo2[n] = 0;
  }

  int getLargestGenerator(int N, int D) {
    int ret = -1;
    int i;
//     int six[3] = {4068479, 2029439, 2879};
//     if (D >= 7)
//       return -1;
//     if (D == 6) {
//       for (i=0; i<3; i++)
//         if (N >= six[i])
//           return six[i];
//       return -1;
//     }

    for (i=N; i>=2; i--) {
      int len = check2(i);
      if (len >= D) {
        ret = i;
        break;
      }
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
    if ((Case == -1) || (Case == 7)) test_case_7();
  }
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { 
    int Arg0 = 10; 
    int Arg1 = 2; 
    int Arg2 = 7; 
    verify_case(0, Arg2, getLargestGenerator(Arg0, Arg1)); }
	void test_case_1() { 
    int Arg0 = 42; 
    int Arg1 = 3; 
    int Arg2 = 23; 
    verify_case(1, Arg2, getLargestGenerator(Arg0, Arg1)); }
	void test_case_2() { 
    int Arg0 = 666; 
    int Arg1 = 7; 
    int Arg2 = -1; 
    verify_case(2, Arg2, getLargestGenerator(Arg0, Arg1)); }
	void test_case_3() { 
    int Arg0 = 1337; 
    int Arg1 = 5; 
    int Arg2 = 47; 
    verify_case(3, Arg2, getLargestGenerator(Arg0, Arg1)); }
	void test_case_4() { 
    int Arg0 = 100000; 
    int Arg1 = 5; 
    int Arg2 = 2879; 
    verify_case(4, Arg2, getLargestGenerator(Arg0, Arg1)); }
	void test_case_5() { 
    int Arg0 = 40000; 
    int Arg1 = 1; 
    int Arg2 = 39989; 
    verify_case(5, Arg2, getLargestGenerator(Arg0, Arg1)); }
	void test_case_6() { 
    int Arg0 = 800000; 
    int Arg1 = 5;
    int Arg2 = 7; 
    verify_case(6, Arg2, getLargestGenerator(Arg0, Arg1)); }
	void test_case_7() { 
    int Arg0 = 10000000; 
    int Arg1 = 5; 
    int Arg2 = 7; 
    verify_case(7, Arg2, getLargestGenerator(Arg0, Arg1)); }

  // END CUT HERE

};
// BEGIN CUT HERE
int main() {
PrimeSequences ___test;
___test.run_test(7);
}
// END CUT HERE 
