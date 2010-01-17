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
class AppleWord {
  // 正規表現 /^ap+le$/i にマッチするような文字列をapple wordという. 与えられた文字列に対して, ある文字を別の文字に入れ替えることができる. 与えられた文字列をapple wordにするには何回文字を入れ替えればよいか. 不可能な場合は-1.
  // -1になるのは文字長が5未満のとき. あとは最初の文字が"a", 最後の二文字が"el"になっているかを調べ, その間を"p"になるようにします.
public:
  int minRep(string word) {
    int ret = 0;

    if (word.size() < 5)
      return -1;

    if (word[0] != 'a' && word[0] != 'A')
      ret += 1;

    for (int i=1; i<word.size()-2; i++)
      if (word[i] != 'p' && word[i] != 'P')
        ret++;

    if (word[word.size()-2] != 'l' && word[word.size()-2] != 'L')
      ret += 1;

    if (word[word.size()-1] != 'e' && word[word.size()-1] != 'E')
      ret += 1;

    return ret;
  }
   
  // BEGIN CUT HERE
public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "Apple"; int Arg1 = 0; verify_case(0, Arg1, minRep(Arg0)); }
	void test_case_1() { string Arg0 = "apPpPPlE"; int Arg1 = 0; verify_case(1, Arg1, minRep(Arg0)); }
	void test_case_2() { string Arg0 = "APLE"; int Arg1 = -1; verify_case(2, Arg1, minRep(Arg0)); }
	void test_case_3() { string Arg0 = "TopCoder"; int Arg1 = 7; verify_case(3, Arg1, minRep(Arg0)); }

  // END CUT HERE

};
// BEGIN CUT HERE
int main() {
AppleWord ___test;
___test.run_test(-1);
}
// END CUT HERE 
