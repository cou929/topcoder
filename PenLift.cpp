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
class PenLift {
public:
  int numTimes(vector <string> segments, int n) {
    int ret = 0;

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
    string Arr0[] = {"-10 0 10 0","0 -10 0 10"}; 
    vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
    int Arg1 = 1; 
    int Arg2 = 1; 
    verify_case(0, Arg2, numTimes(Arg0, Arg1)); }
	void test_case_1() { 
    string Arr0[] = {"-10 0 0 0","0 0 10 0","0 -10 0 0","0 0 0 10"}; 
    vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
    int Arg1 = 1; 
    int Arg2 = 1; 
    verify_case(1, Arg2, numTimes(Arg0, Arg1)); }
	void test_case_2() { 
    string Arr0[] = {"-10 0 0 0","0 0 10 0","0 -10 0 0","0 0 0 10"}; 
    vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
    int Arg1 = 4; 
    int Arg2 = 0; 
    verify_case(2, Arg2, numTimes(Arg0, Arg1)); }
	void test_case_3() { 
    string Arr0[] = {"0 0 1 0",   "2 0 4 0",   "5 0 8 0",   "9 0 13 0",
                     "0 1 1 1",   "2 1 4 1",   "5 1 8 1",   "9 1 13 1",
                     "0 0 0 1",   "1 0 1 1",   "2 0 2 1",   "3 0 3 1",
                     "4 0 4 1",   "5 0 5 1",   "6 0 6 1",   "7 0 7 1",
                     "8 0 8 1",   "9 0 9 1",   "10 0 10 1", "11 0 11 1",
                     "12 0 12 1", "13 0 13 1"}; 
    vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
    int Arg1 = 1; 
    int Arg2 = 6; 
    verify_case(3, Arg2, numTimes(Arg0, Arg1)); }
	void test_case_4() { 
    string Arr0[] = {"-2 6 -2 1",  "2 6 2 1",  "6 -2 1 -2",  "6 2 1 2",
                     "-2 5 -2 -1", "2 5 2 -1", "5 -2 -1 -2", "5 2 -1 2",
                     "-2 1 -2 -5", "2 1 2 -5", "1 -2 -5 -2", "1 2 -5 2",
                     "-2 -1 -2 -6","2 -1 2 -6","-1 -2 -6 -2","-1 2 -6 2"}; 
    vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
    int Arg1 = 5; 
    int Arg2 = 3; 
    verify_case(4, Arg2, numTimes(Arg0, Arg1)); }
	void test_case_5() { 
    string Arr0[] = {"-252927 -1000000 -252927 549481","628981 580961 -971965 580961",
                     "159038 -171934 159038 -420875","159038 923907 159038 418077",
                     "1000000 1000000 -909294 1000000","1000000 -420875 1000000 66849",
                     "1000000 -171934 628981 -171934","411096 66849 411096 -420875",
                     "-1000000 -420875 -396104 -420875","1000000 1000000 159038 1000000",
                     "411096 66849 411096 521448","-971965 580961 -909294 580961",
                     "159038 66849 159038 -1000000","-971965 1000000 725240 1000000",
                     "-396104 -420875 -396104 -171934","-909294 521448 628981 521448",
                     "-909294 1000000 -909294 -1000000","628981 1000000 -909294 1000000",
                     "628981 418077 -396104 418077","-971965 -420875 159038 -420875",
                     "1000000 -1000000 -396104 -1000000","-971965 66849 159038 66849",
                     "-909294 418077 1000000 418077","-909294 418077 411096 418077",
                     "725240 521448 725240 418077","-252927 -1000000 -1000000 -1000000",
                     "411096 549481 -1000000 549481","628981 -171934 628981 923907",
                     "-1000000 66849 -1000000 521448","-396104 66849 -396104 1000000",
                     "628981 -1000000 628981 521448","-971965 521448 -396104 521448",
                     "-1000000 418077 1000000 418077","-1000000 521448 -252927 521448",
                     "725240 -420875 725240 -1000000","-1000000 549481 -1000000 -420875",
                     "159038 521448 -396104 521448","-1000000 521448 -252927 521448",
                     "628981 580961 628981 549481","628981 -1000000 628981 521448",
                     "1000000 66849 1000000 -171934","-396104 66849 159038 66849",
                     "1000000 66849 -396104 66849","628981 1000000 628981 521448",
                     "-252927 923907 -252927 580961","1000000 549481 -971965 549481",
                     "-909294 66849 628981 66849","-252927 418077 628981 418077",
                     "159038 -171934 -909294 -171934","-252927 549481 159038 549481"}; 
    vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
    int Arg1 = 824759; 
    int Arg2 = 19; 
    verify_case(5, Arg2, numTimes(Arg0, Arg1)); }
	void test_case_6() { 
    string Arr0[] = {"-10 0 10 0","0 -10 0 10"}; 
    vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
    int Arg1 = 1; 
    int Arg2 = 1; 
    verify_case(6, Arg2, numTimes(Arg0, Arg1)); }
	void test_case_7() { 
    string Arr0[] = {"-10 0 10 0","0 -10 0 10"}; 
    vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
    int Arg1 = 1; 
    int Arg2 = 1; 
    verify_case(7, Arg2, numTimes(Arg0, Arg1)); }

  // END CUT HERE

};
// BEGIN CUT HERE
int main() {
PenLift ___test;
___test.run_test(-1);
}
// END CUT HERE 
