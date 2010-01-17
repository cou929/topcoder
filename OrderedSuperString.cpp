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
class OrderedSuperString {
public:
  int getLength(vector <string> words)
  {
    int ret = 0;
    string super = words[0];
    int index = 0;

    for (int i=1; i<words.size(); i++)
      {
	//	cout << "super: " << super << " index: " << index << endl;
	if (int p = super.find(words[i], index) != string::npos)
	  {
	    index = max(index, p-1);
	    continue;
	  }
	else
	  {
	    int sublen = min((super.size() - index), words[i].size());
	    string tmpsuper = super.substr(super.size() - sublen);
	    string tmpword = words[i].substr(0, sublen);
	    int pos = super.size();
	    string addition = words[i];

	    while (tmpsuper != "")
	      {
		//		cout << words[i] << "  " << tmpsuper << " " << tmpword << endl;
		if (tmpsuper == tmpword)
		  {
		    pos = super.size() - tmpword.size();
		    addition = words[i].erase(0, tmpword.size());
		    break;
		  }
		else
		  {
		    tmpsuper.erase(0, 1);
		    tmpword.erase(tmpword.size()-1);
		  }
	      }

	    index = max(index, pos);
	    super += addition;
	  }
      }
    //    cout << "RESULT: " << super << endl;
    ret = super.size();

    //     for (int i=0; i<words.size(); i++)
    //       {
    // 	string tmpsuper = super.substr(index);
    // 	//	cout << super << " " << tmpsuper << " " << words[i] << " " << index << endl;

    // 	if (int pos = tmpsuper.find(words[i]) != string::npos)
    // 	  {
    // 	    index = max(index, pos-1);
    // 	    continue;
    // 	  }

    // 	int pos = super.size();
    // 	string addition = words[i];
    // 	for (int j=1; j<words[i].size(); j++)
    // 	  {
    // 	    string sub = words[i].substr(0, words[i].size()-j);
    // 	    if (tmpsuper.size() < sub.size())
    // 	      continue;

    // 	    string supsub = tmpsuper.substr(tmpsuper.size()-sub.size());
    // 	    if (sub == supsub)
    // 	      {
    // 		pos = super.size() - sub.size();
    // 		addition = words[i].substr(words[i].size() - j);
    // 		break;
    // 	      }
    // 	  }

    // 	index = max(index, pos);
    // 	super += addition;
    //       }

    //     //    cout << "RESULT: " << super << endl;

    //     ret = super.size();

    return ret;
  }
   
  // BEGIN CUT HERE
public:
  void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
private:
  template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
  void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
  void test_case_0() { string Arr0[] = {"abc","ca"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(0, Arg1, getLength(Arg0)); }
  void test_case_1() { string Arr0[] = {"a","a","b","a"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(1, Arg1, getLength(Arg0)); }
  void test_case_2() { string Arr0[] = {"abcdef", "ab","bc", "de","ef"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; verify_case(2, Arg1, getLength(Arg0)); }
  void test_case_3() { string Arr0[] = {"aaaaaaaaaa", "a", "ab", "a", "abbbb"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 14; verify_case(3, Arg1, getLength(Arg0)); }
  void test_case_4() { string Arr0[] = {"aaaaaaaaaaabaaaaaaaa", "bac", "aaaabacaaa", "ab", "ba", "a", "ca"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 33; verify_case(4, Arg1, getLength(Arg0)); }

  // END CUT HERE

};
// BEGIN CUT HERE
int main() {
OrderedSuperString ___test;
___test.run_test(-1);
}
// END CUT HERE 


// aaaaaaaaaaabaaaaaaaabacaaaabacaaabaca
// "aaaaaaaaaaabaaaaaaaa", "bac", "aaaabacaaa", "ab", "ba", "a", "ca"
// aaaaaaaaaaabaaaaaaaabacaaaabacaaa
// 123456789012345678901234567890
// "aaaaaaaaaa", "a", "ab", "a", "abbbb"
// aaaaaaaaaababbbb
// aaaaaaaaaabbbb
// aaaaaaaaaabbbb
// 123456789012345678901234567890
