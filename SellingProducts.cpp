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
class SellingProducts {
public:
  int optimalPrice(vector <int> price, vector <int> cost) {
    int max_profit = 0;
    int opt_price = INT_MAX;

    for (int i=0; i<price.size(); i++) {
      int profit = 0;
      for (int j=0; j<price.size(); j++)
        if (price[j] >= price[i] && price[i] > cost[j])
          profit += price[i] - cost[j];

      if (profit == max_profit && opt_price > price[i]) {
        opt_price = price[i];
      } else if (profit > max_profit) {
        opt_price = price[i];
        max_profit = profit;
      }
    }

    if (max_profit == 0) opt_price = 0;

    return opt_price;
  }
   
  // BEGIN CUT HERE
public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {13,22,35}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,0,0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 22; verify_case(0, Arg2, optimalPrice(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {13,22,35}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {5,15,30}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 13; verify_case(1, Arg2, optimalPrice(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {13,22,35}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {15,30,40}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; verify_case(2, Arg2, optimalPrice(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {10,10,20,20,5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,5,11,15,0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 10; verify_case(3, Arg2, optimalPrice(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {13,17,14,30,19,17,55,16}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {12,1,5,10,3,2,40,19}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 17; verify_case(4, Arg2, optimalPrice(Arg0, Arg1)); }

  // END CUT HERE

};
// BEGIN CUT HERE
int main() {
SellingProducts ___test;
___test.run_test(-1);
}
// END CUT HERE 
