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
class TVGameWinnings {
public:
  int getVal(char s) {
    if ('A' <= s && s <= 'I')
      return (s - 'A' + 1) * -1;
    return s - '0';
  }

  vector <int> getMinMax(vector <string> board) {
    vector <int> ret(2, 0);
    vector <int> indices(board.size(), 0);
    ret[0] = INT_MAX, ret[1] = INT_MIN;
    for (int i=0; i<indices.size(); i++)
      indices[i] = i;

    do {
      vector <int> labels(board.size(), 0);
      int label = 1, cur_pos = 0;
      while (1) {
        labels[cur_pos] = label;
        int next_pos = indices[cur_pos];
        if (labels[next_pos] == 0) {
          cur_pos = next_pos;
        } else {
          int i;
          for (i=0; i<labels.size(); i++)
            if (labels[i] == 0) {
              cur_pos = i;
              break;
            }
          if (i == labels.size()) break;
          label++;
        }
      }

      int score = 1;
      for (int i=0; i<indices.size(); i++)
        score *= getVal(board[i][indices[i]]);
      
      if (label % 2 == 0)
        score *= -1;

      ret[0] = min(ret[0], score);
      ret[1] = max(ret[1], score);
    } while (next_permutation(indices.begin(), indices.end()));

    return ret;
  }
   
  // BEGIN CUT HERE
public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"35",
                                        "44"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-12, 20 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, getMinMax(Arg0)); }
	void test_case_1() { string Arr0[] = {"00200",
                                        "0B000",
                                        "00020",
                                        "10000",
                                        "00001"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-8, 0 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, getMinMax(Arg0)); }
	void test_case_2() { string Arr0[] = {"12A",
                                        "A12",
                                        "2A1"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-1, 8 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, getMinMax(Arg0)); }
	void test_case_3() { string Arr0[] = {"AAAA",
                                        "BBBB",
                                        "CCCC",
                                        "DDDD"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-24, 24 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, getMinMax(Arg0)); }

  // END CUT HERE

};
// BEGIN CUT HERE
int main() {
TVGameWinnings ___test;
___test.run_test(-1);
}
// END CUT HERE 
