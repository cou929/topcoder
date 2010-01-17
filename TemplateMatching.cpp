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

using namespace std;

class TemplateMatching {
public:
  string bestMatch(string text, string prefix, string suffix)
  {
    int i, j, k, max = 0;
    vector <int> pre;

    prefix = "";

    for (i=0; i<text.size(); i++)
      {
	int N = prefix.size()-1;
	if (text[i] == prefix[N])
	  {
	    for (j=i-1, k=1; j>=0 && k < prefix.size(); j--, k++)
	      {
		if (text[j] != prefix[N-k])
		  break;
	      }

	    if (max < k)
	      {
		pre.clear();
		pre.push_back(k);
	      }
	    else if (max == k)
	      pre.push_back(k);
	  }


      }
  }

   
  // BEGIN CUT HERE
public:
  void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
private:
  template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
  void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
  void test_case_0() { string Arg0 = "something"; string Arg1 = "awesome"; string Arg2 = "ingenious"; string Arg3 = "something"; verify_case(0, Arg3, bestMatch(Arg0, Arg1, Arg2)); }
  void test_case_1() { string Arg0 = "havka"; string Arg1 = "eto"; string Arg2 = "papstvo"; string Arg3 = "a"; verify_case(1, Arg3, bestMatch(Arg0, Arg1, Arg2)); }
  void test_case_2() { string Arg0 = "abracadabra"; string Arg1 = "habrahabr"; string Arg2 = "bracket"; string Arg3 = "abrac"; verify_case(2, Arg3, bestMatch(Arg0, Arg1, Arg2)); }
  void test_case_3() { string Arg0 = "mississippi"; string Arg1 = "promise"; string Arg2 = "piccolo"; string Arg3 = "ippi"; verify_case(3, Arg3, bestMatch(Arg0, Arg1, Arg2)); }
  void test_case_4() { string Arg0 = "a a a a a a"; string Arg1 = "a a"; string Arg2 = "a"; string Arg3 = "a a"; verify_case(4, Arg3, bestMatch(Arg0, Arg1, Arg2)); }
  void test_case_5() { string Arg0 = "ab"; string Arg1 = "b"; string Arg2 = "a"; string Arg3 = "b"; verify_case(5, Arg3, bestMatch(Arg0, Arg1, Arg2)); }

  // END CUT HERE

};

// BEGIN CUT HERE
int main() {
TemplateMatching ___test;
___test.run_test(-1);
}
// END CUT HERE 
