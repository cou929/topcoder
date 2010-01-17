// BEGIN CUT HERE
// END CUT HERE
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>

using namespace std;

class CircularLine {
   public:
   int longestTravel(vector <int> t)
  {
    int i, j, k;
    int large, small;
    int in, out;
    int maxi = 0;

    for (i=0; i<t.size(); i++)
      {
	for (j=0; j<t.size(); j++)
	  {
	    if (i == j)
	      continue;

	    large = max(i, j);
	    small = min(i, j);

	    in = 0;
	    for (k=small; k<large; k++)
	      in += t[k];

	    out = 0;
	    for (k=0; k<t.size(); k++)
	      if (k < small || k >= large)
		out += t[k];

	    if (maxi < min(in, out))
	      maxi = min(in, out);
	  }
      }
    return maxi;
   }

   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1,1,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(0, Arg1, longestTravel(Arg0)); }
	void test_case_1() { int Arr0[] = {1,4,4,1,5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 7; verify_case(1, Arg1, longestTravel(Arg0)); }
	void test_case_2() { int Arr0[] = {1,1,1000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(2, Arg1, longestTravel(Arg0)); }
	void test_case_3() { int Arr0[] = {1,1000,1,1000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1001; verify_case(3, Arg1, longestTravel(Arg0)); }
	void test_case_4() { int Arr0[] = {1,1,1,1,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(4, Arg1, longestTravel(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
CircularLine ___test;
___test.run_test(-1);
}
// END CUT HERE 
