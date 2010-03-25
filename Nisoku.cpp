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
// BEGIN CUT HERE
#include "cout.hpp"
// END CUT HERE 
using namespace std;
class Nisoku {
   public:
   double theMax(vector <double> cards) {
      double ret = 0;
      int i, j;
      int n = cards.size();

      sort(cards.begin(), cards.end());

      for (i=0; i<=n; i+=2) {
        double cur = 1;
        for (j=0; j<i/2; j++)
          cur *= cards[j] + cards[i-j-1];
        for (j=i; j<n; j++)
          cur *= cards[j];
        ret = max(ret, cur);
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
}
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { 
	double Arr0[] = {5, 8}; 
	vector <double> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
	double Arg1 = 40.0; 
	verify_case(0, Arg1, theMax(Arg0)); }
	void test_case_1() { 
	double Arr0[] = {1.5, 1.8}; 
	vector <double> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
	double Arg1 = 3.3; 
	verify_case(1, Arg1, theMax(Arg0)); }
	void test_case_2() { 
	double Arr0[] = {8.26, 7.54, 3.2567}; 
	vector <double> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
	double Arg1 = 202.82857868; 
	verify_case(2, Arg1, theMax(Arg0)); }
	void test_case_3() { 
	double Arr0[] = {1.5, 1.7, 1.6, 1.5}; 
	vector <double> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
	double Arg1 = 9.920000000000002; 
	verify_case(3, Arg1, theMax(Arg0)); }
	void test_case_4() { 
	double Arr0[] = {10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 
10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 
10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 
10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 
10, 10, 10, 10, 10, 10, 10, 10, 10, 10}; 
	vector <double> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
	double Arg1 = 1.0E50; 
	verify_case(4, Arg1, theMax(Arg0)); }
	void test_case_5() { 
	double Arr0[] = {5, 8}; 
	vector <double> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
	double Arg1 = 40.0; 
	verify_case(5, Arg1, theMax(Arg0)); }
	void test_case_6() { 
	double Arr0[] = {5, 8}; 
	vector <double> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
	double Arg1 = 40.0; 
	verify_case(6, Arg1, theMax(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
Nisoku ___test;
___test.run_test(-1);
}
// END CUT HERE 
