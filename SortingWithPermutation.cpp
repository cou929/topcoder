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
class SortingWithPermutation {
public:
  vector <int> getPermutation(vector <int> a) {
    vector <int> ret;
    vector <int> sorted = a;
    int n = a.size();
    vector <bool> used(n, false);
    int i, j;

    sort(sorted.begin(), sorted.end());

    for (i=0; i<n; i++)
      for (j=0; j<n; j++)
        if (a[i] == sorted[j] && !used[j]) {
          ret.push_back(j);
          used[j] = true;
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
  }
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { 
    int Arr0[] = {2, 3, 1}; 
    vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
    int Arr1[] = {1, 2, 0 }; 
    vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); 
    verify_case(0, Arg1, getPermutation(Arg0)); }
	void test_case_1() { 
    int Arr0[] = {2, 1, 3, 1}; 
    vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
    int Arr1[] = {2, 0, 3, 1 }; 
    vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); 
    verify_case(1, Arg1, getPermutation(Arg0)); }
	void test_case_2() { 
    int Arr0[] = {4, 1, 6, 1, 3, 6, 1, 4}; 
    vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
    int Arr1[] = {4, 0, 6, 1, 3, 7, 2, 5 }; 
    vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); 
    verify_case(2, Arg1, getPermutation(Arg0)); }
	void test_case_3() { 
    int Arr0[] = {221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221}; 
    vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
    int Arr1[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29}; 
    vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); 
    verify_case(3, Arg1, getPermutation(Arg0)); }
	void test_case_4() { 
    int Arr0[] = {2, 3, 1}; 
    vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
    int Arr1[] = {1, 2, 0 }; 
    vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); 
    verify_case(4, Arg1, getPermutation(Arg0)); }

  // END CUT HERE

};
// BEGIN CUT HERE
int main() {
SortingWithPermutation ___test;
___test.run_test(-1);
}
// END CUT HERE 
