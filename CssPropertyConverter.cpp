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

class CssPropertyConverter {
public:
  vector <string> split(const string _s, const string del)
  {
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

  string getCamelized(string cssPropertyName)
  {
    string ret;
    vector <string> s = split(cssPropertyName, "-");
    for (int i=1; i<s.size(); i++)
      s[i][0] = s[i][0] - 'a' + 'A';
    for (int i=0; i<s.size(); i++)
      ret += s[i];
    return ret;
  }

   
  // BEGIN CUT HERE
public:
  void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
private:
  template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
  void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
  void test_case_0() { string Arg0 = "z-index"; string Arg1 = "zIndex"; verify_case(0, Arg1, getCamelized(Arg0)); }
  void test_case_1() { string Arg0 = "border-collapse"; string Arg1 = "borderCollapse"; verify_case(1, Arg1, getCamelized(Arg0)); }
  void test_case_2() { string Arg0 = "top-border-width"; string Arg1 = "topBorderWidth"; verify_case(2, Arg1, getCamelized(Arg0)); }

  // END CUT HERE

};

// BEGIN CUT HERE
int main() {
CssPropertyConverter ___test;
___test.run_test(-1);
}
// END CUT HERE 
