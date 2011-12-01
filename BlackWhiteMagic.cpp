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
class BlackWhiteMagic {
public:
    int count(string creatures) {
        int ret = 0;
        int W = 0;
        int i;

        for (i=0; i<creatures.size(); i++)
            if (creatures[i] == 'W')
                W++;
        for (i=0; i<W; i++)
            if (creatures[i] == 'B')
                ret++;

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
        string Arg0 = "WBBW"; 
        int Arg1 = 1; 
        verify_case(0, Arg1, count(Arg0)); }
    void test_case_1() { 
        string Arg0 = "WWWWBBBB"; 
        int Arg1 = 0; 
        verify_case(1, Arg1, count(Arg0)); }
    void test_case_2() { 
        string Arg0 = "BBWW"; 
        int Arg1 = 2; 
        verify_case(2, Arg1, count(Arg0)); }
    void test_case_3() { 
        string Arg0 = "BWWWWWWWBBBBBBBW"; 
        int Arg1 = 1; 
        verify_case(3, Arg1, count(Arg0)); }
    void test_case_4() { 
        string Arg0 = "WBWBWBWBWWBWBWBWBBBWBW"; 
        int Arg1 = 5; 
        verify_case(4, Arg1, count(Arg0)); }
    void test_case_5() { 
        string Arg0 = "WBBW"; 
        int Arg1 = 1; 
        verify_case(5, Arg1, count(Arg0)); }
    void test_case_6() { 
        string Arg0 = "WBBW"; 
        int Arg1 = 1; 
        verify_case(6, Arg1, count(Arg0)); }

    // END CUT HERE

};
// BEGIN CUT HERE
int main() {
    BlackWhiteMagic ___test;
    ___test.run_test(-1);
}
// END CUT HERE 
