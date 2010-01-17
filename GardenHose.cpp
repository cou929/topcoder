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

class GardenHose {
   public:
   int countDead(int n, int rowDist, int colDist, int hoseDist)
  {
    unsigned int i;
    int distance = 0;
    int ret = 0;

    distance = rowDist * (n + 1);
    distance -= hoseDist * 2;
    ret = (distance / rowDist);

    cout << ret << endl;

    distance = colDist * (n + 1);
    distance -= hoseDist * 2;
    ret *= (distance / colDist) - 1;

    return (ret > 0) ? ret : 0;
   }

   
// Begin CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 2; int Arg2 = 1; int Arg3 = 2; int Arg4 = 0; verify_case(0, Arg4, countDead(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 2; int Arg2 = 1; int Arg3 = 1; int Arg4 = 3; verify_case(1, Arg4, countDead(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 6; int Arg1 = 2; int Arg2 = 5; int Arg3 = 5; int Arg4 = 8; verify_case(2, Arg4, countDead(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 6; int Arg1 = 2; int Arg2 = 5; int Arg3 = 3; int Arg4 = 24; verify_case(3, Arg4, countDead(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arg0 = 50; int Arg1 = 50; int Arg2 = 50; int Arg3 = 49; int Arg4 = 2500; verify_case(4, Arg4, countDead(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
GardenHose ___test;
___test.run_test(-1);
}
// END CUT HERE 
