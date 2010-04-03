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
class TurretPlacement {
public:

  long long c(double distance) {
    long long ret = 0;
    double i;

    ret += (long long)(distance / 2.0 / 0.5);

    for (i=0.5; distance - i*2 > 0; i += 0.5)
      ret += (long long)((distance - i*2) / 0.5) * 2;

    return ret;
  }

  long long count(vector <int> x, vector <int> y) {
    long long ret = 0;
    int i, j;
    int n = x.size();

    for (i=0; i<n; i++)
      for (j=i+1; j<n; j++) {
        double distance = sqrt((x[i] - x[j])*(x[i] - x[j]) + (y[i] - y[j])*(y[i] - y[j]));
        ret += c(distance);
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
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { 
    int Arr0[] = {0,2}; 
    vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
    int Arr1[] = {0,2}; 
    vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); 
    long long Arg2 = 10LL; 
    verify_case(0, Arg2, count(Arg0, Arg1)); }
	void test_case_1() { 
    int Arr0[] = {0,1,2}; 
    vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
    int Arr1[] = {0,1,0}; 
    vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); 
    long long Arg2 = 8LL; 
    verify_case(1, Arg2, count(Arg0, Arg1)); }
	void test_case_2() { 
    int Arr0[] = {1,2,3,0}; 
    vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
    int Arr1[] = {-1,-5,-7,100}; 
    vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); 
    long long Arg2 = 65137LL; 
    verify_case(2, Arg2, count(Arg0, Arg1)); }
	void test_case_3() { 
    int Arr0[] = {9998,-10000,10000,0}; 
    vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
    int Arr1[] = {9998,10000,10000,0}; 
    vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); 
    long long Arg2 = 2799564895LL; 
    verify_case(3, Arg2, count(Arg0, Arg1)); }
	void test_case_4() { 
    int Arr0[] = {0,2}; 
    vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
    int Arr1[] = {0,2}; 
    vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); 
    long long Arg2 = 10LL; 
    verify_case(4, Arg2, count(Arg0, Arg1)); }
	void test_case_5() { 
    int Arr0[] = {0,2}; 
    vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
    int Arr1[] = {0,2}; 
    vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); 
    long long Arg2 = 10LL; 
    verify_case(5, Arg2, count(Arg0, Arg1)); }

  // END CUT HERE

};
// BEGIN CUT HERE
int main() {
TurretPlacement ___test;
___test.run_test(-1);
}
// END CUT HERE 
