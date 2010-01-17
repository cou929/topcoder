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
class Library {
public:
  vector <string> split(const string _s, const string del) {
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

  int documentAccess(vector <string> records, vector <string> userGroups, vector <string> roomRights) {
    int ret = 0;
    set <string> docs;

    for (int i=0; i<records.size(); i++) {
      vector <string> tmp = split(records[i], " ");
      if (find(userGroups.begin(), userGroups.end(), tmp[2]) != userGroups.end() &&
          find(roomRights.begin(), roomRights.end(), tmp[1]) != roomRights.end())
        docs.insert(tmp[0]);
    }

    ret = docs.size();

    return ret;
  }
   
  // BEGIN CUT HERE
public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"diary computers editor","fairytale gardening editor","comix cars author","comix cars librarian"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"employee","editor","author"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"history","cars","computers"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 2; verify_case(0, Arg3, documentAccess(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arr0[] = {"diary computers editor","fairytale gardening editor","comix cars author","comix cars librarian"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"employee","editor","author","librarian"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"history","cars","computers"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 2; verify_case(1, Arg3, documentAccess(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arr0[] = {"diary computers editor","fairytale gardening editor","comix cars author","comix cars librarian"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"employee","editor","author","librarian"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 0; verify_case(2, Arg3, documentAccess(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arr0[] = {"a b c","a b d","b b c","b b d","e c d","e c b","e c c","t d e"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"c","d","x"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"a","b","c"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 3; verify_case(3, Arg3, documentAccess(Arg0, Arg1, Arg2)); }

  // END CUT HERE

};
// BEGIN CUT HERE
int main() {
Library ___test;
___test.run_test(-1);
}
// END CUT HERE 
