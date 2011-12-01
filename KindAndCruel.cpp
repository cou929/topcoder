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
class KindAndCruel {
  public:
  int crossTheField(string field, int K, int C) {
    int ret = -1;
    stack <pair <int, int> > s;
    int i = 0;
    int duration = max(K, C);
    bool isClear = false;

    for (i=duration - 1; i>=0; i--)
        s.push(make_pair(0, 0 + i));

    while (!s.empty()) {
        pair <int, int> cur = s.top();
        s.pop();
        int pos = cur.first, time = cur.second;

        stack <pair <int, int> > tmp = s;
        int out = 0;
        while (!tmp.empty()) {
            out++;
            tmp.pop();
        }
        //        cout << out << endl;

        //        cout << pos << " " << time << endl;
        if (pos == field.size() - 1) {
            isClear = true;
            ret = time;
            break;
        }

        pos++, time++;

        bool isOk = true;
        while (field[pos] != '.') {
            if (field[pos] == 'K' && time % K == 0) {
                isOk = false;
                break;
            } else if (field[pos] == 'C' && time % C != 0) {
                isOk = false;
                break;
            }
            pos++, time++;
        }

        while (1) {
            if (field[pos + 1] == '.')
                pos++, time++;
            else
                break;
        }

        if (isOk) {
            for (i=duration - 1; i>=0; i--)
                s.push(make_pair(pos, time + i));
        }
    }

    if (!isClear)
        ret = -1;

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
	string Arg0 = ".................................................."; 
	int Arg1 = 2; 
	int Arg2 = 50; 
	int Arg3 = 49; 
	verify_case(0, Arg3, crossTheField(Arg0, Arg1, Arg2)); }
	void test_case_1() { 
	string Arg0 = ".K.C."; 
	int Arg1 = 3; 
	int Arg2 = 4; 
	int Arg3 = 5; 
	verify_case(1, Arg3, crossTheField(Arg0, Arg1, Arg2)); }
	void test_case_2() { 
	string Arg0 = ".CCCC."; 
	int Arg1 = 3; 
	int Arg2 = 5; 
	int Arg3 = -1; 
	verify_case(2, Arg3, crossTheField(Arg0, Arg1, Arg2)); }
	void test_case_3() { 
	string Arg0 = ".CKKKKCKKKKC.KKKKCKKKKC.CKKKKCKKKKCKKKKCKKKKCKKKK."; 
	int Arg1 = 5; 
	int Arg2 = 5; 
	int Arg3 = 60; 
	verify_case(3, Arg3, crossTheField(Arg0, Arg1, Arg2)); }
	void test_case_4() { 
	string Arg0 = ".CCCCCCCCCCCCCCCC."; 
	int Arg1 = 1; 
	int Arg2 = 1; 
	int Arg3 = 17; 
	verify_case(4, Arg3, crossTheField(Arg0, Arg1, Arg2)); }

	void test_case_5() { 
      string Arg0 = "..........................................CC.";
	int Arg1 = 50; 
	int Arg2 = 50; 
	int Arg3 = -1; 
	verify_case(5, Arg3, crossTheField(Arg0, Arg1, Arg2)); }

	void test_case_6() { 
	string Arg0 = "......KK...K.K.....K."; 
	int Arg1 = 1; 
	int Arg2 = 1; 
	int Arg3 = -1; 
	verify_case(6, Arg3, crossTheField(Arg0, Arg1, Arg2)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
KindAndCruel ___test;
___test.run_test(-1);
}
// END CUT HERE 
