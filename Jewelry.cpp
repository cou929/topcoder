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
class Jewelry {
public:
  long long howMany(vector <int> values) {
    long long ret = 0;

    long long a[1000*30+1][30];
    memset(a, 0, sizeof(a));

    return ret;
  }
   
  // BEGIN CUT HERE
public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1,2,5,3,4,5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 9LL; verify_case(0, Arg1, howMany(Arg0)); }
	void test_case_1() { int Arr0[] = {1000,1000,1000,1000,1000,
                                     1000,1000,1000,1000,1000,
                                     1000,1000,1000,1000,1000,
                                     1000,1000,1000,1000,1000,
                                     1000,1000,1000,1000,1000,
                                     1000,1000,1000,1000,1000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 18252025766940LL; verify_case(1, Arg1, howMany(Arg0)); }
	void test_case_2() { int Arr0[] = {1,2,3,4,5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 4LL; verify_case(2, Arg1, howMany(Arg0)); }
	void test_case_3() { int Arr0[] = {7,7,8,9,10,11,1,2,2,3,4,5,6}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 607LL; verify_case(3, Arg1, howMany(Arg0)); }
	void test_case_4() { int Arr0[] = {123,217,661,678,796,964,54,111,417,526,917,923}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 0LL; verify_case(4, Arg1, howMany(Arg0)); }

  // END CUT HERE

};
// BEGIN CUT HERE
int main() {
Jewelry ___test;
___test.run_test(-1);
}
// END CUT HERE 
