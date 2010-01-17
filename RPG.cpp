// BEGIN CUT HERE
// END CUT HERE
#include <sstream>
#include <string>
#include <vector>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>

using namespace std;

class RPG {
   public:
   vector <int> dieRolls(vector <string> dice)
  {
    unsigned int i;
    int vals[dice.size()][2];
    int min=0;
    int max=0;
    double avg=0;
    vector <int> ret(3);

    for(i=0; i<dice.size(); i++)
      sscanf(dice[i].c_str(), "%dd%d", &vals[i][0], &vals[i][1]);


    for(i=0; i<dice.size(); i++)
      {
	min += vals[i][0];
	max += vals[i][0] * vals[i][1];
	avg += (double)vals[i][0] * ((double)vals[i][1]+1.0) / 2.0;
      }

    ret[0] = min;
    ret[1] = max;
    ret[2] = (int)avg;
    return ret;
   }

   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"3d6"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 3,  18,  10 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, dieRolls(Arg0)); }
	void test_case_1() { string Arr0[] = {"3d4","1d6"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 4,  18,  11 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, dieRolls(Arg0)); }
	void test_case_2() { string Arr0[] = {"6d5","10d10","10d20"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 26,  330,  178 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, dieRolls(Arg0)); }
	void test_case_3() { string Arr0[] = {"1d2","2d2","4d2","6d2","8d2"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 21,  42,  31 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, dieRolls(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
RPG ___test;
___test.run_test(-1);
}
// END CUT HERE
