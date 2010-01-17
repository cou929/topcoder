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

class CommonMultiples {
public:
  int gcd(int _a, int _b)
  {
    int a = max(_a, _b);
    int b = min(_a, _b);

    while (b)
      {
	int tmp = a % b;
	a = b;
	b = tmp;
      }

    return a;
  }

  double lcm(int _a, int _b)
  {
    int a = max(_a, _b);
    int b = min(_a, _b);

    return (double)a / gcd(a, b) * b;
  }


  int countCommMult(vector <int> a, int lower, int upper)
  {
    int ret = 0;

    double l = a[0];
    for (int i=1; i<a.size(); i++)
      {
	l = lcm(max((int)l, (int)a[i]), min((int)l, (int)a[i]));
	if (l > 2000000000)
	  return 0;
      }

    if (upper < l)
      return 0;

    ret = upper / l;

    if (l < lower)
      ret -= (int)((lower-1) / l);

    return ret;
  }

  // BEGIN CUT HERE
public:
  void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
private:
  template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
  void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
  void test_case_0() { int Arr0[] = {1,2,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; int Arg2 = 15; int Arg3 = 2; verify_case(0, Arg3, countCommMult(Arg0, Arg1, Arg2)); }
  void test_case_1() { int Arr0[] = {1,2,4,8,16,32,64}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 128; int Arg2 = 128; int Arg3 = 1; verify_case(1, Arg3, countCommMult(Arg0, Arg1, Arg2)); }
  void test_case_2() { int Arr0[] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,49}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 2000000000; int Arg3 = 0; verify_case(2, Arg3, countCommMult(Arg0, Arg1, Arg2)); }
  void test_case_3() { int Arr0[] = {1,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 2000000000; int Arg3 = 2000000000; verify_case(3, Arg3, countCommMult(Arg0, Arg1, Arg2)); }

  // END CUT HERE

};

// BEGIN CUT HERE
int main() {
CommonMultiples ___test;
___test.run_test(-1);
}
// END CUT HERE 
