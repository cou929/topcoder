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

class MovingAverages {
   public:
   vector <int> calculate(vector <string> times, int n)
  {
    int i, j;
    vector <int> secs;
    vector <int> ret;

    for (i=0; i<times.size(); i++)
      secs.push_back((((times[i][0]-'0')*10+(times[i][1]-'0'))*60*60) + (((times[i][3]-'0')*10+(times[i][4]-'0'))*60) + ((times[i][6]-'0')*10+(times[i][7]-'0')));
    
    for (i=0; i<=times.size()-n; i++)
      {
	int sum = 0;
	for (j=0; j<n; j++)
	  sum += secs[i+j];
	ret.push_back(sum/n);
      }
    return ret;
   }

   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"01:19:10", "01:17:40", "01:19:44", "01:17:23", "01:17:07"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arr2[] = { 4731,  4695,  4684 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, calculate(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"01:19:10", "01:17:40", "01:19:44", "01:17:23", "01:17:07"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arr2[] = { 4750,  4660,  4784,  4643,  4627 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, calculate(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"01:19:10", "01:17:40", "01:19:44", "01:17:23", "01:17:07"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; int Arr2[] = { 4692 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(2, Arg2, calculate(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
MovingAverages ___test;
___test.run_test(-1);
}
// END CUT HERE 
