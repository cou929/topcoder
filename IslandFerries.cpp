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
class IslandFerries {
   public:
   vector <int> costs(vector <string> legs, vector <string> prices)
  {

  }
   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = { "0-1 0-3", "0-2" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "5 7", "1000 1000", "1000 1000", "1000 1000" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = { 5,  7,  5 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, costs(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = { "0-1 1-2 2-3", "0-1 2-3" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "1 10", "20 25", "50 50", "1000 1000", "1000 1000" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = { 1,  11,  31,  -1 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, costs(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = { "0-1", "1-0", "0-2", "2-3" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "1 1 1000 1000", "1000 1000 10 100", "1000 1000 1000 1000", "1000 1000 1000 1000" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = { 1,  12,  112 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(2, Arg2, costs(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = { "1-0" }
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "793", "350" }
; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = { -1 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(3, Arg2, costs(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"8-18 4-11 15-5 7-12 11-8 0-15 15-2 3-11 4-18 2-3",
 "16-2 18-3 15-18 11-19 18-2 18-7 19-17 3-15 12-19",
 "2-17 0-12 1-2 14-12 6-2 4-2 11-5 4-11 11-6 17-16",
 "0-18 13-18 16-0 3-7 14-12 3-1 19-18 3-19 10-3 8-15",
 "18-19 3-16 13-6 0-19 12-14 5-17 1-12 7-13 9-14 1-2",
 "14-5 17-9 2-10 16-13 11-15 10-17 14-10 0-14 2-13",
 "4-5 0-17 6-9 17-7 12-6 5-6 6-18 10-18 0-2 13-0 8-4",
 "3-12 4-11 10-17 13-12 3-0 3-7 13-0 9-15 10-9 0-10" }
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"592 219 88 529 324 86 503 610",
 "2 94 8 600 34 95 6 494",
 "638 301 10 246 290 97 85 74",
 "118 8 939 393 450 79 317 99",
 "99 806 698 740 2 26 525 818",
 "95 9 615 972 23 23 5 666",
 "6 448 440 710 83 4 419 496",
 "4 47 182 4 185 70 718 770",
 "3 321 6 855 968 65 10 6",
 "173 224 300 3 79 2 707 49",
 "21 10 7 10 4 9 5 8",
 "6 600 4 724 7 1 960 247",
 "83 16 901 50 437 780 658 2",
 "763 923 125 576 45 423 3 1",
 "7 324 391 898 8 59 281 973",
 "9 44 49 364 78 744 43 5",
 "10 62 75 418 216 90 32 919",
 "764 534 778 605 80 647 821 74",
 "65 449 102 867 421 94 6 7",
 "67 155 362 789 189 316 107 595" }
; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = { 170,  160,  155,  173,  145,  150,  158,  168,  153,  145,  162,  88,  162,  86,  163,  159,  153,  150,  104 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(4, Arg2, costs(Arg0, Arg1)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
IslandFerries ___test;
___test.run_test(-1);
}
// END CUT HERE 
