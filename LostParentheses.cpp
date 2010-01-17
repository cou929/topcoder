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

class LostParentheses {
public:
  int minResult(string e)
  {
    int ret = 0;
    vector <int> vals;
    vector <int> ops;

    e += 'E';

    while (!e.empty())
      {
	string s;
	int n;
	int pos;
	for (int i=0; i<e.size(); i++)
	  {
	    pos = i;
	    if (e[i] == '+')
	      {
		ops.push_back(1);
		break;
	      }
	    else if (e[i] == '-')
	      {
		ops.push_back(-1);
		break;
	      }
	    else if (e[i] == 'E')
	      {
		break;
	      }
	  }

	s = e.substr(0, pos);
	sscanf(s.c_str(), "%d", &n);
	vals.push_back(n);

	e.erase(0, pos+1);
      }

    bool appeared = false;
    ret = vals[0];
    for (int i=1; i<vals.size(); i++)
      {
	if (!appeared && ops[i-1] == -1)
	  appeared = true;

	if (appeared)
	  ret -= vals[i];
	else
	  ret += vals[i];
      }

    return ret;
  }

   
  // BEGIN CUT HERE
public:
  void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
private:
  template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
  void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
  void test_case_0() { string Arg0 = "55-50+40"; int Arg1 = -35; verify_case(0, Arg1, minResult(Arg0)); }
  void test_case_1() { string Arg0 = "10+20+30+40"; int Arg1 = 100; verify_case(1, Arg1, minResult(Arg0)); }
  void test_case_2() { string Arg0 = "00009-00009"; int Arg1 = 0; verify_case(2, Arg1, minResult(Arg0)); }

  // END CUT HERE

};

// BEGIN CUT HERE
int main() {
LostParentheses ___test;
___test.run_test(-1);
}
// END CUT HERE 
