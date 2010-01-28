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
class MagicWords {
public:
  map <string, int> memo;

  bool isMagic(string &str, int pos) {
    int len = str.size();
    for (int i=0; i<len; i++)
      if (str[i] != str[(i+pos)%len])
        return false;
    return true;
  }

  int count(vector <string> S, int K) {
    int ret = 0;
    vector <int> pos;
    for (int i=0; i<S.size(); i++) pos.push_back(i);

    do {
      string str;
      int magic = 0;
      for (int i=0; i<S.size(); i++) str += S[pos[i]];
      if (memo.find(str) != memo.end()) 
        magic = memo[str];
      else
        for (int i=0; i<str.size(); i++) if (isMagic(str, i)) magic++;
      memo[str] = magic;
      if (magic == K) ret++;
    } while (next_permutation(pos.begin(), pos.end()));

    return ret;
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
    if ((Case == -1) || (Case == 6)) test_case_6();
    if ((Case == -1) || (Case == 7)) test_case_7();
    if ((Case == -1) || (Case == 8)) test_case_8();
  }
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { 
    string Arr0[] = {"CAD","ABRA","ABRA"}; 
    vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
    int Arg1 = 1; 
    int Arg2 = 6; 
    verify_case(0, Arg2, count(Arg0, Arg1)); }
	void test_case_1() { 
    string Arr0[] = {"AB","RAAB","RA"}; 
    vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
    int Arg1 = 2; 
    int Arg2 = 3; 
    verify_case(1, Arg2, count(Arg0, Arg1)); }
	void test_case_2() { 
    string Arr0[] = {"AA","AA","AAA","A"}; 
    vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
    int Arg1 = 1; 
    int Arg2 = 0; 
    verify_case(2, Arg2, count(Arg0, Arg1)); }
	void test_case_3() { 
    string Arr0[] = {"AA","AA","AAA","A","AAA","AAAA"}; 
    vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
    int Arg1 = 15; 
    int Arg2 = 720; 
    verify_case(3, Arg2, count(Arg0, Arg1)); }
	void test_case_4() { 
    string Arr0[] = {"ABC","AB","ABC","CA"}; 
    vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
    int Arg1 = 3; 
    int Arg2 = 0; 
    verify_case(4, Arg2, count(Arg0, Arg1)); }
	void test_case_5() { 
    string Arr0[] = {"A","B","C","A","B","C"}; 
    vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
    int Arg1 = 1; 
    int Arg2 = 672; 
    verify_case(5, Arg2, count(Arg0, Arg1)); }
	void test_case_6() { 
    string Arr0[] = {"AAAAAAAAAAAAAAAAAAAA",
                     "AAAAAAAAAAAAAAAAAAAA",
                     "AAAAAAAAAAAAAAAAAAAA",
                     "AAAAAAAAAAAAAAAAAAAA",
                     "AAAAAAAAAAAAAAAAAAAA",
                     "AAAAAAAAAAAAAAAAAAAA",
                     "AAAAAAAAAAAAAAAAAAAA",
                     "AAAAAAAAAAAAAAAAAAAB"}; 
    vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
    int Arg1 = 1; 
    int Arg2 = 40320; 
    verify_case(6, Arg2, count(Arg0, Arg1)); }
	void test_case_7() { 
    string Arr0[] = {"A"}; 
    vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
    int Arg1 = 200; 
    int Arg2 = 0; 
    verify_case(7, Arg2, count(Arg0, Arg1)); }
	void test_case_8() { 
    string Arr0[] = {"AAIIDMLAKSIVMLAAAAAA",
                     "AAAAAAAAABANDJAAAAAA",
                     "AAAAAAAAAAAAAAAAAAAA",
                     "BNVJSUWOPMLOPIMMSHSU",
                     "AISUENDJNJKAHDNVVVVA",
                     "JAJJASNKJFNUEHINQKJL",
                     "KKKKKAAAAAIISDMASKLA",
                     "IAJWQQQQQQQIOMQQAAAB"}; 
    vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
    int Arg1 = 1; 
    int Arg2 = 6; 
    verify_case(8, Arg2, count(Arg0, Arg1)); }

  // END CUT HERE

};
// BEGIN CUT HERE
int main() {
MagicWords ___test;
___test.run_test(-1);
}
// END CUT HERE 
