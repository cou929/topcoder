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
class NumericalSequence {
public:
  int makePalindrome(vector <int> sequence)
  {
    int ret = 0;

    while (sequence.size() > 1)
      {
	int left = sequence[0];
	int right = sequence[sequence.size()-1];

	if (left == right)
	  {
	    sequence.erase(sequence.begin());
	    sequence.erase(sequence.end()-1);
	  }
	else
	  {
	    if (left < right)
	      {
		int tmp = sequence[0] + sequence[1];
		sequence.erase(sequence.begin());
		sequence.erase(sequence.begin());
		sequence.insert(sequence.begin(), tmp);
	      }
	    else
	      {
		int tmp = sequence[sequence.size()-1] + sequence[sequence.size()-2];
		sequence.erase(sequence.end()-1);
		sequence.erase(sequence.end()-1);
		sequence.push_back(tmp);
	      }
	    ret++;
	  }
      }

    return ret;
  }
   
  // BEGIN CUT HERE
public:
  void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
private:
  template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
  void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
  void test_case_0() { int Arr0[] = {15,78,78,15}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(0, Arg1, makePalindrome(Arg0)); }
  void test_case_1() { int Arr0[] = {1,1,1,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(1, Arg1, makePalindrome(Arg0)); }
  void test_case_2() { int Arr0[] = {15,78,87,51}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(2, Arg1, makePalindrome(Arg0)); }
  void test_case_3() { int Arr0[] = {3,23,21,23,42,39,63,76,13,13,13,32,12,42,26}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 8; verify_case(3, Arg1, makePalindrome(Arg0)); }

  // END CUT HERE

};
// BEGIN CUT HERE
int main() {
NumericalSequence ___test;
___test.run_test(-1);
}
// END CUT HERE 
