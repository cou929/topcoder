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
class PrimeSoccer {
public:
  double combination(int n, int r)
  {
    int i, j;
    double result[r+1], tmp[r+1];

    for (i=0; i<=r; i++)
      {
	result[i] = 0;
	tmp[i] = 0;
      }

    result[0] = 1;

    for (i=1; i<=n; i++)
      {
	tmp[0] = 1;

	for (j=1; j<=r; j++)
	  tmp[j] = result[j-1] + result[j];

	for (j=0; j<=r; j++)
	  result[j] = tmp[j];
      }

    return result[r];
  }

  double getProbability(int skillOfTeamA, int skillOfTeamB)
  {
    int notPrimes[12] = {0, 1, 4, 6, 8, 9, 10, 12, 14, 15, 16, 18};
    double probA = 0, probB = 0;
    double skillA = (double)skillOfTeamA / 100, skillB = (double)skillOfTeamB / 100;

    for (int i=0; i<12; i++)
      {
	probA += combination(18, notPrimes[i]) * pow(skillA, notPrimes[i]) * pow(1 - skillA, 18 - notPrimes[i]);
	probB += combination(18, notPrimes[i]) * pow(skillB, notPrimes[i]) * pow(1 - skillB, 18 - notPrimes[i]);
      }

    return 1 - probA * probB;
  }
  // BEGIN CUT HERE
public:
  void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
private:
  template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
  void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
  void test_case_0() { int Arg0 = 50; int Arg1 = 50; double Arg2 = 0.5265618908306351; verify_case(0, Arg2, getProbability(Arg0, Arg1)); }
  void test_case_1() { int Arg0 = 100; int Arg1 = 100; double Arg2 = 0.0; verify_case(1, Arg2, getProbability(Arg0, Arg1)); }
  void test_case_2() { int Arg0 = 12; int Arg1 = 89; double Arg2 = 0.6772047168840167; verify_case(2, Arg2, getProbability(Arg0, Arg1)); }

  // END CUT HERE
};
// BEGIN CUT HERE
int main() {
PrimeSoccer ___test;
___test.run_test(-1);
}
// END CUT HERE 
