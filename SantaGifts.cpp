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
class SantaGifts {
public:
  vector <string> distribute(vector <string> gifts, int N)
  {
    vector <string> ret(N);

    int limit = min((int)gifts.size(), N*4);
    for (int i=0; i<limit; i++)
      ret[i % N] += gifts[i] + " ";

    for (int i=0; i<N; i++)
      if (ret[i][ret[i].size()-1] == ' ')
	ret[i].erase(ret[i].end()-1);

    return ret;
  }
  // BEGIN CUT HERE
public:
  void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
private:
  template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
  void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
  void test_case_0() { string Arr0[] = {"ball","plane","robot","puzzle"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; string Arr2[] = {"ball puzzle", "plane", "robot" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, distribute(Arg0, Arg1)); }
  void test_case_1() { string Arr0[] = {"ball","plane","robot","puzzle","bike"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; string Arr2[] = {"ball plane robot puzzle" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, distribute(Arg0, Arg1)); }
  void test_case_2() { string Arr0[] = {"ball","ball","plane","plane"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; string Arr2[] = {"ball plane", "ball plane" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(2, Arg2, distribute(Arg0, Arg1)); }
  void test_case_3() { string Arr0[] = {"ball","plane","robot"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; string Arr2[] = {"ball", "plane", "robot", "", "" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(3, Arg2, distribute(Arg0, Arg1)); }
  void test_case_4() { string Arr0[] = {"ball","plane","robot","kosei","kosei","kosei","kosei","kosei","kosei","kosei","kosei","kosei","kosei","kosei","kosei","kosei","kosei","kosei","kosei","kosei"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; string Arr2[] = {"ball kosei kosei kosei", "plane kosei kosei kosei", "robot kosei kosei kosei"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(4, Arg2, distribute(Arg0, Arg1)); }

  // END CUT HERE
};
// BEGIN CUT HERE
int main() {
SantaGifts ___test;
___test.run_test(-1);
}
// END CUT HERE 
