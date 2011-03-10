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
class SumRectangle {
public:
  int getCorner(vector <int> leftColumn, vector <int> topRow) {
    int i, j;
    int rect[leftColumn.size()][topRow.size()];

    for (i=0; i<leftColumn.size(); i++)
      for (j=0; j<topRow.size(); j++) {
        if (j == 0)
          rect[i][j] = leftColumn[i];
        else if (i == 0)
          rect[i][j] = topRow[j];
        else
          rect[i][j] = 0;
      }

    for (i=1; i<leftColumn.size(); i++)
      for (j=1; j<topRow.size(); j++)
        rect[i][j] = rect[i-1][j-1] - rect[i][j-1] - rect[i-1][j];

    return rect[leftColumn.size()-1][topRow.size()-1];
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
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { 
    int Arr0[] = {88,18,1}; 
    vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
    int Arr1[] = {88,57,33,10,5}; 
    vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); 
    int Arg2 = 18; 
    verify_case(0, Arg2, getCorner(Arg0, Arg1)); }
	void test_case_1() { 
    int Arr0[] = {0,0,0,0}; 
    vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
    int Arr1[] = {0,0,0,0}; 
    vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); 
    int Arg2 = 0; 
    verify_case(1, Arg2, getCorner(Arg0, Arg1)); }
	void test_case_2() { 
    int Arr0[] = {6,1}; 
    vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
    int Arr1[] = {6,2}; 
    vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); 
    int Arg2 = 3; 
    verify_case(2, Arg2, getCorner(Arg0, Arg1)); }
	void test_case_3() { 
    int Arr0[] = {88,18,1}; 
    vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
    int Arr1[] = {88,57,33,10,5}; 
    vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); 
    int Arg2 = 18; 
    verify_case(3, Arg2, getCorner(Arg0, Arg1)); }
	void test_case_4() { 
    int Arr0[] = {88,18,1}; 
    vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
    int Arr1[] = {88,57,33,10,5}; 
    vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); 
    int Arg2 = 18; 
    verify_case(4, Arg2, getCorner(Arg0, Arg1)); }

  // END CUT HERE

};
// BEGIN CUT HERE
int main() {
SumRectangle ___test;
___test.run_test(-1);
}
// END CUT HERE 
