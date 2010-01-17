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
class CreateGroups {
public:
  int minChanges(vector <int> groups, int minSize, int maxSize)
  {
    int ret = 0;
    vector <int> flgs(groups.size(), 0);
    vector <int> nums(groups.size(), 0);
    int overs = 0;
    int unders = 0;

    for (int i=0; i<groups.size(); i++)
      {
	if (groups[i] < minSize)
	  unders += minSize - groups[i];
	else if (groups[i] > maxSize)
	  overs += groups[i] - maxSize;
      }

    if (unders == overs)
      ret = overs;
    else if (unders < overs)
      {
	int capacity = 0;
	for (int i=0; i<groups.size(); i++)
	  {
	    if (groups[i] > maxSize)
	      capacity += 0;
	    else if (groups[i] < minSize)
	      capacity += maxSize - minSize;
	    else
	      capacity += maxSize - groups[i];
	  }

	if (capacity < (overs - unders))
	  ret = -1;
	else
	  ret = overs;
      }
    else if (overs < unders)
      {
	int capacity = 0;
	for (int i=0; i<groups.size(); i++)
	  {
	    if (groups[i] > maxSize)
	      capacity += maxSize - minSize;
	    else if (groups[i] < minSize)
	      capacity += 0;
	    else
	      capacity += groups[i] - minSize;
	  }

	if (capacity < (unders - overs))
	  ret = -1;
	else
	  ret = unders;
      }

    return ret;
  }
   
  // BEGIN CUT HERE
public:
  void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); if ((Case == -1) || (Case == 7)) test_case_7(); if ((Case == -1) || (Case == 8)) test_case_8(); }
private:
  template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
  void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
  void test_case_0() { int Arr0[] = {10,20}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; int Arg2 = 15; int Arg3 = 5; verify_case(0, Arg3, minChanges(Arg0, Arg1, Arg2)); }
  void test_case_1() { int Arr0[] = {20,8,6}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; int Arg2 = 15; int Arg3 = 6; verify_case(1, Arg3, minChanges(Arg0, Arg1, Arg2)); }
  void test_case_2() { int Arr0[] = {10,20,30}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 18; int Arg3 = -1; verify_case(2, Arg3, minChanges(Arg0, Arg1, Arg2)); }
  void test_case_3() { int Arr0[] = {50,10,20,20,5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 15; int Arg2 = 30; int Arg3 = 20; verify_case(3, Arg3, minChanges(Arg0, Arg1, Arg2)); }
  void test_case_4() { int Arr0[] = {100,200,301}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 200; int Arg2 = 200; int Arg3 = -1; verify_case(4, Arg3, minChanges(Arg0, Arg1, Arg2)); }
  void test_case_5() { int Arr0[] = {1,10,10}	; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 9; int Arg2 = 20; int Arg3 = -1; verify_case(5, Arg3, minChanges(Arg0, Arg1, Arg2)); }
  void test_case_6() { int Arr0[] = {55,33,45,71,27,89,16,14,61}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 33; int Arg2 = 56; int Arg3 = 53; verify_case(6, Arg3, minChanges(Arg0, Arg1, Arg2)); }
  void test_case_7() { int Arr0[] = {49,60,36,34,36,52,60,43,52,59}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 45; int Arg2 = 51; int Arg3 = 31; verify_case(7, Arg3, minChanges(Arg0, Arg1, Arg2)); }
  void test_case_8() { int Arr0[] = {5,5,5,5,5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; int Arg2 = 5; int Arg3 = 0; verify_case(8, Arg3, minChanges(Arg0, Arg1, Arg2)); }

  // END CUT HERE

};
// BEGIN CUT HERE
int main() {
CreateGroups ___test;
___test.run_test(-1);
}
// END CUT HERE 
