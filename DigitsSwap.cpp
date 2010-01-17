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

class DigitsSwap {
   public:
   string maximalProduct(string x, string y, int swaps)
  {
    unsigned int i;

   }

   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "123"; string Arg1 = "321"; int Arg2 = 2; string Arg3 = "39483"; verify_case(0, Arg3, maximalProduct(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arg0 = "4531"; string Arg1 = "1332"; int Arg2 = 0; string Arg3 = "6035292"; verify_case(1, Arg3, maximalProduct(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arg0 = "13425"; string Arg1 = "87694"; int Arg2 = 99; string Arg3 = "1476187680"; verify_case(2, Arg3, maximalProduct(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arg0 = "2872876342876443222"; string Arg1 = "2309482482304823423"; int Arg2 = 5; string Arg3 = "6669566046086333877050194232995188906"; verify_case(3, Arg3, maximalProduct(Arg0, Arg1, Arg2)); }
	void test_case_4() { string Arg0 = "940948"; string Arg1 = "124551"; int Arg2 = 4893846; string Arg3 = "133434353148"; verify_case(4, Arg3, maximalProduct(Arg0, Arg1, Arg2)); }
	void test_case_5() { string Arg0 = "56710852"; string Arg1 = "18058360"; int Arg2 = 1; string Arg3 = "1050671725722720"; verify_case(5, Arg3, maximalProduct(Arg0, Arg1, Arg2)); }
	void test_case_6() { string Arg0 = "9"; string Arg1 = "1"; int Arg2 = 1000000000; string Arg3 = "9"; verify_case(6, Arg3, maximalProduct(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
DigitsSwap ___test;
___test.run_test(-1);
}
// END CUT HERE 
