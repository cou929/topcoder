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
class SimpleCalculator {
public:
  int toInt(string s) {int r = 0; istringstream ss(s); ss >> r; return r;}

  vector <int> split(const string _s, const string del)
  {
    vector <int> ret;
    string s = _s;

    while (!s.empty())
      {
	size_t pos = s.find(del);
	string sub = "";
	sub = s.substr(0, pos);
	ret.push_back(toInt(sub));
	if (pos != string::npos)
	  pos += del.size();
	s.erase(0, pos);
      }

    return ret;
  }

  int calculate(string input)
  {
    int ret = 0;
    string del;

    for (int i=0; i<input.size(); i++)
      if (input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/')
	del = input[i];

    vector <int> tmp = split(input, del);

    if (del == "+")
      ret = tmp[0] + tmp[1];
    else if (del == "-")
      ret = tmp[0] - tmp[1];
    else if (del == "*")
      ret = tmp[0] * tmp[1];
    else if (del == "/")
      ret = tmp[0] / tmp[1];

    return ret;
  }
   
  // BEGIN CUT HERE
public:
  void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
private:
  template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
  void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
  void test_case_0() { string Arg0 = "5/3"; int Arg1 = 1; verify_case(0, Arg1, calculate(Arg0)); }
  void test_case_1() { string Arg0 = "15*3"; int Arg1 = 45; verify_case(1, Arg1, calculate(Arg0)); }
  void test_case_2() { string Arg0 = "1-10000"; int Arg1 = -9999; verify_case(2, Arg1, calculate(Arg0)); }
  void test_case_3() { string Arg0 = "17+18"; int Arg1 = 35; verify_case(3, Arg1, calculate(Arg0)); }
  void test_case_4() { string Arg0 = "0000000000000018/00000000000000000009"; int Arg1 = 2; verify_case(4, Arg1, calculate(Arg0)); }

  // END CUT HERE

};
// BEGIN CUT HERE
int main() {
SimpleCalculator ___test;
___test.run_test(-1);
}
// END CUT HERE 
