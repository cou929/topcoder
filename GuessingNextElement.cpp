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
class GuessingNextElement {
public:
  int guess(vector <int> A)
  {
    int p = A[0];
    int art = A[1] - A[0];
    int geo = A[1] / A[0];
    bool isGeo = true;
    if (A[1] % A[0] != 0)
      isGeo = false;

    if (isGeo)
      {
	int n = p;
	for (int i=1; i<A.size(); i++)
	  {
	    n *= geo;
	    if (n != A[i])
	      {
		isGeo = false;
		break;
	      }
	  }
      }

    if (isGeo)
      return A[A.size()-1]*geo;
    else
      return A[A.size()-1]+art;
  }
   
  // BEGIN CUT HERE
public:
  void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
private:
  template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
  void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
  void test_case_0() { int Arr0[] = {364,843,1322,1801}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2280; verify_case(0, Arg1, guess(Arg0)); }
  void test_case_1() { int Arr0[] = {394,1172,1950,2728,3506,4284,5062,5840}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6618; verify_case(1, Arg1, guess(Arg0)); }
  void test_case_2() { int Arr0[] = {13,117,1053,9477,85293}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 767637; verify_case(2, Arg1, guess(Arg0)); }
  void test_case_3() { int Arr0[] = {22,220,2200,22000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 220000; verify_case(3, Arg1, guess(Arg0)); }
  void test_case_4() { int Arr0[] = {250000, 500000, 1000000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2000000; verify_case(4, Arg1, guess(Arg0)); }

  // END CUT HERE

};
// BEGIN CUT HERE
int main() {
GuessingNextElement ___test;
___test.run_test(-1);
}
// END CUT HERE 
