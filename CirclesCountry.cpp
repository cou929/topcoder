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
#include <math.h>
#include <utility>
#include <set>
#include <cctype>
#include <queue>
#include <stack>
using namespace std;
class CirclesCountry {
public:
  int leastBorders(vector <int> X, vector <int> Y, vector <int> R, int x1, int y1, int x2, int y2)
  {
    int limit = X.size();
    int source = 0;
    int dest = 0;

    for (int i=0; i<limit; i++)
      {
	int flg = 0;

	if (pow(x1-X[i], 2)+pow(y1-Y[i], 2) < pow(R[i],2))
	  {
	    ++source;
	    ++flg;
	  }
	if (pow(x2-X[i], 2)+pow(y2-Y[i], 2) < pow(R[i],2))
	  {
	    ++dest;
	    ++flg;
	  }
	if (flg == 2)
	  {
	    source--;
	    dest--;
	  }
      }
    return source + dest;
  }
   
  // BEGIN CUT HERE
public:
  void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
private:
  template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
  void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
  void test_case_0() { int Arr0[] = {0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = -5; int Arg4 = 1; int Arg5 = 5; int Arg6 = 1; int Arg7 = 0; verify_case(0, Arg7, leastBorders(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6)); }
  void test_case_1() { int Arr0[] = {0,-6,6}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,1,2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {2,2,2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = -5; int Arg4 = 1; int Arg5 = 5; int Arg6 = 1; int Arg7 = 2; verify_case(1, Arg7, leastBorders(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6)); }
  void test_case_2() { int Arr0[] = {1,-3,2,5,-4,12,12}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,-1,2,5,5,1,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {8,1,2,1,1,1,2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = -5; int Arg4 = 1; int Arg5 = 12; int Arg6 = 1; int Arg7 = 3; verify_case(2, Arg7, leastBorders(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6)); }
  void test_case_3() { int Arr0[] = {-3,2,2,0,-4,12,12,12}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-1,2,3,1,5,1,1,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1,3,1,7,1,1,2,3}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 2; int Arg4 = 3; int Arg5 = 13; int Arg6 = 2; int Arg7 = 5; verify_case(3, Arg7, leastBorders(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6)); }
  void test_case_4() { int Arr0[] = {-107,-38,140,148,-198,172,-179,148,176,153,-56,-187}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {175,-115,23,-2,-49,-151,-52,42,0,68,109,-174}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {135,42,70,39,89,39,43,150,10,120,16,8}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 102; int Arg4 = 16; int Arg5 = 19; int Arg6 = -108; int Arg7 = 3; verify_case(4, Arg7, leastBorders(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6)); }

  // END CUT HERE

};
// BEGIN CUT HERE
int main() {
CirclesCountry ___test;
___test.run_test(-1);
}
// END CUT HERE 
