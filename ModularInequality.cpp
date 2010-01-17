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
class ModularInequality {
public:
  int countSolutions(vector <int> A, int P)
  {
    int ret = 0;
    int maxi = -1000000000;
    int mini = 1000000000;
    double fromMax = 0, fromMin = 0;

    for (int i=0; i<A.size(); i++)
      {
	maxi = max(maxi, A[i]);
	mini = min(mini, A[i]);
      }

    for (int i=0; i<A.size(); i++)
      {
	fromMax += abs(A[i] - maxi);
	fromMin += abs(A[i] - mini);
      }

    if (fromMax <= P)
      ret += P - (int)fromMax;

    if (fromMin <= P)
      ret += P - (int)fromMin;

    for (int i=mini; i<=maxi; i++)
      {
	double tmp = 0;
	for (int j=0; j<A.size(); j++)
	  tmp += abs(A[j] - i);
	if ((int)tmp <= P)
	  ret++;
      }

    return ret;
  }
   
  // BEGIN CUT HERE
public:
  void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
private:
  template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
  void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
  void test_case_0() { int Arr0[] = {1, 2, 3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; int Arg2 = 5; verify_case(0, Arg2, countSolutions(Arg0, Arg1)); }
  void test_case_1() { int Arr0[] = {10, 30, 15, -1, 17}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 42; int Arg2 = 7; verify_case(1, Arg2, countSolutions(Arg0, Arg1)); }
  void test_case_2() { int Arr0[] = {0, 2, 3, -5, 10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 17; int Arg2 = 0; verify_case(2, Arg2, countSolutions(Arg0, Arg1)); }
  void test_case_3() { int Arr0[] = {-693}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1265; int Arg2 = 2531; verify_case(3, Arg2, countSolutions(Arg0, Arg1)); }
  void test_case_4() { int Arr0[] = {965, -938, -396, -142, 926, 31, -720}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6495; int Arg2 = 1781; verify_case(4, Arg2, countSolutions(Arg0, Arg1)); }

  // END CUT HERE

};
// BEGIN CUT HERE
int main() {
ModularInequality ___test;
___test.run_test(-1);
}
// END CUT HERE 
