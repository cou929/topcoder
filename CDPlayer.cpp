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

class CDPlayer {
public:
  bool ok(string s)
  {
    map <char, int> m;
    map <char, int>::iterator it;
    for (int i=0; i<s.size(); i++)
      m[s[i]]++;

    for (it=m.begin(); it!=m.end(); it++)
      if (it->second > 1)
	return false;

    return true;
  }

  int isRandom(vector <string> songlist, int n)
  {
    string s = "";

    for (int i=0; i<songlist.size(); i++)
      s += songlist[i];

    for (int i=0; i<n; i++)
      {
	string sub = s.substr(0, i);
	if (!ok(sub))
	  continue;

	int pos = i;
	bool notFound = false;
	while (pos < s.size())
	  {
	    sub = s.substr(pos, n);
	    if (!ok(sub))
	      {
		notFound = true;
		break;
	      }
	    pos += n;
	  }
	if (!notFound)
	  return i;
      }

    return -1;
  }

   
  // BEGIN CUT HERE
public:
  void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
private:
  template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
  void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
  void test_case_0() { string Arr0[] = {"BBAC"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 1; verify_case(0, Arg2, isRandom(Arg0, Arg1)); }
  void test_case_1() { string Arr0[] = {"BACAB",
					"BCA"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 2; verify_case(1, Arg2, isRandom(Arg0, Arg1)); }
  void test_case_2() { string Arr0[] = {"AAACBACBACBACBACBACBACB"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = -1; verify_case(2, Arg2, isRandom(Arg0, Arg1)); }
  void test_case_3() { string Arr0[] = {"ABCDEABDECBAECDEDACB"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; int Arg2 = 0; verify_case(3, Arg2, isRandom(Arg0, Arg1)); }
  void test_case_4() { string Arr0[] = {"ABCABCABCABCABCABCABC",
					"ABCABCABCABCABCABCABC"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 22; int Arg2 = -1; verify_case(4, Arg2, isRandom(Arg0, Arg1)); }
  void test_case_5() { string Arr0[] = {"AAAAAAAAAAAAAAAA",
					"AAAAAAAAAAAAAAAA",
					"AAAAAAAAAAAAAAAA",
					"AAAAAAAAAAAAAAAA",
					"AAAAAAAAAAAAAAAA",
					"AAAAAAAAAAAAAAAA",
					"AAAAAAAAAAAAAAAA",
					"AAAAAAAAAAAAAAAA",
					"AAAAAAAAAAAAAAAA",
					"AAAAAAAAAAAAAAAA"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 0; verify_case(5, Arg2, isRandom(Arg0, Arg1)); }
  void test_case_6() { string Arr0[] = {"ADEF"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 12; int Arg2 = 0; verify_case(6, Arg2, isRandom(Arg0, Arg1)); }

  // END CUT HERE

};

// BEGIN CUT HERE
int main() {
CDPlayer ___test;
___test.run_test(-1);
}
// END CUT HERE 
