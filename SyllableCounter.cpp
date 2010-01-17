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
class SyllableCounter {
public:
  bool isVowel(char c)
  {
   string vowel = "AIUEO";

   for (int i=0; i<vowel.size(); i++)
     if (vowel[i] == c)
       return true;

   return false;
  }

  int countSyllables(string word)
  {
    int ret = 0;
    bool inVowelGroup = false;

    for (int i=0; i<word.size(); i++)
      {
	if (isVowel(word[i]))
	  {
	    if (inVowelGroup)
	      continue;
	    else
	      {
		ret++;
		inVowelGroup = true;
	      }
	  }
	else
	  {
	    if (inVowelGroup)
	      inVowelGroup = false;
	  }
      }

    return ret;
  }
   
  // BEGIN CUT HERE
public:
  void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
private:
  template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
  void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
  void test_case_0() { string Arg0 = "VOLUME"; int Arg1 = 3; verify_case(0, Arg1, countSyllables(Arg0)); }
  void test_case_1() { string Arg0 = "TELEVISION"; int Arg1 = 4; verify_case(1, Arg1, countSyllables(Arg0)); }
  void test_case_2() { string Arg0 = "BOOKKEEEEEEEEEEEEPER"; int Arg1 = 3; verify_case(2, Arg1, countSyllables(Arg0)); }
  void test_case_3() { string Arg0 = "SLKJSGLKAKHDGHELHDGILKLHDGOLOOOOOL"; int Arg1 = 5; verify_case(3, Arg1, countSyllables(Arg0)); }

  // END CUT HERE

};
// BEGIN CUT HERE
int main() {
SyllableCounter ___test;
___test.run_test(-1);
}
// END CUT HERE 
