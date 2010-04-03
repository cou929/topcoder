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
class NumberNeighbours {
public:
  string toStr(int n) {ostringstream ss; ss << n; return ss.str();}
  int numPairs(vector <int> numbers) {
    int ret = 0;
    int i, j, k;
    int n = numbers.size();

    for (i=0; i<n; i++)
      for (j=i+1; j<n; j++) {
        string a = toStr(numbers[i]), b = toStr(numbers[j]);
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        for (k=0; k<a.size(); k++) if (a[k] != '0') break;
        if (k != 0) a.erase(0, k);
        for (k=0; k<b.size(); k++) if (b[k] != '0') break;
        if (k != 0) b.erase(0, k);
        if (a == b) ret++;
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
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { 
    int Arr0[] = {10, 1, 100, 20, 2, 3}; 
    vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
    int Arg1 = 4; 
    verify_case(0, Arg1, numPairs(Arg0)); }
	void test_case_1() { 
    int Arr0[] = {204, 42, 40020, 200}; 
    vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
    int Arg1 = 3; 
    verify_case(1, Arg1, numPairs(Arg0)); }
	void test_case_2() { 
    int Arr0[] = {1, 10, 100, 1000, 10000, 100000, 1000000}; 
    vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
    int Arg1 = 21; 
    verify_case(2, Arg1, numPairs(Arg0)); }
	void test_case_3() { 
    int Arr0[] = {3, 33, 333, 3333}; 
    vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
    int Arg1 = 0; 
    verify_case(3, Arg1, numPairs(Arg0)); }
	void test_case_4() { 
    int Arr0[] = {1024, 4021, 204, 303, 33, 603, 36, 55, 505}; 
    vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
    int Arg1 = 4; 
    verify_case(4, Arg1, numPairs(Arg0)); }
	void test_case_5() { 
    int Arr0[] = {10, 1, 100, 20, 2, 3}; 
    vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
    int Arg1 = 4; 
    verify_case(5, Arg1, numPairs(Arg0)); }
	void test_case_6() { 
    int Arr0[] = {10, 1, 100, 20, 2, 3}; 
    vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
    int Arg1 = 4; 
    verify_case(6, Arg1, numPairs(Arg0)); }

  // END CUT HERE

};
// BEGIN CUT HERE
int main() {
NumberNeighbours ___test;
___test.run_test(-1);
}
// END CUT HERE 
