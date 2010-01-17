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
class PositiveID {
public:
  set <string> split(const string _s, const string del)
  {
    set <string> ret;
    string s = _s;

    while (!s.empty())
      {
	size_t pos = s.find(del);
	string sub = "";
	sub = s.substr(0, pos);
	ret.insert(sub);
	if (pos != string::npos)
	  pos += del.size();
	s.erase(0, pos);
      }

    return ret;
  }

  int maximumFacts(vector <string> suspects)
  {
    int ret = 0;
    vector <set <string> > sus;

    for (int i=0; i<suspects.size(); i++)
      sus.push_back(split(suspects[i], ","));

    for (int i=0; i<sus.size(); i++)
      for (int j=0; j<sus.size(); j++)
	if (i != j)
	  {
	    int c = 0;
	    for (set <string>::iterator it=sus[i].begin(); it!=sus[i].end(); it++)
	      {

		if (sus[j].find(*it) != sus[j].end())
		  c++;
	      }
	    ret = max(c, ret);
	  }

    return ret;
  }
   
  // BEGIN CUT HERE
public:
  void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
private:
  template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
  void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
  void test_case_0() { string Arr0[] = {"blond,tall,skinny",
					"short,skinny,blond,tattooed",
					"scarred,bald"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(0, Arg1, maximumFacts(Arg0)); }
  void test_case_1() { string Arr0[] = {"gigantic,fluorescent,loud,male"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(1, Arg1, maximumFacts(Arg0)); }
  void test_case_2() { string Arr0[] = {"medium,average,nondescript",
					"medium,average,nondescript"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(2, Arg1, maximumFacts(Arg0)); }
  void test_case_3() { string Arr0[] = {"big,tall,loud,happy,male,scarred,tattooed,dirty",
					"short,male,beard,quiet,happy,tanned,handsome",
					"female,pretty,blond,quiet",
					"somnambulistic",
					"happy,tiny,stout,male,tanned,beard,blond"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(3, Arg1, maximumFacts(Arg0)); }

  // END CUT HERE

};
// BEGIN CUT HERE
int main() {
PositiveID ___test;
___test.run_test(-1);
}
// END CUT HERE 
