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
class RepaintTheChessboard {
public:
  int minimumChanges(vector <string> board) {
    int ret = 64;
    int i, j, k, l;
    char board1[8][8] = {{'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'}, {'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
                         {'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'}, {'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
                         {'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'}, {'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
                         {'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'}, {'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'}};
    char board2[8][8] = {{'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'}, {'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
                         {'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'}, {'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
                         {'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'}, {'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
                         {'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'}, {'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'}};

    for (i=0; i<=board.size()-8; i++)
      for (j=0; j<=board[0].size()-8; j++) {
        int tmp1 = 0, tmp2 = 0;
        for (k=0; k<8; k++)
          for (l=0; l<8; l++)
            if (board[i+k][j+l] != board1[k][l])
              tmp1++;
        for (k=0; k<8; k++)
          for (l=0; l<8; l++)
            if (board[i+k][j+l] != board2[k][l])
              tmp2++;
        ret = min(ret, min(tmp1, tmp2));
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
    if ((Case == -1) || (Case == 7)) test_case_7();
  }
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { 
    string Arr0[] = {"BWBWBWBW",
                     "WBWBWBWB",
                     "BWBWBWBW",
                     "WBWBWBWB",
                     "BWBWBWBW",
                     "WBWBWBWB",
                     "BWBWBWBW",
                     "WBWBWBWB"}
    ; 
    vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
    int Arg1 = 0; 
    verify_case(0, Arg1, minimumChanges(Arg0)); }
	void test_case_1() { 
    string Arr0[] = {"WBWBWBWB",
                     "BWBWBWBW",
                     "WBWBWBWB",
                     "BWBBBWBW",
                     "WBWBWBWB",
                     "BWBWBWBW",
                     "WBWBWBWB",
                     "BWBWBWBW"}; 
    vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
    int Arg1 = 1; 
    verify_case(1, Arg1, minimumChanges(Arg0)); }
	void test_case_2() { 
    string Arr0[] = {"BBBBBBBBBBBBBBBBBBBBBBB",
                     "BBBBBBBBBBBBBBBBBBBBBBB",
                     "BBBBBBBBBBBBBBBBBBBBBBB",
                     "BBBBBBBBBBBBBBBBBBBBBBB",
                     "BBBBBBBBBBBBBBBBBBBBBBB",
                     "BBBBBBBBBBBBBBBBBBBBBBB",
                     "BBBBBBBBBBBBBBBBBBBBBBB",
                     "BBBBBBBBBBBBBBBBBBBBBBB",
                     "BBBBBBBBBBBBBBBBBBBBBBW"}
    ; 
    vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
    int Arg1 = 31; 
    verify_case(2, Arg1, minimumChanges(Arg0)); }
	void test_case_3() { 
    string Arr0[] = {"BBBBBBBBBB",
                     "BBWBWBWBWB",
                     "BWBWBWBWBB",
                     "BBWBWBWBWB",
                     "BWBWBWBWBB",
                     "BBWBWBWBWB",
                     "BWBWBWBWBB",
                     "BBWBWBWBWB",
                     "BWBWBWBWBB",
                     "BBBBBBBBBB"}; 
    vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
    int Arg1 = 0; 
    verify_case(3, Arg1, minimumChanges(Arg0)); }
	void test_case_4() { 
    string Arr0[] = {"WBWBWBWB",
                     "BWBWBWBW",
                     "WBWBWBWB",
                     "BWBBBWBW",
                     "WBWBWBWB",
                     "BWBWBWBW",
                     "WBWBWWWB",
                     "BWBWBWBW"}; 
    vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
    int Arg1 = 2; 
    verify_case(4, Arg1, minimumChanges(Arg0)); }
	void test_case_5() { 
    string Arr0[] = {"BWWBWWBWWBWW",
                     "BWWBWBBWWBWW",
                     "WBWWBWBBWWBW",
                     "BWWBWBBWWBWW",
                     "WBWWBWBBWWBW",
                     "BWWBWBBWWBWW",
                     "WBWWBWBBWWBW",
                     "BWWBWBWWWBWW",
                     "WBWWBWBBWWBW",
                     "BWWBWBBWWBWW",
                     "WBWWBWBBWWBW"}
    ; 
    vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
    int Arg1 = 15; 
    verify_case(5, Arg1, minimumChanges(Arg0)); }
	void test_case_6() { 
    string Arr0[] = {"BWBWBWBW",
                     "WBWBWBWB",
                     "BWBWBWBW",
                     "WBWBWBWB",
                     "BWBWBWBW",
                     "WBWBWBWB",
                     "BWBWBWBW",
                     "WBWBWBWB"}
    ; 
    vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
    int Arg1 = 0; 
    verify_case(6, Arg1, minimumChanges(Arg0)); }
	void test_case_7() { 
    string Arr0[] = {"BWBWBWBW",
                     "WBWBWBWB",
                     "BWBWBWBW",
                     "WBWBWBWB",
                     "BWBWBWBW",
                     "WBWBWBWB",
                     "BWBWBWBW",
                     "WBWBWBWB"}
    ; 
    vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
    int Arg1 = 0; 
    verify_case(7, Arg1, minimumChanges(Arg0)); }

  // END CUT HERE

};
// BEGIN CUT HERE
int main() {
RepaintTheChessboard ___test;
___test.run_test(-1);
}
// END CUT HERE 
