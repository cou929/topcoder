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
class SkewSymmetric {
public:
  int toInt(string s) {int r = 0; istringstream ss(s); ss >> r; return r;}
  vector <int> split(const string _s, const string del)
  {
    vector <int> ret;
    string s = _s;

    while (!s.empty())
      {
	size_t pos = s.find(del);
	string sub = "";
	sub = s.substr(0, pos);
	ret.push_back(toInt(sub));
	if (pos != string::npos)
	  pos += del.size();
	s.erase(0, pos);
      }

    return ret;
  }

  int minChanges(vector <string> M)
  {
    vector <vector <int> > mat;
    int ret = 0;

    for (int i=0; i<M.size(); i++)
      mat.push_back(split(M[i], " "));

    for (int i=0; i<mat.size(); i++)
      for (int j=i; j<mat[i].size(); j++)
	{
	  if (i == j && mat[i][j] != 0)
	    ret++;
	  else if (i != j && mat[i][j] != (-1) * mat[j][i])
	    ret++;
	}

    return ret;
  }
   
  // BEGIN CUT HERE
public:
  void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
private:
  template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
  void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
  void test_case_0() { string Arr0[] = {"1 2 8", "-2 1 0", "3 99 3"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; verify_case(0, Arg1, minChanges(Arg0)); }
  void test_case_1() { string Arr0[] = {"0 1 1 1 1 1", "-1 0 1 1 1 1", "-1 -1 0 1 1 1", 
					"-1 -1 -1 0 1 1", "-1 -1 -1 -1 0 1", "0 0 0 0 0 0"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; verify_case(1, Arg1, minChanges(Arg0)); }
  void test_case_2() { string Arr0[] = {"0 0 0 0", "0 0 0 0", "0 0 0 0", "0 0 0 0"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(2, Arg1, minChanges(Arg0)); }
  void test_case_3() { string Arr0[] = {"1 0", "0 1"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(3, Arg1, minChanges(Arg0)); }

  // END CUT HERE

};
// BEGIN CUT HERE
int main() {
SkewSymmetric ___test;
___test.run_test(-1);
}
// END CUT HERE 
