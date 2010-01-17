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
class RGBStreet {
public:
  int mini;
  vector <string> houses;

  int s(int _rgb, int n, int cost)
  {
    int rgb[3];

    if (n == houses.size())
      {
	mini = min(mini, cost);
	return 0;
      }

    sscanf(houses[n].c_str(), "%d %d %d", &rgb[0], &rgb[1], &rgb[2]);

    for (int i=0; i<3; i++)
      {
	if (i != _rgb)
	  {
	    int tmp = rgb[i] + cost;
	    if (cost < mini)
	      s(i, n+1, tmp);
	  }
      }
    return 0;
  }

  int estimateCost(vector <string> _h)
  {
    mini = 1000*20;
    houses = _h;

    s(4, 0, 0);

    return mini;
  }
   
  // BEGIN CUT HERE
public:
  void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
private:
  template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
  void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
  void test_case_0() { string Arr0[] = {"1 100 100", "100 1 100", "100 100 1"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(0, Arg1, estimateCost(Arg0)); }
  void test_case_1() { string Arr0[] = {"1 100 100", "100 100 100", "1 100 100"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 102; verify_case(1, Arg1, estimateCost(Arg0)); }
  void test_case_2() { string Arr0[] = {"26 40 83", "49 60 57", "13 89 99"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 96; verify_case(2, Arg1, estimateCost(Arg0)); }
  void test_case_3() { string Arr0[] = {"30 19 5", "64 77 64", "15 19 97", "4 71 57", "90 86 84", "93 32 91"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 208; verify_case(3, Arg1, estimateCost(Arg0)); }
  void test_case_4() { string Arr0[] = {"71 39 44", "32 83 55", "51 37 63", "89 29 100", 
					"83 58 11", "65 13 15", "47 25 29", "60 66 19"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 253; verify_case(4, Arg1, estimateCost(Arg0)); }

  // END CUT HERE

};
// BEGIN CUT HERE
int main() {
RGBStreet ___test;
___test.run_test(-1);
}
// END CUT HERE 
