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
class InterestingParty {
  public:
  int bestInvitation(vector <string> first, vector <string> second) {
    int ret = 0;
    set <string> dic;
    int i;

    for (i=0; i<first.size(); i++) {
      dic.insert(first[i]);
      dic.insert(second[i]);
    }

    for (set <string>::iterator it=dic.begin(); it!=dic.end(); it++) {
      int c = 0;
      for (i=0; i<first.size(); i++)
        if (first[i] == *it || second[i] == *it)
          c++;
      ret = max(ret, c);
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
	string Arr0[] = {"fishing", "gardening", "swimming", "fishing"}; 
	vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
	string Arr1[] = {"hunting", "fishing", "fishing", "biting"}; 
	vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); 
	int Arg2 = 4; 
	verify_case(0, Arg2, bestInvitation(Arg0, Arg1)); }
	void test_case_1() { 
	string Arr0[] = {"variety", "diversity", "loquacity", "courtesy"}; 
	vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
	string Arr1[] = {"talking", "speaking", "discussion", "meeting"}; 
	vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); 
	int Arg2 = 1; 
	verify_case(1, Arg2, bestInvitation(Arg0, Arg1)); }
	void test_case_2() { 
	string Arr0[] = {"snakes", "programming", "cobra", "monty"}; 
	vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
	string Arr1[] = {"python", "python", "anaconda", "python"}; 
	vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); 
	int Arg2 = 3; 
	verify_case(2, Arg2, bestInvitation(Arg0, Arg1)); }
	void test_case_3() { 
	string Arr0[] = {"t", "o", "p", "c", "o", "d", "e", "r", "s", "i", "n", "g", "l", "e", "r",
 "o", "u", "n", "d", "m", "a", "t", "c", "h", "f", "o", "u", "r", "n", "i"}; 
	vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
	string Arr1[] = {"n", "e", "f", "o", "u", "r", "j", "a", "n", "u", "a", "r", "y", "t", "w", 
 "e", "n", "t", "y", "t", "w", "o", "s", "a", "t", "u", "r", "d", "a", "y"}; 
	vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); 
	int Arg2 = 6; 
	verify_case(3, Arg2, bestInvitation(Arg0, Arg1)); }
	void test_case_4() { 
	string Arr0[] = {"fishing", "gardening", "swimming", "fishing"}; 
	vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
	string Arr1[] = {"hunting", "fishing", "fishing", "biting"}; 
	vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); 
	int Arg2 = 4; 
	verify_case(4, Arg2, bestInvitation(Arg0, Arg1)); }
	void test_case_5() { 
	string Arr0[] = {"fishing", "gardening", "swimming", "fishing"}; 
	vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
	string Arr1[] = {"hunting", "fishing", "fishing", "biting"}; 
	vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); 
	int Arg2 = 4; 
	verify_case(5, Arg2, bestInvitation(Arg0, Arg1)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
InterestingParty ___test;
___test.run_test(-1);
}
// END CUT HERE 
