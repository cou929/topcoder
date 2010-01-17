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
class RussianSpeedLimits {
public:
  int toInt(string s) {int r = 0; istringstream ss(s); ss >> r; return r;}
  int getCurrentLimit(vector <string> signs) {
    int ret = 0;
    bool in_city = true;

    for (int i=0; i<signs.size(); i++) {
      if (signs[i][0] == 'd') {
        ret = (in_city) ? 60 : 90;
      } else if (signs[i][0] == 'c') {
        ret = (in_city) ? 90 : 60;
        in_city = (in_city) ? false : true;
      } else {
        ret = toInt(signs[i]);
      }
    }

    return ret;
  }
  
  // BEGIN CUT HERE
public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); if ((Case == -1) || (Case == 7)) test_case_7(); }
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"80"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 80; verify_case(0, Arg1, getCurrentLimit(Arg0)); }
	void test_case_1() { string Arr0[] = {"40", "70", "default", "20", "50"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 50; verify_case(1, Arg1, getCurrentLimit(Arg0)); }
	void test_case_2() { string Arr0[] = {"40", "70", "default"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 60; verify_case(2, Arg1, getCurrentLimit(Arg0)); }
	void test_case_3() { string Arr0[] = {"40", "80", "city"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 90; verify_case(3, Arg1, getCurrentLimit(Arg0)); }
	void test_case_4() { string Arr0[] = {"city", "60"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 60; verify_case(4, Arg1, getCurrentLimit(Arg0)); }
	void test_case_5() { string Arr0[] = {"city", "50", "default"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 90; verify_case(5, Arg1, getCurrentLimit(Arg0)); }
	void test_case_6() { string Arr0[] = {"city", "city", "city", "city"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 60; verify_case(6, Arg1, getCurrentLimit(Arg0)); }
	void test_case_7() { string Arr0[] = {"20", "city", "city", "50", "60"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 60; verify_case(7, Arg1, getCurrentLimit(Arg0)); }

  // END CUT HERE

};
// BEGIN CUT HERE
int main() {
RussianSpeedLimits ___test;
___test.run_test(-1);
}
// END CUT HERE 
