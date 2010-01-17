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
class MarblesRegroupingHard {
   public:
   int minMoves(vector <string> boxes)
  {

  }
   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"0"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(0, Arg1, minMoves(Arg0)); }
	void test_case_1() { string Arr0[] = {"77 97","8 0"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 77; verify_case(1, Arg1, minMoves(Arg0)); }
	void test_case_2() { string Arr0[] = {"6 97 7","73 45 0","67 45 63"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 170; verify_case(2, Arg1, minMoves(Arg0)); }
	void test_case_3() { string Arr0[] = {"97 94 0 99","1 72 46 45","0 10 47 75","0 92 76 20","2 25 98 22"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 559; verify_case(3, Arg1, minMoves(Arg0)); }
	void test_case_4() { string Arr0[] = {"38 0 0 45 77 61 0 0 8 87 65 53 0 2",
 "0 97 79 37 70 0 69 35 95 11 75 96 77 29",
 "39 32 0 24 63 22 91 71 0 63 92 59 12 0",
 "34 0 0 71 88 13 60 56 0 22 29 89 81 53",
 "69 95 65 0 94 98 84 37 0 87 16 0 58 18",
 "82 0 36 88 0 54 82 40 6 0 34 44 80 2",
 "33 58 7 95 83 87 0 0 79 35 0 51 22 84",
 "7 0 30 57 33 4 0 26 44 55 67 31 88 42",
 "62 58 62 93 91 0 1 0 44 23 95 0 55 57",
 "35 8 22 26 76 0 78 54 0 46 42 0 0 64",
 "93 54 58 0 89 89 0 0 57 0 98 3 24 0",
 "9 0 0 23 82 18 0 46 0 0 94 84 19 18",
 "78 12 6 45 0 80 16 69 59 76 35 0 66 0",
 "0 68 77 13 15 0 52 72 0 0 18 65 23 0",
 "0 0 73 53 0 95 91 44 27 96 85 0 99 85",
 "93 29 4 89 27 44 27 17 21 6 0 8 3 91",
 "0 46 73 94 60 59 15 50 18 75 74 88 46 93",
 "0 0 0 94 93 26 21 83 54 62 0 89 59 77",
 "32 98 0 44 34 38 56 20 0 61 29 94 52 57",
 "52 60 0 22 0 5 38 0 50 98 12 75 0 81",
 "23 0 41 18 36 87 49 32 62 43 22 74 0 97",
 "0 0 30 79 16 73 61 0 75 51 64 13 45 0",
 "11 0 14 2 0 1 2 16 84 37 95 45 48 33",
 "10 0 0 35 0 85 28 76 99 74 76 32 52 8",
 "60 0 96 0 95 26 59 13 0 0 44 42 97 48",
 "34 7 77 25 91 85 35 78 32 99 7 29 18 15",
 "61 50 43 22 42 63 64 50 9 94 42 22 21 33",
 "58 0 41 10 16 0 27 67 83 27 14 37 98 47",
 "37 60 60 76 71 2 84 32 27 39 82 84 0 94",
 "15 98 69 82 36 66 0 97 62 39 0 65 62 67",
 "0 41 0 43 0 0 94 0 0 58 0 0 27 33",
 "53 90 71 91 85 0 32 86 40 60 11 0 99 28",
 "79 62 0 0 79 0 14 62 87 76 35 0 70 0",
 "0 40 73 48 0 63 0 0 63 5 30 18 47 51",
 "75 6 58 69 33 57 66 0 12 0 46 0 65 10"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 18618; verify_case(4, Arg1, minMoves(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
MarblesRegroupingHard ___test;
___test.run_test(-1);
}
// END CUT HERE 
