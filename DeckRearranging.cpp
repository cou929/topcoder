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

class DeckRearranging {
public:
  string rearrange(string deck, vector <int> above)
  {
    string ret;

    for (int i=0; i<deck.size(); i++)
      ret.insert(above[i], deck.substr(i, 1));

    return ret;
  }

   
  // BEGIN CUT HERE
public:
  void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
private:
  template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
  void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
  void test_case_0() { string Arg0 = "BRBRR"; int Arr1[] = {0, 0, 1, 0, 3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "RRBRB"; verify_case(0, Arg2, rearrange(Arg0, Arg1)); }
  void test_case_1() { string Arg0 = "RRRRRR"; int Arr1[] = {0,1,2,0,1,3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "RRRRRR"; verify_case(1, Arg2, rearrange(Arg0, Arg1)); }
  void test_case_2() { string Arg0 = "RBRRBRBB"; int Arr1[] = {0,1,2,3,4,5,6,7}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "RBRRBRBB"; verify_case(2, Arg2, rearrange(Arg0, Arg1)); }
  void test_case_3() { string Arg0 = "RBRRBRBB"; int Arr1[] = {0,0,0,0,0,0,0,0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "BBRBRRBR"; verify_case(3, Arg2, rearrange(Arg0, Arg1)); }
  void test_case_4() { string Arg0 = "RBRRBRBB"; int Arr1[] = {0,1,0,0,4,0,6,7}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "RRRRBBBB"; verify_case(4, Arg2, rearrange(Arg0, Arg1)); }

  // END CUT HERE

};

// BEGIN CUT HERE
int main() {
DeckRearranging ___test;
___test.run_test(-1);
}
// END CUT HERE 
