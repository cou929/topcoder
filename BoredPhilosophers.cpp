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
class BoredPhilosophers {
public:
  vector <string> splits(const string _s, const string del)
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

  vector <int> simulate(vector <string> text, int N)
  {
    vector <int> ret;
    string completeText = "";
    for (int i=0; i<text.size(); i++)
      completeText += text[i];

    vector <string> words = splits(completeText, " ");

    for (int i=1; i<=N; i++)
      {
	map <string, int> m;

	for (int j=0; j<words.size()-i+1; j++)
	  {
	    string s = "";

	    for (int k=0; k<i; k++)
	      {
		s += words[j+k];
		s += " ";
	      }

	    s.erase(s.end()-1);

	    m[s]++;
	  }

	ret.push_back(m.size());
      }

    return ret;
  }
   
  // BEGIN CUT HERE
public:
  void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
private:
  template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
  void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
  void test_case_0() { string Arr0[] = {"aa aaa a aaaa"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; int Arr2[] = {2, 1 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, simulate(Arg0, Arg1)); }
  void test_case_1() { string Arr0[] = {"aaa bbb aaa bbb aaa aaa"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; int Arr2[] = {2, 3, 3, 3 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, simulate(Arg0, Arg1)); }
  void test_case_2() { string Arr0[] = {"remember"," t","o concatenate ","the"," ","text"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arr2[] = {5 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(2, Arg2, simulate(Arg0, Arg1)); }
  void test_case_3() { string Arr0[] = {"a a a a a a a b a a b a a a b b a b a a a b a b"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; int Arr2[] = {2, 4, 7, 11, 14, 17 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(3, Arg2, simulate(Arg0, Arg1)); }
  void test_case_4() { string Arr0[] = {"aa ababaa c cbbcbc cabcbcb ba bccc ababb",
					"c cabcba caa ababaa c cbbcbc cabcbcb ba ",
					"bccc ababbc cabcba c bbcbab",
					"b aaaa cbccaaa bccc ababbc cabcba c bbcb",
					"ab cbcaca"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 7; int Arr2[] = {15, 17, 18, 19, 20, 20, 20 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(4, Arg2, simulate(Arg0, Arg1)); }
  void test_case_5() { string Arr0[] = {"a a a a a a a b a a b a a a b b a b a a a b a b a ", "a a a a a a a b a a b a a a b b a b a a a b a b a ", "a a a a a a a b a a b a a a b b a b a a a b a b a ", "a a a a a a a b a a b a a a b b a b a a a b a b a ", "a a a a a a a b a a b a a a b b a b a a a b a b a ", "a a a a a a a b a a b a a a b b a b a a a b a b a ", "a a a a a a a b a a b a a a b b a b a a a b a b a ", "a a a a a a a b a a b a a a b b a b a a a b a b a ", "a a a a a a a b a a b a a a b b a b a a a b a b a ", "a a a a a a a b a a b a a a b b a b a a a b a b a ", "a a a a a a a b a a b a a a b b a b a a a b a b a ", "a a a a a a a b a a b a a a b b a b a a a b a b a ", "a a a a a a a b a a b a a a b b a b a a a b a b a ", "a a a a a a a b a a b a a a b b a b a a a b a b a ", "a a a a a a a b a a b a a a b b a b a a a b a b a ", "a a a a a a a b a a b a a a b b a b a a a b a b a ", "a a a a a a a b a a b a a a b b a b a a a b a b a ", "a a a a a a a b a a b a a a b b a b a a a b a b a ", "a a a a a a a b a a b a a a b b a b a a a b a b a ", "a a a a a a a b a a b a a a b b a b a a a b a b a ", "a a a a a a a b a a b a a a b b a b a a a b a b a ", "a a a a a a a b a a b a a a b b a b a a a b a b a ", "a a a a a a a b a a b a a a b b a b a a a b a b a ", "a a a a a a a b a a b a a a b b a b a a a b a b a ", "a a a a a a a b a a b a a a b b a b a a a b a b a ", "a a a a a a a b a a b a a a b b a b a a a b a b a ", "a a a a a a a b a a b a a a b b a b a a a b a b a ", "a a a a a a a b a a b a a a b b a b a a a b a b a ", "a a a a a a a b a a b a a a b b a b a a a b a b a ", "a a a a a a a b a a b a a a b b a b a a a b a b a ", "a a a a a a a b a a b a a a b b a b a a a b a b a ", "a a a a a a a b a a b a a a b b a b a a a b a b a ", "a a a a a a a b a a b a a a b b a b a a a b a b a ", "a a a a a a a b a a b a a a b b a b a a a b a b a ", "a a a a a a a b a a b a a a b b a b a a a b a b a ", "a a a a a a a b a a b a a a b b a b a a a b a b a ", "a a a a a a a b a a b a a a b b a b a a a b a b a ", "a a a a a a a b a a b a a a b b a b a a a b a b a ", "a a a a a a a b a a b a a a b b a b a a a b a b a ", "a a a a a a a b a a b a a a b b a b a a a b a b a ", "a a a a a a a b a a b a a a b b a b a a a b a b a ", "a a a a a a a b a a b a a a b b a b a a a b a b a ", "a a a a a a a b a a b a a a b b a b a a a b a b a ", "a a a a a a a b a a b a a a b b a b a a a b a b a ", "a a a a a a a b a a b a a a b b a b a a a b a b a ", "a a a a a a a b a a b a a a b b a b a a a b a b a ", "a a a a a a a b a a b a a a b b a b a a a b a b a ", "a a a a a a a b a a b a a a b b a b a a a b a b a ", "a a a a a a a b a a b a a a b b a b a a a b a b a ", "a a a a a a a b a a b a a a b b a b a a a b a b a "}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 50; int Arr2[] = {2, 4, 7, 11, 14, 17 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(3, Arg2, simulate(Arg0, Arg1)); }

  // END CUT HERE

};
// BEGIN CUT HERE
int main() {
BoredPhilosophers ___test;
___test.run_test(-1);
}
// END CUT HERE 
