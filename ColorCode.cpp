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

class ColorCode {
   public:
   long long getOhms(vector <string> code)
  {
    int i;
    map <string, int> color;
    long long ret;

    color["black"] = 0;
    color["brown"] = 1;
    color["red"] = 2;
    color["orange"] = 3;
    color["yellow"] = 4;
    color["green"] = 5;
    color["blue"] = 6;
    color["violet"] = 7;
    color["grey"] = 8;
    color["white"] = 9;

    ret = 10 * color[code[0]];
    ret += color[code[1]];
    for (i=0; i<color[code[2]]; i++)
      ret *= 10;

    return ret;
   }

   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = { "yellow", "violet", "red" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 4700LL; verify_case(0, Arg1, getOhms(Arg0)); }
	void test_case_1() { string Arr0[] = { "orange", "red", "blue" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 32000000LL; verify_case(1, Arg1, getOhms(Arg0)); }
	void test_case_2() { string Arr0[] = { "white", "white", "white" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 99000000000LL; verify_case(2, Arg1, getOhms(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
ColorCode ___test;
___test.run_test(-1);
}
// END CUT HERE 
