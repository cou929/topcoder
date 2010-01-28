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
class FindingSquareInTable {
public:
  int findMaximalSquare(vector <string> table) {
    int ret = -1;
    int n = table.size(), m = table[0].size();

    for (int i=0; i<n; i++)
      for (int j=0; j<m; j++)
        for (int k=-9; k<10; k++)
          for (int l=-9; l<10; l++) {
            if (k == 0 && l == 0) continue;
            int cur = 0;
            int next_x = i, next_y = j;
            while (0 <= next_x && next_x < n && 0 <= next_y && next_y < m) {
              cur = cur * 10 + table[next_x][next_y] - '0';
              int checker = (int)sqrt(cur);
              if (cur == checker * checker) ret = max(ret, cur);
              next_x += k, next_y += l;
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
    if ((Case == -1) || (Case == 6)) test_case_6();
    if ((Case == -1) || (Case == 7)) test_case_7();
  }
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { 
    string Arr0[] = {"123",
                     "456"}; 
    vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
    int Arg1 = 64; 
    verify_case(0, Arg1, findMaximalSquare(Arg0)); }
	void test_case_1() { 
    string Arr0[] = {"00000",
                     "00000",
                     "00200",
                     "00000",
                     "00000"}; 
    vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
    int Arg1 = 0; 
    verify_case(1, Arg1, findMaximalSquare(Arg0)); }
	void test_case_2() { 
    string Arr0[] = {"3791178",
                     "1283252",
                     "4103617",
                     "8233494",
                     "8725572",
                     "2937261"}; 
    vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
    int Arg1 = 320356; 
    verify_case(2, Arg1, findMaximalSquare(Arg0)); }
	void test_case_3() { 
    string Arr0[] = {"135791357",
                     "357913579",
                     "579135791",
                     "791357913",
                     "913579135"}
    ; 
    vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
    int Arg1 = 9; 
    verify_case(3, Arg1, findMaximalSquare(Arg0)); }
	void test_case_4() { 
    string Arr0[] = {"553333733",
                     "775337775",
                     "777537775",
                     "777357333",
                     "755553557",
                     "355533335",
                     "373773573",
                     "337373777",
                     "775557777"}; 
    vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
    int Arg1 = -1; 
    verify_case(4, Arg1, findMaximalSquare(Arg0)); }
	void test_case_5() { 
    string Arr0[] = {"2572402810",
                     "1975108460",
                     "0143454010",
                     "0355625750",
                     "9749356320",
                     "8658659330",
                     "6846849870",
                     "7689346590",
                     "2874938670",
                     "2874938670"}; 
    vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
    int Arg1 = 95481; 
    verify_case(5, Arg1, findMaximalSquare(Arg0)); }
	void test_case_6() { 
    string Arr0[] = {"0160"
    }; 
    vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
    int Arg1 = 16; 
    verify_case(6, Arg1, findMaximalSquare(Arg0)); }
	void test_case_7() { 
    string Arr0[] = {"123",
                     "456"}; 
    vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
    int Arg1 = 64; 
    verify_case(7, Arg1, findMaximalSquare(Arg0)); }

  // END CUT HERE

};
// BEGIN CUT HERE
int main() {
FindingSquareInTable ___test;
___test.run_test(5);
}
// END CUT HERE 
