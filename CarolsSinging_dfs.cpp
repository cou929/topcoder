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
class CarolsSinging {
public:
  vector <string> lyrics;
  int ret;

  bool check(vector <int> v)
  {
    bool sang[lyrics.size()];
    memset(sang, false, sizeof(sang));

    for (int i=0; i<lyrics.size(); i++)
      for (int j=0; j<v.size(); j++)
	if (v[j] == 1 && lyrics[i][j] == 'Y')
	  sang[i] = true;

    for (int i=0; i<lyrics.size(); i++)
      if (!sang[i])
	return false;

    int tmp = 0;
    for (int i=0; i<v.size(); i++)
      if (v[i] == 1)
	tmp++;

    ret = min(ret, tmp);

    return true;
  }

  int dfs(int c, vector <int> & v)
  {
    if (c == lyrics[0].size())
      {
	check(v);
	return 0;
      }

    c++;
    v.push_back(0);
    dfs(c, v);
    v.erase(v.end()-1);

    v.push_back(1);
    dfs(c, v);
    v.erase(v.end()-1);

    return 0;
  }

  int choose(vector <string> _lyrics)
  {
    lyrics = _lyrics;
    ret = lyrics.size();
    vector <int> tmp;

    int b = 1 << 3;

    dfs(0, tmp);

    return ret;
  }
  // BEGIN CUT HERE
public:
  void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
private:
  template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
  void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
  void test_case_0() { string Arr0[] = {"YN","NY"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(0, Arg1, choose(Arg0)); }
  void test_case_1() { string Arr0[] = {"YN","YY","YN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(1, Arg1, choose(Arg0)); }
  void test_case_2() { string Arr0[] = {"YNN","YNY","YNY","NYY","NYY","NYN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(2, Arg1, choose(Arg0)); }
  void test_case_3() { string Arr0[] = {"YNNYYY","YYNYYY","YNNYYN","NYYNNN","YYYNNN","YYYNNY","NYYYYY","NYNYYY","NNNNYY",
					"YYYYYY","YNNNNN","YYYYNY","YYNNNN","NNYYYN","NNNNYY","YYYNNN","NYNNYN","YNNYYN",
					"YYNNNY","NYYNNY","NNYYYN","YNYYYN","NNNYNY","YYYYNN","YYNYNN","NYYNYY","YYNYYN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(3, Arg1, choose(Arg0)); }

  // END CUT HERE

};
// BEGIN CUT HERE
int main() {
CarolsSinging ___test;
___test.run_test(-1);
}
// END CUT HERE 
