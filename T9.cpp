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
// BEGIN CUT HERE
#include "cout.hpp"
// END CUT HERE 
using namespace std;
class T9 {
public:
  vector <string> part;
  vector <string> dict;

  bool ok(string s, vector <int> word) {
    int i, j;
    int n = s.size();

    //    cout << s << endl;

    if (n != word.size())
      return false;

    for (i=0; i<n; i++) {
      bool flag = false;
      //      cout << s << " " << part[word[i]-1] << endl;
      for (j=0; j<part[word[i]-1].size(); j++) {
        if (s[i] == part[word[i]-1][j]) {
          flag = true;
          break;
        }
      }
      if (!flag)
        return false;
    }

    return true;
  }

  string searchWord(vector <int> word, int sharps) {
    string ret;
    int i;
    int n = dict.size();
    int couter = 0;

//     for (i=0; i<word.size(); i++)
//       cout << word[i] << " ";
//     cout << sharps << endl;

    for (i=0; i<n; i++) {
      string can = dict[i];
      if (ok(can, word)) {
        if (sharps == couter) {
          ret = can;
          break;
        }
        couter++;
      }
    }

    return ret;
  }

  string message(vector <string> _part, vector <string> _dict, vector <string> keystr) {
    string ret;
    string keys;
    part = _part;
    dict = _dict;
    int i;
    sort(dict.begin(), dict.end());
    
    for (i=0; i<keystr.size(); i++)
      keys += keystr[i];

    int n = keys.size();
    vector <int> word;
    int sharps = 0;

    for (i=0; i<n; i++) {
      if (keys[i] == '0') {
        if (word.size() > 0)
          ret += searchWord(word, sharps);
        ret += ' ';
        word.clear();
        sharps = 0;
      } else if ('1' <= keys[i] && keys[i] <= '9') {
        word.push_back(keys[i] - '0');
      } else if (keys[i] == '#') {
        sharps++;
      } else if (keys[i] == '*') {
        sharps += 5;
      }
    }

    if (word.size() > 0)
      ret += searchWord(word, sharps);
     
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
  }
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { 
    string Arr0[] = {"", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"}; 
    vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
    string Arr1[] = {"bad"}; 
    vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); 
    string Arr2[] = {"2230223"}; 
    vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); 
    string Arg3 = "bad bad"; 
    verify_case(0, Arg3, message(Arg0, Arg1, Arg2)); }
	void test_case_1() { 
    string Arr0[] = {"", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"}; 
    vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
    string Arr1[] = {"the", "tie"}; 
    vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); 
    string Arr2[] = {"0843#000843#000"}; 
    vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); 
    string Arg3 = " tie   tie   "; 
    verify_case(1, Arg3, message(Arg0, Arg1, Arg2)); }
	void test_case_2() { 
    string Arr0[] = {"", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"}; 
    vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
    string Arr1[] = {"bad", "ace", "aad", "aae", "aaf", "acf", "acd", "the", "tie"}; 
    vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); 
    string Arr2[] = {"223#02", "23*#00843#0"}; 
    vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); 
    string Arg3 = "aae bad  tie "; 
    verify_case(2, Arg3, message(Arg0, Arg1, Arg2)); }
	void test_case_3() { 
    string Arr0[] = {"", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"}; 
    vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
    string Arr1[] = {"the", "tie", "bad", "ace", "aad", "aae", "aaf", "acf", "acd"}; 
    vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); 
    string Arr2[] = {"84300223#02", "23#*"}; 
    vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); 
    string Arg3 = "the  aae bad"; 
    verify_case(3, Arg3, message(Arg0, Arg1, Arg2)); }
	void test_case_4() { 
    string Arr0[] = {"", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"}; 
    vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
    string Arr1[] = {"bad", "ace", "aad", "aae", "tie", "aaf", "acf", "acd", "the"}; 
    vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); 
    string Arr2[] = {"223#02", "23######"}; 
    vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); 
    string Arg3 = "aae bad"; 
    verify_case(4, Arg3, message(Arg0, Arg1, Arg2)); }
	void test_case_5() { 
    string Arr0[] = {"", "rq", "lde", "yoauz", "cbfgn", "tjkpx", "wvs", "ih", "m"}; 
    vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
    string Arr1[] = {"xktgmfmoqlmivm", 
                     "hmthr", 
                     "tpjgmnmaremiwm", 
                     "tpjcmnmyrlmhvm", 
                     "xkpnmgmzqdmhsm", 
                     "wqopvvmiig", 
                     "melbcbqeeg", 
                     "jkxnmbmardmhwm", 
                     "kpxnmcmyqlmism", 
                     "wrztvsmhhf", 
                     "srztssmiic", 
                     "pxtgmfmyrdmhwm", 
                     "vqoxswmiin", 
                     "wryksvmihb", 
                     "ptjfmbmoremhvm"}; 
    vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); 
    string Arr2[] = {"00", 
                     "7246779885##00000089682000007246779885##0000724677", 
                     "9885#000089682000093355523350066659594239879###000"}; 
    vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); 
    string Arg3 = "  wqopvvmiig      hmthr     wqopvvmiig    vqoxswmiin    hmthr    melbcbqeeg  pxtgmfmyrdmhwm   "; 
    verify_case(5, Arg3, message(Arg0, Arg1, Arg2)); }
	void test_case_6() { 
    string Arr0[] = {"", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"}; 
    vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
    string Arr1[] = {"bad"}; 
    vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); 
    string Arr2[] = {"2230223"}; 
    vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); 
    string Arg3 = "bad bad"; 
    verify_case(6, Arg3, message(Arg0, Arg1, Arg2)); }
	void test_case_7() { 
    string Arr0[] = {"", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"}; 
    vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
    string Arr1[] = {"bad"}; 
    vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); 
    string Arr2[] = {"2230223"}; 
    vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); 
    string Arg3 = "bad bad"; 
    verify_case(7, Arg3, message(Arg0, Arg1, Arg2)); }

  // END CUT HERE

};
// BEGIN CUT HERE
int main() {
T9 ___test;
___test.run_test(-1);
}
// END CUT HERE 
