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
class IQTest {
public:
  string toStr(int n) {ostringstream ss; ss << n; return ss.str();}
  string nextNumber(vector <int> previous)
  {
    vector <pair <int, int> > sols;

    if (previous.size() == 1)
      return "AMBIGUITY";

    for (int i=-1000; i<=1000; i++)
      for (int j=-20000; j<=20000; j++)
	if (previous[0] * i + j == previous[1])
	  {
	    pair <int, int> tmp(i, j);
	    sols.push_back(tmp);
	  }

    for (int i=1; i<previous.size()-1; i++)
      for (int j=0; j<sols.size(); j++)
	if (previous[i] * sols[j].first + sols[j].second != previous[i+1])
	  {
	    sols.erase(sols.begin() + j);
	    j--;
	  }

    set <int> next;
    for (int i=0; i<sols.size(); i++)
      next.insert( previous[previous.size()-1] * sols[i].first + sols[i].second);

    if (sols.size() == 0)
      return "BUG";

    if (next.size() > 1)
      return "AMBIGUITY";

    return toStr(*next.begin());
  }
   
  // BEGIN CUT HERE
public:
  void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); if ((Case == -1) || (Case == 7)) test_case_7(); if ((Case == -1) || (Case == 8)) test_case_8(); if ((Case == -1) || (Case == 9)) test_case_9(); }
private:
  template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
  void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
  void test_case_0() { int Arr0[] = {1, 2, 3, 4, 5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "6"; verify_case(0, Arg1, nextNumber(Arg0)); }
  void test_case_1() { int Arr0[] = {3, 6, 12, 24, 48}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "96"; verify_case(1, Arg1, nextNumber(Arg0)); }
  void test_case_2() { int Arr0[] = {1, 4, 13, 40}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "121"; verify_case(2, Arg1, nextNumber(Arg0)); }
  void test_case_3() { int Arr0[] = {0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "AMBIGUITY"; verify_case(3, Arg1, nextNumber(Arg0)); }
  void test_case_4() { int Arr0[] = {-1, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "AMBIGUITY"; verify_case(4, Arg1, nextNumber(Arg0)); }
  void test_case_5() { int Arr0[] = {57, 57}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "57"; verify_case(5, Arg1, nextNumber(Arg0)); }
  void test_case_6() { int Arr0[] = {16, -8, 4, -2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "BUG"; verify_case(6, Arg1, nextNumber(Arg0)); }
  void test_case_7() { int Arr0[] = {6, 5, 4, 3, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "BUG"; verify_case(7, Arg1, nextNumber(Arg0)); }
  void test_case_8() { int Arr0[] = {-12, 12, -36, 60}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "-132"; verify_case(8, Arg1, nextNumber(Arg0)); }
  void test_case_9() { int Arr0[] = {-100, -99, 99}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "39303"; verify_case(8, Arg1, nextNumber(Arg0)); }

  // END CUT HERE

};
// BEGIN CUT HERE
int main() {
IQTest ___test;
___test.run_test(-1);
}
// END CUT HERE 
