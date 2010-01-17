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
class DownloadingFiles {
public:
  double actualTime(vector <string> tasks) {
    double ret = 0;
    vector <pair <double, double> > t;

    for (int i=0; i<tasks.size(); i++) {
      int speed = 0, time = 0;
      sscanf(tasks[i].c_str(), "%d %d", &speed, &time);
      t.push_back(make_pair(time, speed));
    }

    for (int i=0; i<t.size(); i++) {
      double free = 0;
      double minus = 0;
      double time = 100000;
      int pos = 0, pos2 = 0;
      
      for (int j=0; j<t.size(); j++)
        if (t[j].first > 0 && t[j].first < time) {
          time = t[j].first;
          pos = j;
        }

      ret += t[pos].first;
      minus = t[pos].first;

      for (int j=0; j<t.size(); j++) {
        t[j].first -= minus;
        if (t[j].first <= 0) {
          free += t[j].second;
          t[j].second = 0;
        }
        if (t[j].first > 0)
          pos2 = j;
      }

      t[pos2].first = t[pos2].first * t[pos2].second / (t[pos2].second + free);
      t[pos2].second = t[pos2].second + free;
    }

    return ret;
  }
   
  // BEGIN CUT HERE
public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"3 57","2 22"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 43.0; verify_case(0, Arg1, actualTime(Arg0)); }
	void test_case_1() { string Arr0[] = {"3 1057","2 1022"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 1043.0; verify_case(1, Arg1, actualTime(Arg0)); }
	void test_case_2() { string Arr0[] = {"25 1000","5 5000","10 5000"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 2500.0; verify_case(2, Arg1, actualTime(Arg0)); }
	void test_case_3() { string Arr0[] = {"1 10","1 20","2 40"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 27.5; verify_case(3, Arg1, actualTime(Arg0)); }
	void test_case_4() { string Arr0[] = {"6 88","39 7057","63 2502","45 2285","28 8749","62 3636","1 5546","49 5741"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 4414.542662116041; verify_case(4, Arg1, actualTime(Arg0)); }

  // END CUT HERE

};
// BEGIN CUT HERE
int main() {
DownloadingFiles ___test;
___test.run_test(-1);
}
// END CUT HERE 
