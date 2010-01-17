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
class VowelEncryptor {
public:
  vector <string> encrypt(vector <string> text)
  {
    vector <string> ret;

    for (int i=0; i<text.size(); i++)
      {
	string s;

	for (int j=0; j<text[i].size(); j++)
	  if (text[i][j] != 'a' && text[i][j] != 'i' && text[i][j] != 'u' && text[i][j] != 'e' && text[i][j] != 'o')
	    s += text[i][j];

	if (s.empty())
	  s = text[i];

	ret.push_back(s);
      }

    return ret;
  }
   
  // BEGIN CUT HERE
public:
  void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
private:
  template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
  void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
  void test_case_0() { string Arr0[] = {"hello", "world"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"hll", "wrld" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, encrypt(Arg0)); }
  void test_case_1() { string Arr0[] = {"a", "b", "c"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"a", "b", "c" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, encrypt(Arg0)); }
  void test_case_2() { string Arr0[] = {"he", "who", "is", "greedy", "is", "disgraced"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"h", "wh", "s", "grdy", "s", "dsgrcd" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, encrypt(Arg0)); }

  // END CUT HERE

};
// BEGIN CUT HERE
int main() {
VowelEncryptor ___test;
___test.run_test(-1);
}
// END CUT HERE 
