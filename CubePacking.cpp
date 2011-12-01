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
#include <numeric>
// BEGIN CUT HERE
#include "cout.hpp"
// END CUT HERE
using namespace std;
class CubePacking {
  public:
  int getMinimumVolume(int Ns, int Nb, int L) {
    int ret;
    vector <int> seq;
    int b_capacity = L*L*L * Nb;
    int s_b_capacity = b_capacity + Ns;
    int maxim_cube = 0;
    int edge = 0;
    int i, n = 1000;

    for (i=1; i<=n; i++)
        seq.push_back(i*i*i);

    for (i=0; i<n; i++) {
        if (seq[i] - b_capacity >= Ns) {
            maxim_cube = seq[i] * seq[i] * seq[i];
            edge = i + 1;
            break;
        }
    }

    cout << edge << endl;
    if (maxim_cube - s_b_capacity >= edge*edge + edge*(edge-1))
        ret = edge * (edge-1) * (edge-1);
    else if (maxim_cube - s_b_capacity >= edge*edge)
        ret = edge * edge * (edge-1);
    else
        ret = edge * edge * edge;

    return ret;
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { 
	if ((Case == -1) || (Case == 0)) test_case_0();
	if ((Case == -1) || (Case == 1)) test_case_1();
	if ((Case == -1) || (Case == 2)) test_case_2();
	if ((Case == -1) || (Case == 3)) test_case_3();
	if ((Case == -1) || (Case == 4)) test_case_4();
	if ((Case == -1) || (Case == 5)) test_case_5();
}
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { 
	int Arg0 = 2; 
	int Arg1 = 2; 
	int Arg2 = 2; 
	int Arg3 = 20; 
	verify_case(0, Arg3, getMinimumVolume(Arg0, Arg1, Arg2)); }
	void test_case_1() { 
	int Arg0 = 19; 
	int Arg1 = 1; 
	int Arg2 = 2; 
	int Arg3 = 27; 
	verify_case(1, Arg3, getMinimumVolume(Arg0, Arg1, Arg2)); }
	void test_case_2() { 
	int Arg0 = 51; 
	int Arg1 = 7; 
	int Arg2 = 5; 
	int Arg3 = 950; 
	verify_case(2, Arg3, getMinimumVolume(Arg0, Arg1, Arg2)); }
	void test_case_3() { 
	int Arg0 = 12345; 
	int Arg1 = 987; 
	int Arg2 = 10; 
	int Arg3 = 999400; 
	verify_case(3, Arg3, getMinimumVolume(Arg0, Arg1, Arg2)); }
	void test_case_4() { 
	int Arg0 = 2; 
	int Arg1 = 2; 
	int Arg2 = 2; 
	int Arg3 = 20; 
	verify_case(4, Arg3, getMinimumVolume(Arg0, Arg1, Arg2)); }
	void test_case_5() { 
	int Arg0 = 1; 
	int Arg1 = 1; 
	int Arg2 = 2; 
	int Arg3 = 12; 
	verify_case(5, Arg3, getMinimumVolume(Arg0, Arg1, Arg2)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
CubePacking ___test;
___test.run_test(-1);
}
// END CUT HERE 
