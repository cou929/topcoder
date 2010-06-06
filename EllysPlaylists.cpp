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

const long long mod = 1000000007;

class EllysPlaylists {
public:
  int memo[51][1001];
  vector <vector <int> > connection;

  int search(int pos, int K) {
    if (memo[pos][K] != -1)
      return memo[pos][K];

    long long ret = 0;
    int i;

    if (K == 0)
      return 1;

    for (i=0; i<connection[pos].size(); i++)
      ret += search(connection[pos][i], K - 1) % mod;

    return memo[pos][K] = ret % mod;
  }

  int countPlaylists(vector <string> songs, int K) {
    long long ret = 0;
    int i, j;
    int n = songs.size();

    memset(memo, -1, sizeof(memo));
    connection = vector <vector <int> >(n);

    for (i=0; i<n; i++)
      for (j=0; j<n; j++)
        if (songs[i][songs[i].size()-1] == songs[j][2] && songs[i][songs[i].size()-2] == songs[j][1]  && songs[i][songs[i].size()-3] == songs[j][0])
          connection[i].push_back(j);

    for (i=0; i<n; i++)
      ret += search(i, K-1) % mod;

    return (int)(ret % mod);
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
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { 
    string Arr0[] = { "abcxxx", "xxxabc", "entersandman", "toxicity", "maneater", "heavensalie",
                      "liebe", "citylights", "fadetoblack", "breakingthehabit", "yyydefg", "defgyyy" }; 
    vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
    int Arg1 = 2; 
    int Arg2 = 5; 
    verify_case(0, Arg2, countPlaylists(Arg0, Arg1)); }
	void test_case_1() { 
    string Arr0[] = { "aaaaaa", "aaabcd", "bcdaaa" }; 
    vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
    int Arg1 = 4; 
    int Arg2 = 13; 
    verify_case(1, Arg2, countPlaylists(Arg0, Arg1)); }
	void test_case_2() { 
    string Arr0[] = { "aaa", "aaaa", "aaaaa" }; 
    vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
    int Arg1 = 3; 
    int Arg2 = 27; 
    verify_case(2, Arg2, countPlaylists(Arg0, Arg1)); }
	void test_case_3() { 
    string Arr0[] = { "elly", "looks", "lovely" }; 
    vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
    int Arg1 = 1; 
    int Arg2 = 3; 
    verify_case(3, Arg2, countPlaylists(Arg0, Arg1)); }
	void test_case_4() { 
    string Arr0[] = { "life", "universe", "everything" }; 
    vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
    int Arg1 = 42; 
    int Arg2 = 0; 
    verify_case(4, Arg2, countPlaylists(Arg0, Arg1)); }
	void test_case_5() { 
    string Arr0[] = { "aaaaaaaaa", "aaabbbaaa", "aaacccaaa", "aaadddaaa", "aaaeeeaaa", "aaafffaaa" }; 
    vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
    int Arg1 = 12; 
    int Arg2 = 176782322; 
    verify_case(5, Arg2, countPlaylists(Arg0, Arg1)); }
	void test_case_6() { 
    string Arr0[] = { "abcxxx", "xxxabc", "entersandman", "toxicity", "maneater", "heavensalie",
                      "liebe", "citylights", "fadetoblack", "breakingthehabit", "yyydefg", "defgyyy" }; 
    vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
    int Arg1 = 2; 
    int Arg2 = 5; 
    verify_case(6, Arg2, countPlaylists(Arg0, Arg1)); }
	void test_case_7() { 
    string Arr0[] = { "abcxxx", "xxxabc", "entersandman", "toxicity", "maneater", "heavensalie",
                      "liebe", "citylights", "fadetoblack", "breakingthehabit", "yyydefg", "defgyyy" }; 
    vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
    int Arg1 = 2; 
    int Arg2 = 5; 
    verify_case(7, Arg2, countPlaylists(Arg0, Arg1)); }

  // END CUT HERE

};
// BEGIN CUT HERE
int main() {
EllysPlaylists ___test;
___test.run_test(-1);
}
// END CUT HERE 
