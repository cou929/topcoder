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
class Badgers {
public:
  int feedMost(vector <int> hunger, vector <int> greed, int totalFood) {
    int ret = 0;
    int n = hunger.size();
    int i, j;

    for (i=0; i<n; i++) {
      vector <int> scores;
      int sum = 0;
      for (j=0; j<n; j++)
        scores.push_back(hunger[j] + greed[j] * i);
      sort(scores.begin(), scores.end());
      for (j=0; j<i+1; j++)
        sum += scores[j];
      if (sum <= totalFood)
        ret = i + 1;
      else
        break;
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
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { 
    int Arr0[] = {1,2,3}; 
    vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
    int Arr1[] = {2,2,1}; 
    vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); 
    int Arg2 = 7; 
    int Arg3 = 2; 
    verify_case(0, Arg3, feedMost(Arg0, Arg1, Arg2)); }
	void test_case_1() { 
    int Arr0[] = {5,2,1,5}; 
    vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
    int Arr1[] = {0,2,4,1}; 
    vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); 
    int Arg2 = 19; 
    int Arg3 = 3; 
    verify_case(1, Arg3, feedMost(Arg0, Arg1, Arg2)); }
	void test_case_2() { 
    int Arr0[] = {1,1,1,1,1}; 
    vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
    int Arr1[] = {1000,1000,1000,1000,1000}; 
    vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); 
    int Arg2 = 10; 
    int Arg3 = 1; 
    verify_case(2, Arg3, feedMost(Arg0, Arg1, Arg2)); }
	void test_case_3() { 
    int Arr0[] = {1,2,3,4,5,6,7,8,9,10}; 
    vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
    int Arr1[] = {10,9,8,7,6,5,4,3,2,1}; 
    vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); 
    int Arg2 = 100; 
    int Arg3 = 5; 
    verify_case(3, Arg3, feedMost(Arg0, Arg1, Arg2)); }
	void test_case_4() { 
    int Arr0[] = {1,2,3}; 
    vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
    int Arr1[] = {2,2,1}; 
    vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); 
    int Arg2 = 7; 
    int Arg3 = 2; 
    verify_case(4, Arg3, feedMost(Arg0, Arg1, Arg2)); }
	void test_case_5() { 
    int Arr0[] = {1,2,3}; 
    vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
    int Arr1[] = {2,2,1}; 
    vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); 
    int Arg2 = 7; 
    int Arg3 = 2; 
    verify_case(5, Arg3, feedMost(Arg0, Arg1, Arg2)); }

  // END CUT HERE

};
// BEGIN CUT HERE
int main() {
Badgers ___test;
___test.run_test(-1);
}
// END CUT HERE 
