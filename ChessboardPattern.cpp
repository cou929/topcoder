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
using namespace std;
class ChessboardPattern {
public:
  vector <string> makeChessboard(int rows, int columns)
  {
    vector <string> ret;
    char pat[] = {'.', 'X'};

    for (int i=0; i<rows; i++)
      {
	string tmp;
	int s = 0;
	if (i % 2 != 0)
	  s = 1;
	for (int j=0; j<columns; j++)
	  {
	    tmp.push_back(pat[s]);
	    s = (s + 1) % 2;
	  }
	ret.push_back(tmp);
      }

    reverse(ret.begin(), ret.end());

    return ret;
  }
   
  // BEGIN CUT HERE
public:
  void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
private:
  template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
  void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
  void test_case_0() { int Arg0 = 8; int Arg1 = 8; string Arr2[] = {"X.X.X.X.", ".X.X.X.X", "X.X.X.X.", ".X.X.X.X", "X.X.X.X.", ".X.X.X.X", "X.X.X.X.", ".X.X.X.X" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, makeChessboard(Arg0, Arg1)); }
  void test_case_1() { int Arg0 = 1; int Arg1 = 20; string Arr2[] = {".X.X.X.X.X.X.X.X.X.X" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, makeChessboard(Arg0, Arg1)); }
  void test_case_2() { int Arg0 = 5; int Arg1 = 1; string Arr2[] = {".", "X", ".", "X", "." }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(2, Arg2, makeChessboard(Arg0, Arg1)); }
  void test_case_3() { int Arg0 = 5; int Arg1 = 13; string Arr2[] = {".X.X.X.X.X.X.", "X.X.X.X.X.X.X", ".X.X.X.X.X.X.", "X.X.X.X.X.X.X", ".X.X.X.X.X.X." }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(3, Arg2, makeChessboard(Arg0, Arg1)); }

  // END CUT HERE

};
// BEGIN CUT HERE
int main() {
ChessboardPattern ___test;
___test.run_test(-1);
}
// END CUT HERE 
