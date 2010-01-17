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

class ProgressBar {
   public:
   string showProgress(vector <int> taskTimes, int tasksCompleted)
  {
    int i;
    int total = 0;
    int comp = 0;
    int sharps;
    string ret;

    for(i=0; i<taskTimes.size(); i++)
      {
	if(i < tasksCompleted)
	  comp += taskTimes[i];

	total += taskTimes[i];
      }

    sharps = (int)((double)comp / (double)total * 20.0);

    for(i=0; i<sharps; i++)
      ret.push_back('#');

    for(i=0; i<20-sharps; i++)
      ret.push_back('.');

    return ret;
   }

   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {19,6,23,17}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; string Arg2 = "##############......"; verify_case(0, Arg2, showProgress(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {2,3,7,1,4,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; string Arg2 = "#############......."; verify_case(1, Arg2, showProgress(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {553,846,816,203,101,120,161,818,315,772}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; string Arg2 = "##########.........."; verify_case(2, Arg2, showProgress(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {7,60,468,489,707,499,350,998,1000,716,457,104,597,583,396,862}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; string Arg2 = "...................."; verify_case(3, Arg2, showProgress(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {419,337,853,513,632,861,336,594,94,367,336,297,966,627,399,433,846,859,80,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 19; string Arg2 = "###################."; verify_case(4, Arg2, showProgress(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
ProgressBar ___test;
___test.run_test(-1);
}
// END CUT HERE
