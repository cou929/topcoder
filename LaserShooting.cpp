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
class LaserShooting {
public:
  double numberOfHits(vector <int> x, vector <int> y1, vector <int> y2) {
    double ret = 0;

    for (int i=0; i<x.size(); i++) {
      double ang1 = atan((double)y1[i] / (double)x[i]);
      double ang2 = atan((double)y2[i] / (double)x[i]);
      ret += abs(ang1 - ang2) / M_PI;
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
  }
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { 
    int Arr0[] = {1}; 
    vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
    int Arr1[] = {-1}; 
    vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); 
    int Arr2[] = {1}; 
    vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); 
    double Arg3 = 0.5; 
    verify_case(0, Arg3, numberOfHits(Arg0, Arg1, Arg2)); }
	void test_case_1() { 
    int Arr0[] = {1,2}; 
    vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
    int Arr1[] = {-1,-2}; 
    vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); 
    int Arr2[] = {1,2}; 
    vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); 
    double Arg3 = 1.0; 
    verify_case(1, Arg3, numberOfHits(Arg0, Arg1, Arg2)); }
	void test_case_2() { 
    int Arr0[] = {3,4,7,1}; 
    vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
    int Arr1[] = {1,2,3,4}; 
    vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); 
    int Arr2[] = {4,3,2,1}; 
    vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); 
    double Arg3 = 0.4623163952488826; 
    verify_case(2, Arg3, numberOfHits(Arg0, Arg1, Arg2)); }
	void test_case_3() { 
    int Arr0[] = {134,298,151,942}; 
    vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
    int Arr1[] = {-753,-76,19,568}; 
    vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); 
    int Arr2[] = {440,689,-39,672}; 
    vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); 
    double Arg3 = 1.444210260641501; 
    verify_case(3, Arg3, numberOfHits(Arg0, Arg1, Arg2)); }
	void test_case_4() { 
    int Arr0[] = {1}; 
    vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
    int Arr1[] = {-1}; 
    vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); 
    int Arr2[] = {1}; 
    vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); 
    double Arg3 = 0.5; 
    verify_case(4, Arg3, numberOfHits(Arg0, Arg1, Arg2)); }
	void test_case_5() { 
    int Arr0[] = {1}; 
    vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
    int Arr1[] = {-1}; 
    vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); 
    int Arr2[] = {1}; 
    vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); 
    double Arg3 = 0.5; 
    verify_case(5, Arg3, numberOfHits(Arg0, Arg1, Arg2)); }

  // END CUT HERE

};
// BEGIN CUT HERE
int main() {
LaserShooting ___test;
___test.run_test(-1);
}
// END CUT HERE 
