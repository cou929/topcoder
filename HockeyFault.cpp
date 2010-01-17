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

using namespace std;

class HockeyFault {
public:
  int numPlayers(int width, int height, int x, int y, vector <int> px, vector <int> py)
  {
    int i, ret=0;

    for (i=0; i<px.size(); i++)
      {
	if (px[i] >= x && py[i] >= y && px[i] <= x+width && py[i] <= y+height)
	  {
	    ret++;
	    continue;
	  }

	int rad = height/2;
	int cxl = px[i] - x;
	int cyl = py[i] - (y + rad);
	int cxr = px[i] - (x + width);
	int cyr = py[i] - (y + rad);
	int rad2 = rad*rad;

	if ((cxl*cxl + cyl*cyl) <= rad2 || (cxr*cxr + cyr*cyr) <= rad2)
	  {
	    ret++;
	    continue;
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
  void test_case_0() { int Arg0 = 20; int Arg1 = 10; int Arg2 = 5; int Arg3 = 0; int Arr4[] = {15, 1, 1}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arr5[] = {5, 5, 1}; vector <int> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0]))); int Arg6 = 2; verify_case(0, Arg6, numPlayers(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
  void test_case_1() { int Arg0 = 20; int Arg1 = 10; int Arg2 = 0; int Arg3 = 0; int Arr4[] = {-5, -4, -4, -3, -3, 0, 0, 20, 20, 23, 23, 24, 24, 25}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arr5[] = {5, 2, 8, 1, 9, 0, 10, 0, 10, 1, 9, 2, 8, 5}; vector <int> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0]))); int Arg6 = 14; verify_case(1, Arg6, numPlayers(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
  void test_case_2() { int Arg0 = 52; int Arg1 = 84; int Arg2 = -44; int Arg3 = 66; int Arr4[] = {26, -33, -49, 40, -10, 47, 25, -16, -82, 7}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arr5[] = {118, 106, 128, 114, 101, 85, 142, 140, 126, 145}; vector <int> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0]))); int Arg6 = 8; verify_case(2, Arg6, numPlayers(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
  void test_case_3() { int Arg0 = 24; int Arg1 = 100; int Arg2 = -61; int Arg3 = 71; int Arr4[] = {-63, -26, -9, -113, -124, -95, -89, -55}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arr5[] = {109, 164, 91, 80, 75, 140, 116, 113}; vector <int> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0]))); int Arg6 = 6; verify_case(3, Arg6, numPlayers(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }

  // END CUT HERE

};

// BEGIN CUT HERE
int main() {
HockeyFault ___test;
___test.run_test(-1);
}
// END CUT HERE 
