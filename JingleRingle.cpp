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
class JingleRingle {
public:
  int profit(vector <int> buyOffers, vector <int> sellOffers, int tax) {
    int ret  = 0;
    int i, j;
    int n = min(buyOffers.size(), sellOffers.size());

    sort(buyOffers.rbegin(), buyOffers.rend());
    sort(sellOffers.begin(), sellOffers.end());

    for (i=1; i<=n; i++) {
      int cost = accumulate(sellOffers.begin(), sellOffers.begin() + i, 0);
      int profit = accumulate(buyOffers.begin(), buyOffers.begin() + i, 0);
      int amountTax = 0;
      for (j=0; j<i; j++)
        amountTax += (buyOffers[j] * tax) / 100;
      ret = max(ret, profit - cost - amountTax);
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
    int Arr0[] = {1000, 1024}; 
    vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
    int Arr1[] = {990, 1011}; 
    vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); 
    int Arg2 = 0; 
    int Arg3 = 34; 
    verify_case(0, Arg3, profit(Arg0, Arg1, Arg2)); }
	void test_case_1() { 
    int Arr0[] = {1000, 1001, 1002}; 
    vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
    int Arr1[] = {980, 981, 982}; 
    vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); 
    int Arg2 = 2; 
    int Arg3 = 2; 
    verify_case(1, Arg3, profit(Arg0, Arg1, Arg2)); }
	void test_case_2() { 
    int Arr0[] = {100, 120, 140}; 
    vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
    int Arr1[] = {150, 170, 200}; 
    vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); 
    int Arg2 = 15; 
    int Arg3 = 0; 
    verify_case(2, Arg3, profit(Arg0, Arg1, Arg2)); }
	void test_case_3() { 
    int Arr0[] = {}; 
    vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
    int Arr1[] = {}; 
    vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); 
    int Arg2 = 20; 
    int Arg3 = 0; 
    verify_case(3, Arg3, profit(Arg0, Arg1, Arg2)); }
	void test_case_4() { 
    int Arr0[] = {1692, 3281, 862}; 
    vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
    int Arr1[] = {2701, 2819, 2582, 1918, 638, 601, 1128, 2760, 1949, 3074,
                  615, 2221, 1691, 3226, 1351, 1329, 556, 1060, 898, 1080,
                  2494, 2379, 3148, 737, 1412, 3290, 1594, 1314, 959, 3192,
                  1326, 932, 1103, 937, 1670, 2017, 1403, 1282, 2949, 2940,
                  2557, 940, 2561, 1248, 2385, 541, 2382, 1309, 831}; 
    vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); 
    int Arg2 = 4; 
    int Arg3 = 3905; 
    verify_case(4, Arg3, profit(Arg0, Arg1, Arg2)); }
	void test_case_5() { 
    int Arr0[] = {5016, 7212, 7613, 1590, 2942, 5155, 5898, 8113, 2001, 2348,
                  671, 5167, 7524, 2467, 4294, 3628, 4480, 5872, 5230, 3732,
                  4637, 6419, 1431, 6335, 1652, 3005, 2125, 2193, 2183, 5856,
                  1795, 5441, 2079, 7114, 2290, 4025, 5943, 1695}; 
    vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
    int Arr1[] = {2407, 5602, 1350}; 
    vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); 
    int Arg2 = 3; 
    int Arg3 = 13195; 
    verify_case(5, Arg3, profit(Arg0, Arg1, Arg2)); }
	void test_case_6() { 
    int Arr0[] = {1000, 1024}; 
    vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
    int Arr1[] = {990, 1011}; 
    vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); 
    int Arg2 = 0; 
    int Arg3 = 34; 
    verify_case(6, Arg3, profit(Arg0, Arg1, Arg2)); }
	void test_case_7() { 
    int Arr0[] = {1000, 1024}; 
    vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
    int Arr1[] = {990, 1011}; 
    vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); 
    int Arg2 = 0; 
    int Arg3 = 34; 
    verify_case(7, Arg3, profit(Arg0, Arg1, Arg2)); }

  // END CUT HERE

};
// BEGIN CUT HERE
int main() {
JingleRingle ___test;
___test.run_test(-1);
}
// END CUT HERE 
