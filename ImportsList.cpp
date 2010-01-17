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
class ImportsList {
public:
  vector <int> importsCount(vector <string> requires) {
    vector <int> ret(requires.size(), 0);
    vector <string> result = requires;
    int n = requires.size();

    for (int i=0; i<n; i++)
      for (int j=0; j<n; j++)
        for (int k=0; k<n; k++)
          if (requires[i][k] == 'Y' && requires[k][j] == 'Y')
            result[i][j] = 'N';

    for (int i=0; i<n; i++)
      for (int j=0; j<n; j++)
        if (result[i][j] == 'Y')
          ret[i]++;

    return ret;
  }
   
  // BEGIN CUT HERE
public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"NNN"
                                        ,"NNN"
                                        ,"NNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 0, 0 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, importsCount(Arg0)); }
	void test_case_1() { string Arr0[] = {"NYYY"
                                        ,"NNYY"
                                        ,"NNNY"
                                        ,"NNNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 1, 1, 0 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, importsCount(Arg0)); }
	void test_case_2() { string Arr0[] = {"NNNNY"
                                        ,"NNNNY"
                                        ,"YNNNY"
                                        ,"NNNNN"
                                        ,"NNNNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 1, 1, 0, 0 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, importsCount(Arg0)); }
	void test_case_3() { string Arr0[] = {"NYYNYNYYYNYYNYNN"
                                        ,"NNNNNNNNNNNNNNNN"
                                        ,"NNNNNNNNNNYNNNNN"
                                        ,"NNNNNNNNNYNNYNNN"
                                        ,"NYNNNNYNNNYYNNNN"
                                        ,"NYNNYNYNYNYYNNNN"
                                        ,"NNNNNNNNNNYNNNNN"
                                        ,"NNYNNNYNYNYNNNNN"
                                        ,"NNNNNNYNNNYNNNNN"
                                        ,"NNNNNNNNNNNNYNNN"
                                        ,"NNNNNNNNNNNNNNNN"
                                        ,"NNNNNNNNNNNNNNNN"
                                        ,"NNNNNNNNNNNNNNNN"
                                        ,"NNNNNNYNNNYNNNNN"
                                        ,"YYYYYNYYYYYYYYNY"
                                        ,"NYYYNNYNNYYNYYNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {3, 0, 1, 1, 3, 2, 1, 2, 1, 1, 0, 0, 0, 1, 2, 4 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, importsCount(Arg0)); }

  // END CUT HERE

};
// BEGIN CUT HERE
int main() {
ImportsList ___test;
___test.run_test(-1);
}
// END CUT HERE 
