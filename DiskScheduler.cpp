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
class DiskScheduler {
   public:
   int optimize(int start, vector <int> sectors)
  {

  }
   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 5; int Arr1[] = {6,8,65,71}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 46; verify_case(0, Arg2, optimize(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 5; int Arr1[] = {55,65,71}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 50; verify_case(1, Arg2, optimize(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 20; int Arr1[] = {1,21,99}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 23; verify_case(2, Arg2, optimize(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 99; int Arr1[] = {55,56,61,70,76,78,80,83,84,90,1,4,6,26,27,33,38,46,47,49}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 87; verify_case(3, Arg2, optimize(Arg0, Arg1)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
DiskScheduler ___test;
___test.run_test(-1);
}
// END CUT HERE 
