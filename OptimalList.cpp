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

using namespace std;

class OptimalList {
public:
  string optimize(string inst)
  {
    pair <int, int> cur(0, 0);
    string ret = "";

    for (int i=0; i<inst.size(); i++)
      {
	if (inst[i] == 'N')
	  cur.second++;
	else if (inst[i] == 'S')
	  cur.second--;
	else if (inst[i] == 'E')
	  cur.first++;
	else if (inst[i] == 'W')
	  cur.first--;
      }

    if (cur.first > 0)
      for (int i=0; i<cur.first; i++)
	ret += 'E';
    else if (cur.first < 0)
      for (int i=0; i<abs(cur.first); i++)
	ret += 'W';

    if (cur.second > 0)
      for (int i=0; i<cur.second; i++)
	ret += 'N';
    else if (cur.second < 0)
      for (int i=0; i<abs(cur.second); i++)
	ret += 'S';

    sort(ret.begin(), ret.end());

    return ret;
  }

   
  // BEGIN CUT HERE
public:
  void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
private:
  template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
  void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
  void test_case_0() { string Arg0 = "NENENNWWWWWS"; string Arg1 = "NNNWWW"; verify_case(0, Arg1, optimize(Arg0)); }
  void test_case_1() { string Arg0 = "NNEESSWW"; string Arg1 = ""; verify_case(1, Arg1, optimize(Arg0)); }
  void test_case_2() { string Arg0 = "NEWSNWESWESSEWSENSEWSEWESEWWEWEEWESSSWWWWWW"; string Arg1 = "SSSSSSSSWWW"; verify_case(2, Arg1, optimize(Arg0)); }
  void test_case_3() { string Arg0 = "NENENE"; string Arg1 = "EEENNN"; verify_case(3, Arg1, optimize(Arg0)); }

  // END CUT HERE

};

// BEGIN CUT HERE
int main() {
OptimalList ___test;
___test.run_test(-1);
}
// END CUT HERE 
