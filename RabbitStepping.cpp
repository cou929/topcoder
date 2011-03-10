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
class RabbitStepping {
public:
  string field;

  int calc(vector <int> &_rabbits) {
    vector <int> rabbits = _rabbits;
    int ret = 0;
    int i, j;
    int n = field.size();
    string f = field;
    vector <int> before(n, -1);

    for (i=0; i<n-2; i++) {
      vector <int> tmp = rabbits;
      vector <int> tmp_before(n, -1);

      for (j=0; j<f.size(); j++) {
        if (rabbits[j] == 1) {
          if (j == 0) {
            tmp[j]--;
            tmp[j+1]++;
            tmp_before[j+1] = j;
          } else if (j >= f.size() - 2) {
            tmp[j]--;
            tmp[j-1]++;
            tmp_before[j-1] = j;
          } else {
            if (f[j] == 'W') {
              tmp[j]--;
              tmp[j-1]++;
              tmp_before[j-1] = j;
            } else if (f[j] == 'B') {
              tmp[j]--;
              tmp[j+1]++;
              tmp_before[j+1] = j;
            } else if (f[j] == 'R') {
              if (i == 0) {
                tmp[j]--;
                tmp[j-1]++;
                tmp_before[j-1] = j;
              } else {
                tmp[j]--;
                tmp[before[j]]++;
                tmp_before[before[j]] = j;
              }
            }
          }
        }
      }

      for (j=0; j<f.size(); j++)
        if (tmp[j] > 1) {
          tmp[j] = 0;
          tmp_before[j] = -1;
        }
      rabbits = tmp;
      before = tmp_before;

      f = f.substr(0, f.size()- 1);
    }

    for (i=0; i<rabbits.size(); i++)
      ret += rabbits[i];

    return ret;
  }

//   int traverse(vector <int> &rabbits, int pos) {
//     if (pos > rabbits.size())
//       return 0;

//     if (count(rabbits.begin(), rabbits.end(), 1) == r) {
//       rabbitnum += calc(rabbits);
//       counter++;
//       return 0;
//     }

//     rabbits[pos] = 1;
//     traverse(rabbits, pos + 1);
//     rabbits[pos] = 0;
//     traverse(rabbits, pos + 1);

//     return 0;
//   }

  double getExpected(string _field, int r) {
    field = _field;
    int counter = 0, rabbitnum = 0;
    vector <int> v(field.size(), 1);
    int i;

    for (i=0; i<field.size()-r; i++)
      v[i] = 0;

    do {
      counter++;
      rabbitnum += calc(v);
    } while (next_permutation(v.begin(), v.end()));

    return (double)rabbitnum / (double)counter;
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
  }
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { 
    string Arg0 = "WRBRW"; 
    int Arg1 = 4; 
    double Arg2 = 0.8; 
    verify_case(0, Arg2, getExpected(Arg0, Arg1)); }
	void test_case_1() { 
    string Arg0 = "WWB"; 
    int Arg1 = 2; 
    double Arg2 = 1.3333333333333333; 
    verify_case(1, Arg2, getExpected(Arg0, Arg1)); }
	void test_case_2() { 
    string Arg0 = "WW"; 
    int Arg1 = 1; 
    double Arg2 = 1.0; 
    verify_case(2, Arg2, getExpected(Arg0, Arg1)); }
	void test_case_3() { 
    string Arg0 = "BBBBBBBBBB"; 
    int Arg1 = 4; 
    double Arg2 = 0.9523809523809523; 
    verify_case(3, Arg2, getExpected(Arg0, Arg1)); }
	void test_case_4() { 
    string Arg0 = "RRBRRWRRBRRW"; 
    int Arg1 = 8; 
    double Arg2 = 0.9696969696969697; 
    verify_case(4, Arg2, getExpected(Arg0, Arg1)); }
	void test_case_5() { 
    string Arg0 = "WRBRWWRBRWWRBRWRR"; 
    int Arg1 = 9; 
    double Arg2 = 0; 
    verify_case(5, Arg2, getExpected(Arg0, Arg1)); }
	void test_case_6() { 
    string Arg0 = "WWWWWWWWWWWWWWWW"; 
    int Arg1 = 8; 
    double Arg2 = 0; 
    verify_case(6, Arg2, getExpected(Arg0, Arg1)); }

  // END CUT HERE

};
// BEGIN CUT HERE
int main() {
RabbitStepping ___test;
___test.run_test(-1);
}
// END CUT HERE 
