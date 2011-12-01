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
class DropCoins {
public:
    vector <string> board;
    int K;

    int countCoins(int x, int y, int xlen, int ylen) {
        int i, j;
        int ret = 0;
        
        for (i = x; i < (x + xlen); i++)
            for (j = y; j < (y + ylen); j++)
                if (board[i][j] == 'o')
                    ret++;

        return ret;
    }

    int countStep(int _x, int _y, int xlen, int ylen) {
        int x = min(_x, int(board.size() - xlen - _x));
        int y = min(_y, int(board[0].size() - ylen - _y));
        return x + y + (board.size() - xlen) + (board[0].size() - ylen);
    }

    int getMinimum(vector <string> _board, int _K) {
        board = _board;
        K = _K;
        int ret = 1000000;
        int xlen, ylen, x, y;

        for (xlen = board.size(); xlen >= 1; xlen--)
            for (ylen = board[0].size(); ylen >= 1; ylen--)
                for (x = 0; x <= (board.size() - xlen); x++)
                    for (y = 0; y <= (board[0].size() - ylen); y++) {
                        int res = countCoins(x, y, xlen, ylen);
                        if (res == K)
                            ret = min(countStep(x, y, xlen, ylen), ret);
                    }

        if (ret == 1000000)
            ret = -1;

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
        string Arr0[] = {".o.."
                         ,"oooo"
                         ,"..o."}
        ; 
        vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
        int Arg1 = 3; 
        int Arg2 = 2; 
        verify_case(0, Arg2, getMinimum(Arg0, Arg1)); }
    void test_case_1() { 
        string Arr0[] = {".....o"
                         ,"......"
                         ,"oooooo"
                         ,"oooooo"
                         ,"......"
                         ,"o....."}
        ; 
        vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
        int Arg1 = 12; 
        int Arg2 = 3; 
        verify_case(1, Arg2, getMinimum(Arg0, Arg1)); }
    void test_case_2() { 
        string Arr0[] = {"...."
                         ,".oo."
                         ,".oo."
                         ,"...."}
        ; 
        vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
        int Arg1 = 3; 
        int Arg2 = -1; 
        verify_case(2, Arg2, getMinimum(Arg0, Arg1)); }
    void test_case_3() { 
        string Arr0[] = {"......."
                         ,"..ooo.."
                         ,"ooooooo"
                         ,".oo.oo."
                         ,"oo...oo"}
        ; 
        vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
        int Arg1 = 12; 
        int Arg2 = 4; 
        verify_case(3, Arg2, getMinimum(Arg0, Arg1)); }
    void test_case_4() { 
        string Arr0[] = {"................."
                         ,".ooooooo...oooo.."
                         ,".ooooooo..oooooo."
                         ,".oo.......oo..oo."
                         ,".oo.......oo..oo."
                         ,".ooooo.....oooo.."
                         ,".ooooooo...oooo.."
                         ,".....ooo..oo..oo."
                         ,"......oo..oo..oo."
                         ,".ooooooo..oooooo."
                         ,".oooooo....oooo.."
                         ,"................."}
        ; 
        vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
        int Arg1 = 58; 
        int Arg2 = 6; 
        verify_case(4, Arg2, getMinimum(Arg0, Arg1)); }
    void test_case_5() { 
        string Arr0[] = {".o.."
                         ,"oooo"
                         ,"..o."}
        ; 
        vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
        int Arg1 = 3; 
        int Arg2 = 2; 
        verify_case(5, Arg2, getMinimum(Arg0, Arg1)); }
    void test_case_6() { 
        string Arr0[] = {".o.."
                         ,"oooo"
                         ,"..o."}
        ; 
        vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
        int Arg1 = 3; 
        int Arg2 = 2; 
        verify_case(6, Arg2, getMinimum(Arg0, Arg1)); }

    // END CUT HERE

};
// BEGIN CUT HERE
int main() {
    DropCoins ___test;
    ___test.run_test(-1);
}
// END CUT HERE 
