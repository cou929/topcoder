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
class TeXLeX {
public:
  int rule1(string s)
  {
    int ret = 0;

    for (int i=0; i<s.size(); i++)
      {
	int dec = 0;
	if ('0' <= s[i] && s[i] <= '9')
	  dec = s[i] - '0';
	else
	  dec = s[i] - 'a' + 10;

	ret = ret * 16 + dec;
      }

    return ret;
  }

  int rule2(string s)
  {
    return s[0] - 64;
  }

  int rule3(string s)
  {
    return s[0] + 64;
  }

  vector <int> getTokens(string input)
  {
    vector <int> ret;

    int pos = 0;

    while (pos < input.size())
      {
	if (input[pos] != '^')
	  {
	    ret.push_back(input[pos] - '\0');
	    pos++;
	    continue;
	  }

	if (pos+1 < input.size() && input[pos+1] == '^')
	  {
	    if (pos+2 < input.size() && (('0' <= input[pos+2] && input[pos+2] <= '9') || ('a' <= input[pos+2] && input[pos+2] <= 'f')))
	      {
		if (pos+3 < input.size() && (('0' <= input[pos+3] && input[pos+3] <= '9') || ('a' <= input[pos+3] && input[pos+3] <= 'f')))
		  {
		    string s;
		    s = input[pos+2];
		    s += input[pos+3];
		  }
	      }
	  } 

	if (pos+1 >= input.size() || input[pos+1] != '^')
	  {
	    ret.push_back(input[pos] - '\0');
	    pos++;
	    continue;
	  }
      }

    return ret;
  }
   
  // BEGIN CUT HERE
public:
  void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
private:
  template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
  void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
  void test_case_0() { string Arg0 = "aAbB cd"; int Arr1[] = { 97,  65,  98,  66,  32,  99,  100 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, getTokens(Arg0)); }
  void test_case_1() { string Arg0 = "^^ ^^5e"; int Arr1[] = { 96,  94 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, getTokens(Arg0)); }
  void test_case_2() { string Arg0 = "^^"; int Arr1[] = { 94,  94 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, getTokens(Arg0)); }
  void test_case_3() { string Arg0 = "^^^5e5e"; int Arr1[] = { 30,  53,  101,  53,  101 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, getTokens(Arg0)); }
  void test_case_4() { string Arg0 = "^^5e^5e^5e^5e^ abASFs&*^@%#"; int Arr1[] = { 96,  97,  98,  65,  83,  70,  115,  38,  42,  94,  64,  37,  35 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(4, Arg1, getTokens(Arg0)); }
  void test_case_5() { string Arg0 = "^^5E ^^40"; int Arr1[] = { 117,  69,  32,  64 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(5, Arg1, getTokens(Arg0)); }
  void test_case_6() { string Arg0 = "^^`2^^^^OC^^c^^xJ^^Dq9GQpe^^)^^i_&_Q<^^@>|AL8^^d^^"; int Arr1[] = { 32,  50,  30,  94,  79,  67,  35,  56,  74,  4,  113,  57,  71,  81,  112,  101,  105,  41,  95,  38,  95,  81,  60,  0,  62,  124,  65,  76,  56,  36,  94,  94 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(6, Arg1, getTokens(Arg0)); }

  // END CUT HERE

};
// BEGIN CUT HERE
int main() {
TeXLeX ___test;
___test.run_test(-1);
}
// END CUT HERE 
