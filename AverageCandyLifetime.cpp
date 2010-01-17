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
class AverageCandyLifetime {
public:
  double getAverage(vector <int> eatenCandies)
  {
    int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int lifetime[12];

    int m = 0;
    for (int i=0; i<12; i++)
      {
	m += days[i];
	lifetime[i] = m;
      }

    int totalLifetime = 0;
    int nums = 0;
    for (int i=0; i<eatenCandies.size(); i++)
      {
	totalLifetime += eatenCandies[i] * lifetime[i];
	nums += eatenCandies[i];
      }

    return (double)totalLifetime / nums;
  }
   
  // BEGIN CUT HERE
public:
  void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
private:
  template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
  void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
  void test_case_0() { int Arr0[] = {1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 60.5; verify_case(0, Arg1, getAverage(Arg0)); }
  void test_case_1() { int Arr0[] = {0, 1000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 59.0; verify_case(1, Arg1, getAverage(Arg0)); }
  void test_case_2() { int Arr0[] = {0, 0, 0, 0, 0, 1, 0, 0, 0, 50, 0, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 301.5882352941176; verify_case(2, Arg1, getAverage(Arg0)); }
  void test_case_3() { int Arr0[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 252.80769230769232; verify_case(3, Arg1, getAverage(Arg0)); }

  // END CUT HERE

};
// BEGIN CUT HERE
int main() {
AverageCandyLifetime ___test;
___test.run_test(-1);
}
// END CUT HERE 
