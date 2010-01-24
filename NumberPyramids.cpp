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
class NumberPyramids {
public:
  long long combination(int n, int r)
  {
    int i, j;
    long long result[r+1], tmp[r+1];

    for (i=0; i<=r; i++) {
      result[i] = 0;
      tmp[i] = 0;
    }

    result[0] = 1;

    for (i=1; i<=n; i++) {
      tmp[0] = 1;

      for (j=1; j<=r; j++)
        tmp[j] = result[j-1] + result[j];

      for (j=0; j<=r; j++)
        result[j] = tmp[j];
    }

    return result[r];
  }

  int count(int baseLength, int top) {
    if (baseLength > 20) return 0;
    if ((1 << (baseLength-1)) > top) return 0;

    int ret = 0;
    int prime = 1000000009;
    int binoms[20];
    int dp[top+1];
    int copy[top+1];

    for (int i=0; i<=top; i++) dp[i] = 1;
    dp[0] = 0;

    for (int i=0; i<baseLength; i++)
      binoms[i] = combination(baseLength-1, i);

    for (int i=0; i<baseLength-1; i++) {
      memset(copy, 0, sizeof(copy));

      int num = binoms[i];
      for (int k=num; k<=top; k++)
        copy[k] = (dp[k - num] + copy[k - num])% prime;

      for (int j=0; j<=top; j++)
        dp[j] = copy[j];

      cout << num << endl;
      for (int j=0; j<=top; j++)
        cout << dp[j] << " ";
      cout << endl;
    }

    ret = dp[top];
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
  }
private:
  template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
  void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
  void test_case_0() { 
    int Arg0 = 3; 
    int Arg1 = 5; 
    int Arg2 = 2; 
    verify_case(0, Arg2, count(Arg0, Arg1)); }
  void test_case_1() { 
    int Arg0 = 5;
    int Arg1 = 16;
    int Arg2 = 1;
    verify_case(1, Arg2, count(Arg0, Arg1)); }
  void test_case_2() { 
    int Arg0 = 4; 
    int Arg1 = 15; 
    int Arg2 = 24; 
    verify_case(2, Arg2, count(Arg0, Arg1)); }
  void test_case_3() { 
    int Arg0 = 15; 
    int Arg1 = 31556; 
    int Arg2 = 74280915; 
    verify_case(3, Arg2, count(Arg0, Arg1)); }
  void test_case_4() { 
    int Arg0 = 150; 
    int Arg1 = 500; 
    int Arg2 = 0; 
    verify_case(4, Arg2, count(Arg0, Arg1)); }
  void test_case_5() { 
    int Arg0 = 2;
    int Arg1 = 1000000;
    int Arg2 = 999999;
    verify_case(5, Arg2, count(Arg0, Arg1)); }

  // END CUT HERE

};
// BEGIN CUT HERE
int main() {
  NumberPyramids ___test;
  ___test.run_test(1);
}
// END CUT HERE 
