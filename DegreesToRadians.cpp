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

class DegreesToRadians {
public:
  double convertToRadians(int degrees, int minutes, int seconds)
  {
    double pi = 3.141592653589793;
    double min = (double)minutes + (double)seconds / 60.0;
    double deg = min / 60.0 + (double)degrees;
    return deg * pi / 180.0;
  }

   
  // BEGIN CUT HERE
public:
  void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
private:
  template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
  void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
  void test_case_0() { int Arg0 = 0; int Arg1 = 0; int Arg2 = 0; double Arg3 = 0.0; verify_case(0, Arg3, convertToRadians(Arg0, Arg1, Arg2)); }
  void test_case_1() { int Arg0 = 180; int Arg1 = 0; int Arg2 = 0; double Arg3 = 3.141592653589793; verify_case(1, Arg3, convertToRadians(Arg0, Arg1, Arg2)); }
  void test_case_2() { int Arg0 = 359; int Arg1 = 59; int Arg2 = 59; double Arg3 = 6.283180459042776; verify_case(2, Arg3, convertToRadians(Arg0, Arg1, Arg2)); }
  void test_case_3() { int Arg0 = 23; int Arg1 = 30; int Arg2 = 5; double Arg3 = 0.41017661490272295; verify_case(3, Arg3, convertToRadians(Arg0, Arg1, Arg2)); }

  // END CUT HERE

};

// BEGIN CUT HERE
int main() {
DegreesToRadians ___test;
___test.run_test(-1);
}
// END CUT HERE 
