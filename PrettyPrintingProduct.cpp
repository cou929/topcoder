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
class PrettyPrintingProduct {
public:
  string toStr(int n) {ostringstream ss; ss << n; return ss.str();}

  string plus(string a, string b)
  {
    string ret;

    int i = 0;
    int up = 0;

    while (i < a.size() || i < b.size())
      {
	int ai = (i < a.size()) ? a[a.size() - 1 - i] - '0' : 0;
	int bi = (i < b.size()) ? b[b.size() - 1 - i] - '0' : 0;
	int sum = ai + bi + up;

	ret += sum % 10 + '0';
	up = sum / 10;

	i++;
      }

    if (up)
      ret += '1';

    reverse(ret.begin(), ret.end());
    return ret;
  }

  string mul(string a, string b)
  {
    string ret = "0";
    vector <string> muls;

    for (int i=0; i<b.size(); i++)
      {
	string tmp;
	int cur = b[b.size() - 1 - i] - '0';
	for (int j=0; j<i; j++)
	  tmp += "0";

	int up = 0;
	for (int j=0; j<a.size(); j++)
	  {
	    int n = a[a.size() - 1 - j] - '0';
	    n *= cur;
	    n += up;
	    up = n / 10;
	    tmp += n % 10 + '0';
	  }
	if (up)
	  tmp += up + '0';
	reverse(tmp.begin(), tmp.end());
	muls.push_back(tmp);
      }

    for (int i=0; i<muls.size(); i++)
      ret = plus(ret, muls[i]);

    return ret;
  }

  string prettyPrint(int A, int B)
  {
    string ret;
    string m = "1";

    for (int i=A; i<=B; i++)
      m = mul(m, toStr(i));

    int zeros = 0;
    for (int i=0;; i++)
      if (m[m.size() - 1 - i] == '0')
	zeros++;
      else
	break;

    m.erase(m.end()-zeros, m.end());

    if (m.size() > 10)
      {
	ret += m.substr(0, 5);
	ret += "...";
	ret += m.substr(m.size()-5, 5);
      }
    else
      {
	ret += m;
      }

    ret += " * 10^";
    ret += toStr(zeros);

    return ret;
  }
   
  // BEGIN CUT HERE
public:
  void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); if ((Case == -1) || (Case == 7)) test_case_7(); }
private:
  template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
  void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
  void test_case_0() { int Arg0 = 1; int Arg1 = 10; string Arg2 = "36288 * 10^2"; verify_case(0, Arg2, prettyPrint(Arg0, Arg1)); }
  void test_case_1() { int Arg0 = 7; int Arg1 = 7; string Arg2 = "7 * 10^0"; verify_case(1, Arg2, prettyPrint(Arg0, Arg1)); }
  void test_case_2() { int Arg0 = 211; int Arg1 = 214; string Arg2 = "2038974024 * 10^0"; verify_case(2, Arg2, prettyPrint(Arg0, Arg1)); }
  void test_case_3() { int Arg0 = 411; int Arg1 = 414; string Arg2 = "28952...24024 * 10^0"; verify_case(3, Arg2, prettyPrint(Arg0, Arg1)); }
  void test_case_4() { int Arg0 = 412; int Arg1 = 415; string Arg2 = "2923450236 * 10^1"; verify_case(4, Arg2, prettyPrint(Arg0, Arg1)); }
  void test_case_5() { int Arg0 = 47; int Arg1 = 4700; string Arg2 = "14806...28928 * 10^1163"; verify_case(5, Arg2, prettyPrint(Arg0, Arg1)); }
  void test_case_6() { int Arg0 = 1; int Arg1 = 19; string Arg2 = "12164...08832 * 10^3"; verify_case(6, Arg2, prettyPrint(Arg0, Arg1)); }
  void test_case_7() { int Arg0 = 13; int Arg1 = 25; string Arg2 = "32382...26624 * 10^4"; verify_case(7, Arg2, prettyPrint(Arg0, Arg1)); }

  // END CUT HERE

};
// BEGIN CUT HERE
int main() {
PrettyPrintingProduct ___test;
___test.run_test(-1);
}
// END CUT HERE 
