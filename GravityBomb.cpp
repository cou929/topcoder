// BEGIN CUT HERE
// END CUT HERE
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>

using namespace std;

class GravityBomb {
public:
  vector <string> aftermath(vector <string> board)
  {
    int i, j, min, max, tmp;
    vector <int> colBlockNum;
    vector <string> ret(board.size());

    for (i=0; i<board[0].size(); i++)
      colBlockNum.push_back(0);

    for (i=0; i<board.size(); i++)
      for (j=0; j<board[0].size(); j++)
	if (board[i][j] == 'X')
	  colBlockNum[j]++;

    min = colBlockNum[0];
    max = colBlockNum[0];
    for (i=1; i<colBlockNum.size(); i++)
      {
	if (min > colBlockNum[i])
	  min = colBlockNum[i];
	if (max < colBlockNum[i])
	  max = colBlockNum[i];
      }

    for (i=0; i<colBlockNum.size(); i++)
      colBlockNum[i] -= min;
    max -= min;

    for (i=0; i<board.size()-max; i++)
      for (j=0; j<board[0].size(); j++)
	ret[i].push_back('.');

    tmp = i;
    cout << i << endl;

    for (i=0; i<max; i++)
      for (j=0; j<board[0].size(); j++)
	if ((colBlockNum[j] - max + i + 1) > 0)
	  ret[i+tmp].push_back('X');
	else
	  ret[i+tmp].push_back('.');

    return ret;
  }

   
  // BEGIN CUT HERE
public:
  void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
private:
  template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
  void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
  void test_case_0() { string Arr0[] = {"..X",
					"X.X",
					".X."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "...",  "...",  "..X" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, aftermath(Arg0)); }
  void test_case_1() { string Arr0[] = {"...",
					"X..",
					".X."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "...",  "...",  "XX." }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, aftermath(Arg0)); }
  void test_case_2() { string Arr0[] = {"XXXXXX",
					"......",
					"......"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "......",  "......",  "......" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, aftermath(Arg0)); }
  void test_case_3() { string Arr0[] = {"XX.XX....XX"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "XX.XX....XX" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, aftermath(Arg0)); }
  void test_case_4() { string Arr0[] = {"X",".",".",".",".",".",".",".",".",".",".",".",".",
					".",".",".",".",".",".",".",".",".",".",".",".",".",
					".",".",".",".",".",".",".",".",".",".",".",".",".",
					".",".",".",".",".",".",".",".",".",".","."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { ".",  ".",  ".",  ".",  ".",  ".",  ".",  ".",  ".",  ".",  ".",  ".",  ".",  ".",  ".",  ".",  ".",  ".",  ".",  ".",  ".",  ".",  ".",  ".",  ".",  ".",  ".",  ".",  ".",  ".",  ".",  ".",  ".",  ".",  ".",  ".",  ".",  ".",  ".",  ".",  ".",  ".",  ".",  ".",  ".",  ".",  ".",  ".",  ".",  "." }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(4, Arg1, aftermath(Arg0)); }
  void test_case_5() { string Arr0[] = {"XXX", "XXX"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "...",  "..." }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(5, Arg1, aftermath(Arg0)); }

  // END CUT HERE

};

// BEGIN CUT HERE
int main() {
GravityBomb ___test;
___test.run_test(-1);
}
// END CUT HERE 
