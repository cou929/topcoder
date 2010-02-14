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
const int INF = 100000;
class ColoringRectangle {
public:
  int w, h;
  double length(double r) {
    return 2.0 * sqrt(r * r - ((double)h/2.0) * ((double)h/2.0));
  }

  int solve(vector <int> a, vector <int> b) {
    int ret = 0;
    int i = 0, j = 0;
    double len = 0;
    int which = 1;
    
    while (len + 1e-8 < w) {
      if (which) {
        if (i >= a.size()) return INF;
        len += length((double)a[i++] / 2.0);
        ret++;
      } else {
        if (j >= b.size()) return INF;
        len += length((double)b[j++] / 2.0);
        ret++;
      }

      which = 1 - which;
    }

    return ret;
  }

  int chooseDisks(int width, int height, vector <int> _red, vector <int> _blue) {
    int ret = 0;
    int i;
    vector <int> red;
    vector <int> blue;
    w = width, h = height;

    for (i=0; i<_red.size(); i++)
      if (_red[i] >= height)
        red.push_back(_red[i]);

    for (i=0; i<_blue.size(); i++)
      if (_blue[i] >= height)
        blue.push_back(_blue[i]);

    sort(red.rbegin(), red.rend());
    sort(blue.rbegin(), blue.rend());

    ret = min(solve(red, blue), solve(blue, red));
    if (ret == INF) ret = -1;

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
    int Arg0 = 11; 
    int Arg1 = 3; 
    int Arr2[] = {5,5}; 
    vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); 
    int Arr3[] = {2,5}; 
    vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); 
    int Arg4 = 3; 
    verify_case(0, Arg4, chooseDisks(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { 
    int Arg0 = 30; 
    int Arg1 = 5; 
    int Arr2[] = {4,10,7,8,10}; 
    vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); 
    int Arr3[] = {5,6,11,7,5}; 
    vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); 
    int Arg4 = 4; 
    verify_case(1, Arg4, chooseDisks(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { 
    int Arg0 = 16; 
    int Arg1 = 4; 
    int Arr2[] = {6,5,7}; 
    vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); 
    int Arr3[] = {5}; 
    vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); 
    int Arg4 = -1; 
    verify_case(2, Arg4, chooseDisks(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { 
    int Arg0 = 4; 
    int Arg1 = 4; 
    int Arr2[] = {5}; 
    vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); 
    int Arr3[] = {6}; 
    vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); 
    int Arg4 = 1; 
    verify_case(3, Arg4, chooseDisks(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { 
    int Arg0 = 6; 
    int Arg1 = 2; 
    int Arr2[] = {6,6}; 
    vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); 
    int Arr3[] = {2}; 
    vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); 
    int Arg4 = 3; 
    verify_case(4, Arg4, chooseDisks(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_5() { 
    int Arg0 = 11; 
    int Arg1 = 3; 
    int Arr2[] = {5,5}; 
    vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); 
    int Arr3[] = {2,5}; 
    vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); 
    int Arg4 = 3; 
    verify_case(5, Arg4, chooseDisks(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_6() { 
    int Arg0 = 8284; 
    int Arg1 = 54; 
    int Arr2[] = {162, 90, 89, 73, 172, 141, 80, 133, 154, 64, 141, 56, 174, 102, 77, 191, 130, 191, 180, 158, 69, 106, 136, 112, 79, 94, 73, 193, 195, 71, 171, 72, 147, 126, 145, 131}; 
    vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); 
    int Arr3[] = {111, 84, 67, 126, 106, 114, 116, 171, 176, 82, 102, 142, 81, 191, 78, 105, 192, 115, 142, 106, 196, 157, 144, 108, 89, 97, 56, 107, 112, 182, 112, 80, 126, 191, 101, 197, 169, 156, 113, 56, 134, 70}; 
    vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); 
    int Arg4 = 73; 
    verify_case(6, Arg4, chooseDisks(Arg0, Arg1, Arg2, Arg3)); }



  // END CUT HERE

};
// BEGIN CUT HERE
int main() {
ColoringRectangle ___test;
___test.run_test(-1);
}
// END CUT HERE 
