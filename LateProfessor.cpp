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
class LateProfessor {
public:
  double getProbability(int waitTime, int walkTime, int lateTime, int bestArrival, int worstArrival) {
    int i = 0;
    int amountWalk = 0;

    if (walkTime <= lateTime)
      return 0.0;
    
    while (1) {
      int left = waitTime*(i+1) + walkTime*i;
      int right = left + walkTime;
      i++;

      //      cout << left << ", " << right << endl;

      if (left > worstArrival)
        break;

      if (left <= bestArrival && bestArrival <= right && right <= worstArrival) {
        int t = (right - lateTime) - bestArrival;
        if (t > 0)
          amountWalk += t;
      } else if (bestArrival <= left && right <= worstArrival) {
        //        cout << right << " " << lateTime << " " << left << endl;
        amountWalk = (right - lateTime) - left;
        //        cout << amountWalk << endl;
      } else if (bestArrival <= left && left <= worstArrival && worstArrival <= right) {
        int t = (worstArrival - lateTime) - left;
        if (t > 0)
          amountWalk += t;
      }

      //      cout << amountWalk << endl;
    }

    return (double)amountWalk / (double)(worstArrival - bestArrival);
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
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { 
    int Arg0 = 20; 
    int Arg1 = 30; 
    int Arg2 = 10; 
    int Arg3 = 0; 
    int Arg4 = 50; 
    double Arg5 = 0.4; 
    verify_case(0, Arg5, getProbability(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_1() { 
    int Arg0 = 20; 
    int Arg1 = 30; 
    int Arg2 = 10; 
    int Arg3 = 30; 
    int Arg4 = 100; 
    double Arg5 = 0.42857142857142855; 
    verify_case(1, Arg5, getProbability(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_2() { 
    int Arg0 = 20; 
    int Arg1 = 40; 
    int Arg2 = 50; 
    int Arg3 = 0; 
    int Arg4 = 300; 
    double Arg5 = 0.0; 
    verify_case(2, Arg5, getProbability(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_3() { 
    int Arg0 = 101; 
    int Arg1 = 230; 
    int Arg2 = 10; 
    int Arg3 = 654; 
    int Arg4 = 17890; 
    double Arg5 = 0.6637270828498492; 
    verify_case(3, Arg5, getProbability(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_4() { 
    int Arg0 = 20; 
    int Arg1 = 30; 
    int Arg2 = 10; 
    int Arg3 = 90; 
    int Arg4 = 90; 
    double Arg5 = 1.0; 
    verify_case(4, Arg5, getProbability(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_5() { 
    int Arg0 = 1000; 
    int Arg1 = 600; 
    int Arg2 = 1; 
    int Arg3 = 17000; 
    int Arg4 = 17000; 
    double Arg5 = 0.0; 
    verify_case(5, Arg5, getProbability(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_6() { 
    int Arg0 = 20; 
    int Arg1 = 30; 
    int Arg2 = 10; 
    int Arg3 = 0; 
    int Arg4 = 50; 
    double Arg5 = 0.4; 
    verify_case(6, Arg5, getProbability(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_7() { 
    int Arg0 = 20; 
    int Arg1 = 30; 
    int Arg2 = 10; 
    int Arg3 = 0; 
    int Arg4 = 50; 
    double Arg5 = 0.4; 
    verify_case(7, Arg5, getProbability(Arg0, Arg1, Arg2, Arg3, Arg4)); }

  // END CUT HERE

};
// BEGIN CUT HERE
int main() {
LateProfessor ___test;
 ___test.run_test(-1);
}
// END CUT HERE 
