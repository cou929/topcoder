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

using namespace std;

class HappyCells {
   public:
  vector <string> _grid;

  bool check(int i, int j)
  {
    if (i >= 0 && j >= 0 && i < _grid.size() && j < _grid[0].size() && _grid[i][j] == '.')
	return true;
    return false;
  }

   vector <int> getHappy(vector <string> grid)
  {
    _grid = grid;
    int i, j;
    vector <int> ret;
    ret.push_back(0); ret.push_back(0); ret.push_back(0);

    for (i=0; i<grid.size(); i++)
      for (j=0; j<grid[i].size(); j++)
	{
	  if (grid[i][j] == '.')
	    {
	      int orth = 0;
	      int diag = 0;

	      if (check(i-1, j) || check(i+1, j) || check(i, j-1) || check(i, j+1))
		orth = 1;
	      if (check(i-1, j-1) || check(i+1, j-1) || check(i-1, j+1) || check(i+1, j+1))
		diag = 1;

	      if (orth == 0 && diag == 0)
		ret[0]++;
	      if (orth == 0 && diag == 1)
		ret[1]++;
	      if (orth == 1 && diag == 0)
		ret[2]++;
	    }
	}

    return ret;
   }

   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {
"XXX",
"X.X",
"XXX"
}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 0, 0 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, getHappy(Arg0)); }
	void test_case_1() { string Arr0[] = {"."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 0, 0 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, getHappy(Arg0)); }
	void test_case_2() { string Arr0[] = {
"XXXXXX",
"X.XXXX",
"XXX.XX",
"X..XXX",
"XXXXXX"
}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 1, 1 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, getHappy(Arg0)); }
	void test_case_3() { string Arr0[] = {"..."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 0, 3 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, getHappy(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
HappyCells ___test;
___test.run_test(-1);
}
// END CUT HERE 
