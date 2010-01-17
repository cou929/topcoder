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
class MaxTriangle {
public:
  double calcArea(int x1, int y1, int x2, int y2) {
    return abs(((double)x1*(double)y2 - (double)x2*(double)y1)/2.0);
  }

  double calculateArea(int A, int B) {
    double ret = 0;
    int lim = max(A, B);
    vector <pair <int, int> > canA, canB;
    int tmp = 0, remA = 0, remB = 0;

    for (int i=0; i<44722 && i*i<=lim; i++) {
      tmp = i*i;
      remA = A - tmp, remB = B - tmp;
      if (remA >= 0 && sqrt(remA) == (int)sqrt(remA)) {
        canA.push_back(make_pair(i, (int)sqrt(remA)));
        canA.push_back(make_pair(-i, (int)sqrt(remA)));
        canA.push_back(make_pair(i, -(int)sqrt(remA)));
        canA.push_back(make_pair(-i, -(int)sqrt(remA)));
      }
      if (remB >= 0 && sqrt(remB) == (int)sqrt(remB)) {
        canB.push_back(make_pair(i, (int)sqrt(remB)));
        canB.push_back(make_pair(-i, (int)sqrt(remB)));
        canB.push_back(make_pair(i, -(int)sqrt(remB)));
        canB.push_back(make_pair(-i, -(int)sqrt(remB)));
      }
    }

    if (canA.size() == 0 || canB.size() == 0)
      return -1;

    for (int i=0; i<canA.size(); i++)
      for (int j=0; j<canB.size(); j++)
        ret = max(ret, calcArea(canA[i].first, canA[i].second, canB[j].first, canB[j].second));

    return ret;
  }
   
  // BEGIN CUT HERE
public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 1; double Arg2 = 0.5; verify_case(0, Arg2, calculateArea(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 1988995850; int Arg1 = 1987587738; double Arg2 = 9.92895591E8; verify_case(1, Arg2, calculateArea(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 41; int Arg1 = 85; double Arg2 = 29.5; verify_case(2, Arg2, calculateArea(Arg0, Arg1)); }
  //1988995850, 1987587738

  // END CUT HERE

};
// BEGIN CUT HERE
int main() {
MaxTriangle ___test;
___test.run_test(-1);
}
// END CUT HERE 
