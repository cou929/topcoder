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
#include <numeric>
// BEGIN CUT HERE
#include "cout.hpp"
// END CUT HERE 
using namespace std;
class HandlesSpelling {
public:
  vector <string> badges;
  string sentence;
  string covered;
  int memo[1001];

  bool match(int pos, string badges) {
    int i;
    for (i=0; i<badges.size(); i++)
      if (pos + i >= sentence.size() || badges[i] != sentence[pos + i])
        return false;
    return true;
  }

  int search(int pos) {
    int ret = 0;
    int i;
    int best = -1;

    if (memo[pos] != -1)
      return memo[pos];

    if (pos >= sentence.size())
      return 0;

    for (i=0; i<badges.size(); i++)
      if (match(pos, badges[i])) {
        int score = (int)badges[i].size() + search(pos + (int)badges[i].size());
        if (ret < score) {
          ret = score;
          best = i;
        }
      }

    int score = search(pos + 1);
    if (ret < score) {
      ret = score;
      best = -1;
    }

    if (best != -1)
      for (i=0; i<badges[best].size(); i++)
        covered[pos + i] = '*';

    return memo[pos] = ret;
  }

  int searchA(string covered) {
    int ret = 0;
    int tmp = 0;
    int i;

    for (i=0; i<covered.size();) {
      if (covered[i] == '*') {
        tmp = 0;
        while (i < covered.size() && covered[i++] == '*')
          tmp++;
        ret = max(ret, tmp);
      } else {
        i++;
      }
    }

    return ret;
  }

  int spellIt(vector <string> parts, vector <string> _badges) {
    int i;

    badges.clear();
    sentence.clear();
    covered.clear();
    memset(memo, -1, sizeof(memo));

    badges = _badges;
    for (i=0; i<parts.size(); i++)
      sentence += parts[i];
    covered = sentence;

    int b = search(0);
    int B = sentence.size() - b;
    int A = searchA(covered);

    return A*A - B;
  }
   
  // BEGIN CUT HERE
public:
	void run_test(int Case) { 
    if ((Case == -1) || (Case == 0)) test_case_0();
    if ((Case == -1) || (Case == 1)) test_case_1();
    if ((Case == -1) || (Case == 2)) test_case_2();
    if ((Case == -1) || (Case == 3)) test_case_3();
    if ((Case == -1) || (Case == 4)) test_case_4();
    if ((Case == -1) || (Case == 5)) test_case_5();
  }
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { 
    string Arr0[] = {"HELLO"}; 
    vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
    string Arr1[] = {"E","HE","L"}; 
    vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); 
    int Arg2 = 15; 
    verify_case(0, Arg2, spellIt(Arg0, Arg1)); }
	void test_case_1() { 
    string Arr0[] = {"ALGORITHM","QUALIFICATION","ROUND","TWO"}; 
    vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
    string Arr1[] = {"AL", "CAT", "GOR", "IFI", "ION", "ROUND", "T"}; 
    vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); 
    int Arg2 = 282; 
    verify_case(1, Arg2, spellIt(Arg0, Arg1)); }
	void test_case_2() { 
    string Arr0[] = {"GOOD","LUCK"}; 
    vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
    string Arr1[] = {"GOODLUCKBJ","G","L"}; 
    vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); 
    int Arg2 = -5; 
    verify_case(2, Arg2, spellIt(Arg0, Arg1)); }
	void test_case_3() { 
    string Arr0[] = {"ANDDOHAVEFUN"}; 
    vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
    string Arr1[] = {"HAV"}; 
    vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); 
    int Arg2 = 0; 
    verify_case(3, Arg2, spellIt(Arg0, Arg1)); }
	void test_case_4() { 
    string Arr0[] = {"QWERTYU"}; 
    vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
    string Arr1[] = {"WE","TY","ERT"}; 
    vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); 
    int Arg2 = 5; 
    verify_case(4, Arg2, spellIt(Arg0, Arg1)); }
	void test_case_5() { 
    string Arr0[] = {"HELLO"}; 
    vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
    string Arr1[] = {"E","HE","L"}; 
    vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); 
    int Arg2 = 15; 
    verify_case(5, Arg2, spellIt(Arg0, Arg1)); }

  // END CUT HERE

};
// BEGIN CUT HERE
int main() {
HandlesSpelling ___test;
___test.run_test(-1);
}
// END CUT HERE 
