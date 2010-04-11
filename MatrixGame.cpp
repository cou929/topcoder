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
class MatrixGame {
public:
  vector <string> getMinimal(vector <string> matrix) {
    vector <string> ret = matrix;
    vector <int> p;
    int i, j;

    for (i=0; i<matrix[0].size(); i++) p.push_back(i);

    do {
      vector <string> cur = matrix;
      for (i=0; i<p.size(); i++)
        for (j=0; j<matrix.size(); j++)
          cur[j][p[i]] = matrix[j][i];
      sort(cur.begin(), cur.end());
      if (cur < ret)
        ret = cur;
    } while (next_permutation(p.begin(), p.end()));

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
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { 
    string Arr0[] = {"000",
                     "000",
                     "000"}; 
    vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
    string Arr1[] = {"000", "000", "000" }; 
    vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); 
    verify_case(0, Arg1, getMinimal(Arg0)); }
	void test_case_1() { 
    string Arr0[] = {"010",
                     "000",
                     "110"}; 
    vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
    string Arr1[] = {"000", "001", "011" }; 
    vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); 
    verify_case(1, Arg1, getMinimal(Arg0)); }
	void test_case_2() { 
    string Arr0[] = {"111",
                     "111",
                     "111"}; 
    vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
    string Arr1[] = {"111", "111", "111" }; 
    vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); 
    verify_case(2, Arg1, getMinimal(Arg0)); }
	void test_case_3() { 
    string Arr0[] = {"01010",
                     "10101",
                     "01010",
                     "10101"}; 
    vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
    string Arr1[] = {"00011", "00011", "11100", "11100" }; 
    vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); 
    verify_case(3, Arg1, getMinimal(Arg0)); }
	void test_case_4() { 
    string Arr0[] = {"11010100",
                     "11110001",
                     "00011101",
                     "11111111",
                     "01110100",
                     "10000110",
                     "00001001",
                     "11010111"}; 
    vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
    string Arr1[] = {"00000011", "00001111", "00110100", "01011100", "01111101", "11001100", "11011001", "11111111" }; 
    vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); 
    verify_case(4, Arg1, getMinimal(Arg0)); }
	void test_case_5() { 
    string Arr0[] = {"000",
                     "000",
                     "000"}; 
    vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
    string Arr1[] = {"000", "000", "000" }; 
    vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); 
    verify_case(5, Arg1, getMinimal(Arg0)); }
	void test_case_6() { 
    string Arr0[] = {"000",
                     "000",
                     "000"}; 
    vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
    string Arr1[] = {"000", "000", "000" }; 
    vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); 
    verify_case(6, Arg1, getMinimal(Arg0)); }

  // END CUT HERE

};
// BEGIN CUT HERE
int main() {
MatrixGame ___test;
___test.run_test(-1);
}
// END CUT HERE 
