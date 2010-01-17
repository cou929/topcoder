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
class BirthdayCake {
public:
  double combination(int n, int r)
  {
    int i, j;
    double result[r+1], tmp[r+1];

    for (i=0; i<=r; i++)
      {
	result[i] = 0;
	tmp[i] = 0;
      }

    result[0] = 1;

    for (i=1; i<=n; i++)
      {
	tmp[0] = 1;

	for (j=1; j<=r; j++)
	  tmp[j] = result[j-1] + result[j];

	for (j=0; j<=r; j++)
	  result[j] = tmp[j];
      }

    return result[r];
  }

  int howManyFriends(vector <string> availableFruits, vector <string> friendsDislikings, int K)
  {
    for (int i=0; i<=50; i++)
      cout << "50C" << i << " = " << combination(50, i) << endl;

    return 0;
  }
   
  // BEGIN CUT HERE
public:
  void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
private:
  template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
  void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
  void test_case_0() { string Arr0[] = { "apple", "orange", "strawberry", "cherry" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "apple orange", "apple cherry", "strawberry orange", "cherry", "apple" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; int Arg3 = 3; verify_case(0, Arg3, howManyFriends(Arg0, Arg1, Arg2)); }
  void test_case_1() { string Arr0[] = { "strawberry", "orange", "apple", "lemon", "watermelon" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "orange", "apple", "lemon", "watermelon" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; int Arg3 = 4; verify_case(1, Arg3, howManyFriends(Arg0, Arg1, Arg2)); }
  void test_case_2() { string Arr0[] = { "apple", "orange" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "strawberry" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; int Arg3 = 1; verify_case(2, Arg3, howManyFriends(Arg0, Arg1, Arg2)); }

  // END CUT HERE

};
// BEGIN CUT HERE
int main() {
BirthdayCake ___test;
___test.run_test(-1);
}
// END CUT HERE 
