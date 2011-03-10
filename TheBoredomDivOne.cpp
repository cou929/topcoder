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
class TheBoredomDivOne {
public:
  double mem[110][110];
  bool vis[110][110];
  double find(int n, int m) {
//     int total = n + m;
//     double F[total + 2];
//     int i, j, k;
//     memset(F, 0, sizeof(F));
    
//     for (i=total-1; i>=n; i--) {
//       double counter = 0, t0 = 0, t1 = 0, t2 = 0;
//       for (j=1; j<=total; j++) {
//         for (k=j+1; k<=total; k++) {
//           counter++;
//           if (j>i && k>i)
//             t2++;
//           else if (j>i || k>i)
//             t1++;
//           else
//             t0++;
//         }
//       }
//       double p0 = t0 / counter, p1 = t1 / counter, p2 = t2 / counter;

//       F[i] = (1 + p1 * F[i+1] + p2 * F[i+2]) / (1 - p0);
//     }

//     return F[n];
    if (m <= 0) return 0.0;  // ?
    if (vis[n][m]) return mem[n][m];

    double total = (n + m) * (n + m - 1) / 2.0;
    double p1 = m * n / total;
    double p2 = m * (m - 1) / 2.0 / total;   // ?
    
    double ret = (p1 * find(n + 1, m - 1) + p2 * find(n + 2, m - 2) + 1) / (p1 + p2); // ?

    vis[n][m] = true;
    return mem[n][m] = ret;
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
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { 
    int Arg0 = 1; 
    int Arg1 = 1; 
    double Arg2 = 1.0; 
    verify_case(0, Arg2, find(Arg0, Arg1)); }
	void test_case_1() { 
    int Arg0 = 2; 
    int Arg1 = 1; 
    double Arg2 = 1.5; 
    verify_case(1, Arg2, find(Arg0, Arg1)); }
	void test_case_2() { 
    int Arg0 = 1; 
    int Arg1 = 2; 
    double Arg2 = 2.0; 
    verify_case(2, Arg2, find(Arg0, Arg1)); }
	void test_case_3() { 
    int Arg0 = 4; 
    int Arg1 = 7; 
    double Arg2 = 13.831068977298521; 
    verify_case(3, Arg2, find(Arg0, Arg1)); }
	void test_case_4() { 
    int Arg0 = 1; 
    int Arg1 = 1; 
    double Arg2 = 1.0; 
    verify_case(4, Arg2, find(Arg0, Arg1)); }
	void test_case_5() { 
    int Arg0 = 1; 
    int Arg1 = 1; 
    double Arg2 = 1.0; 
    verify_case(5, Arg2, find(Arg0, Arg1)); }

  // END CUT HERE

};
// BEGIN CUT HERE
int main() {
  TheBoredomDivOne ___test;
  ___test.run_test(-1);
}
// END CUT HERE 
