// BEGIN CUT HERE
// END CUT HERE
#include <sstream>
#include <string>
#include <vector>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>

using namespace std;

class SkipRope {
   public:
   vector <int> partners(vector <int> candidates, int height)
  {
    unsigned int i;
    vector <int> heightAbs(candidates.size());
    vector <int> ret(2);
    int flg1 = 0, flg2 = 0;
    int tmp;

    for(i=0; i<candidates.size(); i++)
      heightAbs[i] = abs(height - candidates[i]);

    sort(heightAbs.begin(), heightAbs.end());

    for(i=0; i<candidates.size(); i++)
      {
	if(height + heightAbs[0] == candidates[i])
	  flg1 = 1;
	if(height + heightAbs[1] == candidates[i])
	  flg2 = 1;
      }

    if(flg1)
      ret[0] = height + heightAbs[0];
    else
      ret[0] = height - heightAbs[0];

    if(flg2)
      ret[1] = height + heightAbs[1];
    else
      ret[1] = height - heightAbs[1];

    if(ret[0] > ret[1])
      {
	tmp = ret[0];
	ret[0] = ret[1];
	ret[1] = tmp;
      }

    return ret;
   }

   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arr0[] = {102, 99, 104}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 100; int Arr2[] = { 99,  102 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, partners(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {102, 97, 104}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 100; int Arr2[] = { 97,  102 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, partners(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {101, 100, 99}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 100; int Arr2[] = { 100,  101 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(2, Arg2, partners(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {75, 117, 170, 175, 168, 167, 167, 142, 170, 85, 89, 170}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 169; int Arr2[] = { 170,  170 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(3, Arg2, partners(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {134, 79, 164, 86, 131, 78, 99, 150, 105, 163, 150, 110, 90, 137, 127, 130, 121, 
 93, 97, 131, 170, 137, 171, 153, 137, 138, 92, 103, 149, 110, 156}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 82; int Arr2[] = { 79,  86 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(4, Arg2, partners(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
SkipRope ___test;
___test.run_test(-1);
}
// END CUT HERE
