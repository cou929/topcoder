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

class SimpleRotationDecoder {
public:
  int toVar(char c)
  {
    int ret = 0;
    if (c != ' ')
      ret = c - 'a' + 1;
      
    return ret;
  }

  char toChar(int d)
  {
    char ret = ' ';
    if (d > 0)
      ret = 'a' + d - 1;
      
    return ret;
  }

  vector <string> getWords(string s)
  {
    size_t pos;
    vector <string> ret;

    while (!s.empty())
      {
	pos = s.find(' ');
	if (pos == string::npos)
	  {
	    ret.push_back(s.substr(0));
	    s.erase(0);
	  }
	else
	  {
	    ret.push_back(s.substr(0, pos));
	    s.erase(0, pos+1);
	  }
      }
    return ret;
  }

  bool isValid(string s)
  {
    vector <string> words;
    char vow[5] = {'a', 'i', 'u', 'e', 'o'};

    if (s[0] == ' ' || s[s.size()-1] == ' ')
      return false;

    words = getWords(s);

    for (int i=0; i<words.size(); i++)
      {
	if (words[i].size() < 2 || 8 < words[i].size())
	  return false;

	bool ok = false;
	for (int j=0; j<5; j++)
	  if (words[i].find(vow[j]) != string::npos)
	    {
	      ok = true;
	      break;
	    }

	if (!ok)
	  return false;
      }

    return true;
  }

  string decode(string cipherText)
  {
    string ret = "";
    string pass = "";

    for (int a=0; a<26; a++)
      for (int b=0; b<26; b++)
	for (int c=0; c<26; c++)
	  {
	    pass = "";
	    pass += 'a' + a;
	    pass += 'a' + b;
	    pass += 'a' + c;

	    string tmp = "";
	    for (int i=0; i<cipherText.size(); i++)
	      tmp += toChar((27 + toVar(cipherText[i]) - toVar(pass[i%3])) % 27);

	    if (isValid(tmp))
	      {
		ret = tmp;
		break;
	      }
	  }

    return ret;
  }

   
  // BEGIN CUT HERE
public:
  void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
private:
  template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
  void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
  void test_case_0() { string Arg0 = "mmbtvrbhhtgohaktklqegnrmlelojotyeyeiudvtil ey ffg"; string Arg1 = "the quick brown fox jumps over the lazy dog again"; verify_case(0, Arg1, decode(Arg0)); }
  void test_case_1() { string Arg0 = "ntgntgntgntofwlfwlfwlnookookook"; string Arg1 = "he he he heh he he heh he he he"; verify_case(1, Arg1, decode(Arg0)); }
  void test_case_2() { string Arg0 = "f sgnzslhzquq ydyuinmqiwfyrtdvn"; string Arg1 = "abkbprnn usmlbqz mdpelkoa jofni"; verify_case(2, Arg1, decode(Arg0)); }
  void test_case_3() { string Arg0 = "shxnaaeqjlofhhsuurbhpdgt z"; string Arg1 = "naeiui jrghnca pnzxaxz avs"; verify_case(3, Arg1, decode(Arg0)); }

  // END CUT HERE

};

// BEGIN CUT HERE
int main() {
SimpleRotationDecoder ___test;
 ___test.run_test(-1);
}
// END CUT HERE 
