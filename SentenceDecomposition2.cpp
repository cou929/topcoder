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
class SentenceDecomposition {
public:
  vector <string> words;
  vector <string> sortedWords;
  int ret;

  int calcCost(string word1, string word2)
  {
    int ret = 0;

    for (int i=0; i<word1.size(); i++)
      if (word1[i] != word2[i])
	ret++;

    return ret;
  }

  bool isSameWord(string sub, int index)
  {
    bool ret = false;

    string tmp = sub;
    sort(tmp.begin(), tmp.end());

    if (tmp == sortedWords[index])
      ret = true;

    return ret;
  }

  int s(string sentence, int cost)
  {
    if (sentence.empty())
      {
	if (ret > cost)
	  ret = cost;
	if (ret == -1)
	  ret = cost;

	return 0;
      }

    for (int i=0; i<words.size(); i++)
      {
	string sub = sentence.substr(0, words[i].size());
	if (isSameWord(sub, i))
	  s(sentence.substr(words[i].size()), cost + calcCost(sub, words[i]));
      }

    return 0;
  }
 
  int decompose(string sentence, vector <string> validWords)
  {
    words = validWords;
    ret = -1;

    for (int i=0; i<validWords.size(); i++)
      {
	string tmp = validWords[i];
	sort(tmp.begin(), tmp.end());
	sortedWords.push_back(tmp);
      }

    s(sentence, 0);

    return ret;
  }
   
  // BEGIN CUT HERE
public:
  void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
private:
  template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
  void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
  void test_case_0() { string Arg0 = "neotowheret"; string Arr1[] = {"one", "two", "three", "there"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 8; verify_case(0, Arg2, decompose(Arg0, Arg1)); }
  void test_case_1() { string Arg0 = "abba"; string Arr1[] = {"ab", "ac", "ad"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; verify_case(1, Arg2, decompose(Arg0, Arg1)); }
  void test_case_2() { string Arg0 = "thisismeaningless"; string Arr1[] = {"this", "is", "meaningful"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = -1; verify_case(2, Arg2, decompose(Arg0, Arg1)); }
  void test_case_3() { string Arg0 = "ommwreehisymkiml"; string Arr1[] = {"we", "were", "here", "my", "is", "mom", "here", "si", "milk", "where", "si"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 10; verify_case(3, Arg2, decompose(Arg0, Arg1)); }
  void test_case_4() { string Arg0 = "ogodtsneeencs"; string Arr1[] = {"go", "good", "do", "sentences", "tense", "scen"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 8; verify_case(4, Arg2, decompose(Arg0, Arg1)); }
  void test_case_5() { string Arg0 = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"; string Arr1[] = {"a","b", "aaa", "aab"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; verify_case(5, Arg2, decompose(Arg0, Arg1)); }

  // END CUT HERE

};
// BEGIN CUT HERE
int main() {
SentenceDecomposition ___test;
___test.run_test(5);
}
// END CUT HERE 
