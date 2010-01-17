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
class BridgeCrossing {
public:
  int ret;
  vector <int> times;

  bool isPassed(int person, vector <int> & passed)
  {
    for (int i=0; i<passed.size(); i++)
      if (person == passed[i])
	return true;
    return false;
  }

  int r(vector <int> passed, int score)
  {
    for (int i=0; i<times.size(); i++)
      for (int j=0; j<times.size(); j++)
	if (i != j && !isPassed(i, passed) && !isPassed(j, passed))
	  {
	    vector <int> tmp = passed;
	    tmp.push_back(i);
	    tmp.push_back(j);

	    if (tmp.size() == times.size())
	      {
		ret = min(ret, score + max(times[i], times[j]));
		return 0;
	      }

	    int mini = 1000;
	    int index = -1;
	    for (int k=0; k<tmp.size(); k++)
	      if (mini > times[tmp[k]])
		{
		  mini = times[tmp[k]];
		  index = k;
		}

	    tmp.erase(tmp.begin() + index);
	    r(tmp, score + max(times[i], times[j]) + mini);
	  }

    return 0;
  }

  int minTime(vector <int> t)
  {
    ret = 1000;
    times = t;
    vector <int> emp;

    if (times.size() == 1)
      return times[0];

    r(emp, 0);

    return ret;
  }
   
  // BEGIN CUT HERE
public:
  void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
private:
  template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
  void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
  void test_case_0() { int Arr0[] = { 1, 2, 5, 10 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 17; verify_case(0, Arg1, minTime(Arg0)); }
  void test_case_1() { int Arr0[] = { 1, 2, 3, 4, 5 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 16; verify_case(1, Arg1, minTime(Arg0)); }
  void test_case_2() { int Arr0[] = { 100 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 100; verify_case(2, Arg1, minTime(Arg0)); }
  void test_case_3() { int Arr0[] = { 1, 2, 3, 50, 99, 100 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 162; verify_case(3, Arg1, minTime(Arg0)); }

  // END CUT HERE

};
// BEGIN CUT HERE
int main() {
BridgeCrossing ___test;
___test.run_test(-1);
}
// END CUT HERE 
