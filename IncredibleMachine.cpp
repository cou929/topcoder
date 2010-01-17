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
class IncredibleMachine {
public:
  vector <vector <double> > planes;  // length, sin(alpha)
  double calcTimes(double g) {
    double ret = 0;
    double initial_velocity = 0;
    double acceleration = 0;
    double time = 0;

    for (int i=0; i<planes.size(); i++) {
      acceleration = g * planes[i][1];
      time = (-initial_velocity + sqrt(initial_velocity*initial_velocity + 2 * acceleration * planes[i][0])) / acceleration;
      initial_velocity = initial_velocity + acceleration * time;
      ret += time;
    }

    return ret;
  }

  double gravitationalAcceleration(vector <int> x, vector <int> y, int T) {
    double ret = 0;
    double left = 0, right = 1e20, mid = 0;
    planes.clear();
    
    for (int i=0; i<x.size()-1; i++) {
      vector <double> tmp(2, 0);
      tmp[0] = sqrt((x[i] - x[i+1]) * (x[i] - x[i+1]) + (y[i] - y[i+1]) * (y[i] - y[i+1]));
      tmp[1] = abs(y[i] - y[i+1]) / tmp[0];
      planes.push_back(tmp);
    }

    for (int i=0; i<1000; i++) {
      mid = (left + right) / 2;
      double t = calcTimes(mid);
      if (t < T)
        right = mid;
      else
        left = mid;
    }

    ret = mid;
    return ret;
  }
   
  // BEGIN CUT HERE
public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0,6}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {100,22}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 4; double Arg3 = 9.807692307692307; verify_case(0, Arg3, gravitationalAcceleration(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {0,26,100}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {50,26,24}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 4; double Arg3 = 26.743031720603582; verify_case(1, Arg3, gravitationalAcceleration(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {0,7,8}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {10,6,0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 7; double Arg3 = 1.1076837407708007; verify_case(2, Arg3, gravitationalAcceleration(Arg0, Arg1, Arg2)); }

  // END CUT HERE

};
// BEGIN CUT HERE
int main() {
IncredibleMachine ___test;
___test.run_test(-1);
}
// END CUT HERE 
