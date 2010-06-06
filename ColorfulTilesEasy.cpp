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
class ColorfulTilesEasy {
public:
  int theMin(string room) {
    int ret = 0;
    int i;
    int n = room.size();

    for (i=1; i<n; i++)
      if (room[i-1] == room[i]) {
        ret++;
        room[i] = 'A';
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
    string Arg0 = "RRRRRR"; 
    int Arg1 = 3; 
    verify_case(0, Arg1, theMin(Arg0)); }
	void test_case_1() { 
    string Arg0 = "GGGGGGG"; 
    int Arg1 = 3; 
    verify_case(1, Arg1, theMin(Arg0)); }
	void test_case_2() { 
    string Arg0 = "BBBYYYYYY"; 
    int Arg1 = 4; 
    verify_case(2, Arg1, theMin(Arg0)); }
	void test_case_3() { 
    string Arg0 = "BRYGYBGRYR"; 
    int Arg1 = 0; 
    verify_case(3, Arg1, theMin(Arg0)); }
	void test_case_4() { 
    string Arg0 = "RGGBBBRYYB"; 
    int Arg1 = 3; 
    verify_case(4, Arg1, theMin(Arg0)); }
	void test_case_5() { 
    string Arg0 = "RRRRRR"; 
    int Arg1 = 3; 
    verify_case(5, Arg1, theMin(Arg0)); }
	void test_case_6() { 
    string Arg0 = "RRRRRR"; 
    int Arg1 = 3; 
    verify_case(6, Arg1, theMin(Arg0)); }

  // END CUT HERE

};
// BEGIN CUT HERE
int main() {
ColorfulTilesEasy ___test;
___test.run_test(-1);
}
// END CUT HERE 
