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
class TheBlackJackDivOne {
public:
  double r(vector <int> c, int sum) {
    double ret = 0;
    double total = 0;

    if (sum >= 21) return ret;
    for (int i=0; i<c.size(); i++) total += c[i];
    
    for (int i=0; i<c.size(); i++)
      if (c[i] > 0) {
        c[i]--;
        ret += (c[i] + 1.0) / total * (r(c, sum + i) + 1.0);
        c[i]++;
      }

    return ret;
  }

  double expected(vector <string> cards) {
    double ret = 0;
    vector <int> remind(12, 4);
    remind[0] = 0, remind[1] = 0, remind[10] = 16;
    int sum = 0;

    for (int i=0; i<cards.size(); i++) {
      char n = cards[i][0];
      int index = 0;
      if (2 <= n - '0' && n - '0' <= 9)
        index = n - '0';
      else if (n == 'A')
        index = 11;
      else
        index = 10;

      remind[index]--;
      sum += index;
    }

    ret = r(remind, sum);

    return ret;
  }
  
  // BEGIN CUT HERE
public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"JS"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 2.105854341736695; verify_case(0, Arg1, expected(Arg0)); }
	void test_case_1() { string Arr0[] = {"KD", "8S"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 1.08; verify_case(1, Arg1, expected(Arg0)); }
	void test_case_2() { string Arr0[] = {"KD", "2S", "2C", "2D", "2H"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 1.0; verify_case(2, Arg1, expected(Arg0)); }
	void test_case_3() { string Arr0[] = {"AS", "KS", "9S", "JC", "2D"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 0.0; verify_case(3, Arg1, expected(Arg0)); }

  // END CUT HERE

};
// BEGIN CUT HERE
int main() {
TheBlackJackDivOne ___test;
___test.run_test(-1);
}
// END CUT HERE 
