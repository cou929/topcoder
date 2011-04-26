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
class MathContest {
public:
  int countBlack(string ballSequence, int repetitions) {
    int ret = 0;
    int rev = true;
    int pos = true;
    string seq = "";
    int left = 0, right = 0;
    int i;

    for (i=0; i<repetitions; i++)
      seq += ballSequence;

    right = seq.size() - 1;

    while (left <= right) {
      if (pos) {
        char cur = seq[left];
        left++;
        if (cur == 'B') {
          if (rev) {
            ret++;
            rev = !rev;
          } else {
            pos = !pos;
          }
        } else {
          if (rev) {
            pos = !pos;
          } else {
            ret++;
            rev = !rev;
          }
        }
      } else {
        char cur = seq[right];
        right--;
        if (cur == 'B') {
          if (rev) {
            ret++;
            rev = !rev;
          } else {
            pos = !pos;
          }
        } else {
          if (rev) {
            pos = !pos;
          } else {
            ret++;
            rev = !rev;
          }
        }
      }
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
    string Arg0 = "BBWWB"; 
    int Arg1 = 1; 
    int Arg2 = 2; 
    verify_case(0, Arg2, countBlack(Arg0, Arg1)); }
	void test_case_1() { 
    string Arg0 = "BBB"; 
    int Arg1 = 10; 
    int Arg2 = 1; 
    verify_case(1, Arg2, countBlack(Arg0, Arg1)); }
	void test_case_2() { 
    string Arg0 = "BW"; 
    int Arg1 = 10; 
    int Arg2 = 20; 
    verify_case(2, Arg2, countBlack(Arg0, Arg1)); }
	void test_case_3() { 
    string Arg0 = "WWWWWWWBWWWWWWWWWWWWWW"; 
    int Arg1 = 1; 
    int Arg2 = 2; 
    verify_case(3, Arg2, countBlack(Arg0, Arg1)); }
	void test_case_4() { 
    string Arg0 = "BBWWBBBWWBBBWWBBBWWBBBWWBBBWWBBBWWBBBWWB"; 
    int Arg1 = 2000; 
    int Arg2 = 2; 
    verify_case(4, Arg2, countBlack(Arg0, Arg1)); }
	void test_case_5() { 
    string Arg0 = "BBWWB"; 
    int Arg1 = 1; 
    int Arg2 = 2; 
    verify_case(5, Arg2, countBlack(Arg0, Arg1)); }

  // END CUT HERE

};
// BEGIN CUT HERE
int main() {
  MathContest ___test;
  ___test.run_test(-1);
}
// END CUT HERE 
