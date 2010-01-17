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
class MagicSpell {
public:
  string fixTheSpell(string spell)
  {
    string AZ = "";
    for (int i=0; i<spell.size(); i++)
      if (spell[i] == 'A' || spell[i] == 'Z')
	AZ += spell[i];

    reverse(AZ.begin(), AZ.end());

    int j = 0;
    for (int i=0; i<spell.size(); i++)
      if (spell[i] == 'A' || spell[i] == 'Z')
	{
	  spell[i] = AZ[j];
	  j++;
	}

    return spell;
  }
  // BEGIN CUT HERE
public:
  void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
private:
  template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
  void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
  void test_case_0() { string Arg0 = "AZ"; string Arg1 = "ZA"; verify_case(0, Arg1, fixTheSpell(Arg0)); }
  void test_case_1() { string Arg0 = "ABACADA"; string Arg1 = "ABACADA"; verify_case(1, Arg1, fixTheSpell(Arg0)); }
  void test_case_2() { string Arg0 = "AABZCADZA"; string Arg1 = "AZBACZDAA"; verify_case(2, Arg1, fixTheSpell(Arg0)); }
  void test_case_3() { string Arg0 = "AZBASGHNAZAHBNVZZGGGAGGZAZ"; string Arg1 = "ZABZSGHNAZZHBNVAZGGGAGGAZA"; verify_case(3, Arg1, fixTheSpell(Arg0)); }

  // END CUT HERE
};
// BEGIN CUT HERE
int main() {
MagicSpell ___test;
___test.run_test(-1);
}
// END CUT HERE 
