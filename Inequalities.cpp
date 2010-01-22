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
class Inequalities {
public:
  vector <string> split(const string _s, const string del) {
    vector <string> ret;
    string s = _s;

    while (!s.empty())
      {
        size_t pos = s.find(del);
        string sub = "";
        sub = s.substr(0, pos);
        ret.push_back(sub);
        if (pos != string::npos)
          pos += del.size();
        s.erase(0, pos);
      }

    return ret;
  }

  int toInt(string s) {int r = 0; istringstream ss(s); ss >> r; return r;}

  int maximumSubset(vector <string> inequalities) {
    int ret = 0;

    for (double i=-1; i<=1001; i+=0.5) {
      int satisfy = 0;
      for (int j=0; j<inequalities.size(); j++) {
        vector <string> res = split(inequalities[j], " ");
        double num = (double)toInt(res[2]);
        if (res[1] == "=") {
          if (i != num) continue;
        } else if (res[1] == "<") {
          if (i >= num) continue;
        } else if (res[1] == "<=") {
          if (i > num) continue;
        } else if (res[1] == ">") {
          if (i <= num) continue;
        } else if (res[1] == ">=") {
          if (i < num) continue;
        }
        satisfy++;
      }
      ret = max(ret, satisfy);
    }

    return ret;
  }
   
  // BEGIN CUT HERE
public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"X <= 12","X = 13","X > 9","X < 10","X >= 14"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(0, Arg1, maximumSubset(Arg0)); }
	void test_case_1() { string Arr0[] = {"X < 0","X <= 0"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(1, Arg1, maximumSubset(Arg0)); }
	void test_case_2() { string Arr0[] = {"X = 1","X = 2","X = 3","X > 0"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(2, Arg1, maximumSubset(Arg0)); }
	void test_case_3() { string Arr0[] = {"X <= 521","X >= 521","X = 521","X > 902","X > 12","X <= 1000"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; verify_case(3, Arg1, maximumSubset(Arg0)); }

  // END CUT HERE

};
// BEGIN CUT HERE
int main() {
Inequalities ___test;
___test.run_test(-1);
}
// END CUT HERE 
