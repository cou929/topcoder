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

class TagalogDictionary {
public:
  vector <string> dic;
  TagalogDictionary(void)
  {
    dic.push_back("a");
    dic.push_back("b");
    dic.push_back("k");
    dic.push_back("d");
    dic.push_back("e");
    dic.push_back("g");
    dic.push_back("h");
    dic.push_back("i");
    dic.push_back("l");
    dic.push_back("m");
    dic.push_back("n");
    dic.push_back("ng");
    dic.push_back("o");
    dic.push_back("p");
    dic.push_back("r");
    dic.push_back("s");
    dic.push_back("t");
    dic.push_back("u");
    dic.push_back("w");
    dic.push_back("y");
  }

  int toVar(string s)
  {
    int ret = 0;
    for (int i=0; i<dic.size(); i++)
      if (s == dic[i])
	ret = i;

    return ret;
  }

  char toChar(int n)
  {
    return 'a' + n;
  }

  vector <string> sortWords(vector <string> words)
  {
    vector <string> ret;
    vector <pair<string, int> > v;

    for (int i=0; i<words.size(); i++)
      {
	string enc = "";
	for (int j=0; j<words[i].size(); j++)
	  {
	    string tmp = "";
	    if (j < words[i].size()-1 && words[i][j] == 'n' && words[i][j+1] == 'g')
	      {
		tmp = "ng";
		j++;
	      }
	    else
	      tmp = words[i][j];

	    enc += toChar(toVar(tmp));
	  }
	pair <string, int> t(enc, i);
	v.push_back(t);
      }

    sort(v.begin(), v.end());

    for (int i=0; i<v.size(); i++)
      ret.push_back(words[v[i].second]);

    return ret;
  }

   
  // BEGIN CUT HERE
public:
  void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
private:
  template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
  void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
  void test_case_0() { string Arr0[] = {"abakada","alpabet","tagalog","ako"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"abakada", "ako", "alpabet", "tagalog" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, sortWords(Arg0)); }
  void test_case_1() { string Arr0[] = {"ang","ano","anim","alak","alam","alab"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"alab", "alak", "alam", "anim", "ano", "ang" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, sortWords(Arg0)); }
  void test_case_2() { string Arr0[] = {"siya","niya","kaniya","ikaw","ito","iyon"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"kaniya", "ikaw", "ito", "iyon", "niya", "siya" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, sortWords(Arg0)); }
  void test_case_3() { string Arr0[] = {"kaba","baka","naba","ngipin","nipin"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"baka", "kaba", "naba", "nipin", "ngipin" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, sortWords(Arg0)); }
  void test_case_4() { string Arr0[] = {"knilngiggnngginggn","ingkigningg","kingkong","dingdong","dindong","dingdont","ingkblot"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"kingkong", "knilngiggnngginggn", "dindong", "dingdont", "dingdong", "ingkblot", "ingkigningg" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(4, Arg1, sortWords(Arg0)); }
  void test_case_5() { string Arr0[] = {"silangang", "baka", "bada", "silang"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"baka", "bada", "silang", "silangang" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(5, Arg1, sortWords(Arg0)); }

  // END CUT HERE

};

// BEGIN CUT HERE
int main() {
TagalogDictionary ___test;
___test.run_test(-1);
}
// END CUT HERE 
