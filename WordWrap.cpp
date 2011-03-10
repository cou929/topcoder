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
class WordWrap {
  public:
  vector <string> splits(const string _s, const string del) {
    vector <string> ret;
    string s = _s;

    while (!s.empty())
      {
        size_t pos = s.find(del);
        string sub = "";
        sub = s.substr(0, pos);
        ret.push_back(sub);
        if (pos != string::npos)
          pos += del.size();
        s.erase(0, pos);
      }

    return ret;
  }

  vector <string> justify(vector <string> lines, int columnWidth) {
    vector <string> ret;
    vector <string> dic;
    int i = 0;

    for (i=0; i<lines.size(); i++) {
      vector <string> a = splits(lines[i], " ");
      dic.insert(dic.end(), a.begin(), a.end());
    }

    for (i=0; i<dic.size(); i++) {
      if (i==0) {
        ret.push_back(dic[i]);
      } else if (columnWidth - ret[ret.size()-1].size() >= dic[i].size() + 1) {
        ret[ret.size()-1] += " ";
        ret[ret.size()-1] += dic[i];
      } else {
        ret.push_back(dic[i]);
      }
    }

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
}
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { 
	string Arr0[] = {"now is the time for all good men",
 "to come to the aid of their country"}; 
	vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
	int Arg1 = 20; 
	string Arr2[] = { "now is the time for",  "all good men to come",  "to the aid of their",  "country" }; 
	vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); 
	verify_case(0, Arg2, justify(Arg0, Arg1)); }
	void test_case_1() { 
	string Arr0[] = {"now",
 "is the time for",
 "all",
 "good",
 "men",
 "to",
 "come to the aid",
 "of",
 "their",
 "country"}; 
	vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
	int Arg1 = 20; 
	string Arr2[] = { "now is the time for",  "all good men to come",  "to the aid of their",  "country" }; 
	vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); 
	verify_case(1, Arg2, justify(Arg0, Arg1)); }
	void test_case_2() { 
	string Arr0[] = {"four score and seven years ago", 
 "our fathers brought forth",
 "upon this continent",
 "a new nation",
 "conceived in liberty", 
 "and dedicated to the proposition", 
 "that all men are created",
 "equal"}; 
	vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
	int Arg1 = 50; 
	string Arr2[] = { "four score and seven years ago our fathers brought",  "forth upon this continent a new nation conceived",  "in liberty and dedicated to the proposition that",  "all men are created equal" }; 
	vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); 
	verify_case(2, Arg2, justify(Arg0, Arg1)); }
	void test_case_3() { 
	string Arr0[] = {"th e ow l an d th e pu ss yc at",
 "we nt to se a",
 "on a be au ti fu l pe a gr ee n bo at"}; 
	vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
	int Arg1 = 4; 
	string Arr2[] = { "th e",  "ow l",  "an d",  "th e",  "pu",  "ss",  "yc",  "at",  "we",  "nt",  "to",  "se a",  "on a",  "be",  "au",  "ti",  "fu l",  "pe a",  "gr",  "ee n",  "bo",  "at" }; 
	vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); 
	verify_case(3, Arg2, justify(Arg0, Arg1)); }
	void test_case_4() { 
	string Arr0[] = {"now is the time for all good men",
 "to come to the aid of their country"}; 
	vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
	int Arg1 = 20; 
	string Arr2[] = { "now is the time for",  "all good men to come",  "to the aid of their",  "country" }; 
	vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); 
	verify_case(4, Arg2, justify(Arg0, Arg1)); }
	void test_case_5() { 
	string Arr0[] = {"now is the time for all good men",
 "to come to the aid of their country"}; 
	vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
	int Arg1 = 20; 
	string Arr2[] = { "now is the time for",  "all good men to come",  "to the aid of their",  "country" }; 
	vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); 
	verify_case(5, Arg2, justify(Arg0, Arg1)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
WordWrap ___test;
___test.run_test(-1);
}
// END CUT HERE 
