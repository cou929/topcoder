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
class RoadOrFlightHard {
public:
  long long minTime(int N, int roadFirst, int roadProd, int roadAdd, int roadMod, int flightFirst, int flightProd, int flightAdd, int flightMod, int K) {
    const long long INF = 1000000000000000000LL;
    long long ret = INF;
    vector <int> roadTimes, flightTimes;
    int i, j, k;
    long long dp[2][42][2];

    for (i=0; i<2; i++)
      for (j=0; j<42; j++)
        for (k=0; k<2; k++)
          dp[i][j][k] = INF;

    roadTimes.push_back(roadFirst % roadMod);
    flightTimes.push_back(flightFirst % flightMod);
    
    for (i=1; i<N; i++) {
      roadTimes.push_back(((long long)roadTimes[i-1] * roadProd + roadAdd) % roadMod);
      flightTimes.push_back(((long long)flightTimes[i-1] * flightProd + flightAdd) % flightMod);
    }

    dp[0][0][0] = 0;

    for (i=1; i<=N; i++) {
      for (j=0; j<=K; j++)
        dp[i%2][j][0] = dp[i%2][j][1] = INF;
      for (j=0; j<=K; j++) {
        // walk -> walk
        dp[i%2][j][0] = min(dp[i%2][j][0], dp[(i-1)%2][j][0] + roadTimes[i-1]);
        // flight -> walk
        dp[i%2][j][0] = min(dp[i%2][j][0], dp[(i-1)%2][j][1] + roadTimes[i-1]);
        // walk -> flight
        if (j < K)
          dp[i%2][j+1][1] = min(dp[i%2][j+1][1], dp[(i-1)%2][j][0] + flightTimes[i-1]);
        // flight -> flight
        dp[i%2][j][1] = min(dp[i%2][j][1], dp[(i-1)%2][j][1] + flightTimes[i-1]);
      }
    }

    for (i=0; i<=K; i++)
      ret = min(ret, min(dp[N%2][i][0], dp[N%2][i][1]));

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
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { 
    int Arg0 = 3; 
    int Arg1 = 14; 
    int Arg2 = 1; 
    int Arg3 = 2; 
    int Arg4 = 10; 
    int Arg5 = 18; 
    int Arg6 = 1; 
    int Arg7 = 10; 
    int Arg8 = 17; 
    int Arg9 = 1; 
    long long Arg10 = 14LL; 
    verify_case(0, Arg10, minTime(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Arg9)); }
	void test_case_1() { 
    int Arg0 = 3; 
    int Arg1 = 4; 
    int Arg2 = 1; 
    int Arg3 = 2; 
    int Arg4 = 10; 
    int Arg5 = 1; 
    int Arg6 = 1; 
    int Arg7 = 10; 
    int Arg8 = 17; 
    int Arg9 = 2; 
    long long Arg10 = 11LL; 
    verify_case(1, Arg10, minTime(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Arg9)); }
	void test_case_2() { 
    int Arg0 = 3; 
    int Arg1 = 4; 
    int Arg2 = 1; 
    int Arg3 = 2; 
    int Arg4 = 10; 
    int Arg5 = 1; 
    int Arg6 = 1; 
    int Arg7 = 6; 
    int Arg8 = 9; 
    int Arg9 = 1; 
    long long Arg10 = 12LL; 
    verify_case(2, Arg10, minTime(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Arg9)); }
	void test_case_3() { 
    int Arg0 = 5; 
    int Arg1 = 85739; 
    int Arg2 = 94847; 
    int Arg3 = 93893; 
    int Arg4 = 98392; 
    int Arg5 = 92840; 
    int Arg6 = 93802; 
    int Arg7 = 93830; 
    int Arg8 = 92790; 
    int Arg9 = 3; 
    long long Arg10 = 122365LL; 
    verify_case(3, Arg10, minTime(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Arg9)); }
	void test_case_4() { 
    int Arg0 = 331999; 
    int Arg1 = 65645; 
    int Arg2 = 48613; 
    int Arg3 = 81333; 
    int Arg4 = 82122; 
    int Arg5 = 2374; 
    int Arg6 = 18997; 
    int Arg7 = 3468; 
    int Arg8 = 97383; 
    int Arg9 = 10; 
    long long Arg10 = 13625973966LL; 
    verify_case(4, Arg10, minTime(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Arg9)); }
	void test_case_5() { 
    int Arg0 = 3; 
    int Arg1 = 14; 
    int Arg2 = 1; 
    int Arg3 = 2; 
    int Arg4 = 10; 
    int Arg5 = 18; 
    int Arg6 = 1; 
    int Arg7 = 10; 
    int Arg8 = 17; 
    int Arg9 = 1; 
    long long Arg10 = 14LL; 
    verify_case(5, Arg10, minTime(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Arg9)); }

  // END CUT HERE

};
// BEGIN CUT HERE
int main() {
RoadOrFlightHard ___test;
___test.run_test(-1);
}
// END CUT HERE 
