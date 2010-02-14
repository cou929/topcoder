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
class RelativePath {
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

  string makeRelative(string path, string currentDir) {
    string ret;

    vector <string> p = split(path, "/");
    vector <string> c = split(currentDir, "/");

    int i = 0, n = min(p.size(), c.size());
    for (i=0; i<n; i++)
      if (p[i] != c[i]) break;

    for (int j=0; j<c.size() - i; j++)
      ret += "../";
    for (int j=i; j<p.size(); j++)
      ret += p[j] + "/";

    ret.erase(ret.end()-1);

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
    if ((Case == -1) || (Case == 6)) test_case_6();
  }
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { 
    string Arg0 = "/home/top/data/file"; 
    string Arg1 = "/home/user/pictures"; 
    string Arg2 = "../../top/data/file"; 
    verify_case(0, Arg2, makeRelative(Arg0, Arg1)); }
	void test_case_1() { 
    string Arg0 = "/home/user/movies/title"; 
    string Arg1 = "/home/user/pictures"; 
    string Arg2 = "../movies/title"; 
    verify_case(1, Arg2, makeRelative(Arg0, Arg1)); }
	void test_case_2() { 
    string Arg0 = "/file"; 
    string Arg1 = "/"; 
    string Arg2 = "file"; 
    verify_case(2, Arg2, makeRelative(Arg0, Arg1)); }
	void test_case_3() { 
    string Arg0 = "/a/b/a/b/a/b"; 
    string Arg1 = "/a/b/a/a/b/a/b"; 
    string Arg2 = "../../../../b/a/b"; 
    verify_case(3, Arg2, makeRelative(Arg0, Arg1)); }
	void test_case_4() { 
    string Arg0 = "/root/root/root"; 
    string Arg1 = "/root"; 
    string Arg2 = "root/root"; 
    verify_case(4, Arg2, makeRelative(Arg0, Arg1)); }
	void test_case_5() { 
    string Arg0 = "/home/top/data/file"; 
    string Arg1 = "/home/user/pictures"; 
    string Arg2 = "../../top/data/file"; 
    verify_case(5, Arg2, makeRelative(Arg0, Arg1)); }
	void test_case_6() { 
    string Arg0 = "/home/top/data/file"; 
    string Arg1 = "/home/user/pictures"; 
    string Arg2 = "../../top/data/file"; 
    verify_case(6, Arg2, makeRelative(Arg0, Arg1)); }

  // END CUT HERE

};
// BEGIN CUT HERE
int main() {
RelativePath ___test;
___test.run_test(-1);
}
// END CUT HERE 
