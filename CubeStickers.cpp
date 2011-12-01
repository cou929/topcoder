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
class CubeStickers {
  public:
  string isPossible(vector <string> sticker) {
    string ret = "NO";
    map <string, int> m;
    vector <int> nums;

    for (int i=0; i<sticker.size(); i++)
        m[sticker[i]]++;

    for (map <string, int>::iterator it=m.begin(); it!=m.end(); it++)
        nums.push_back(it->second);

    sort(nums.rbegin(), nums.rend());

    if (nums.size() >= 6 ||
        (nums.size() == 5 && nums[0] >= 2) ||
        (nums.size() == 4 && nums[0] >= 2 && nums[1] >= 2) ||
        (nums.size() == 3 && nums[0] >= 2 && nums[1] >= 2 && nums[2] >= 2))
        ret = "YES";

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
	if ((Case == -1) || (Case == 6)) test_case_6();
}
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { 
	string Arr0[] = {"cyan","magenta","yellow","purple","black","white","purple"}; 
	vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
	string Arg1 = "YES"; 
	verify_case(0, Arg1, isPossible(Arg0)); }
	void test_case_1() { 
	string Arr0[] = {"blue","blue","blue","blue","blue","blue","blue","blue","blue","blue"}; 
	vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
	string Arg1 = "NO"; 
	verify_case(1, Arg1, isPossible(Arg0)); }
	void test_case_2() { 
	string Arr0[] = {"red","yellow","blue","red","yellow","blue","red","yellow","blue"}; 
	vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
	string Arg1 = "YES"; 
	verify_case(2, Arg1, isPossible(Arg0)); }
	void test_case_3() { 
	string Arr0[] = {"purple","orange","orange","purple","black","orange","purple"}; 
	vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
	string Arg1 = "NO"; 
	verify_case(3, Arg1, isPossible(Arg0)); }
	void test_case_4() { 
	string Arr0[] = {"white","gray","green","blue","yellow","red","target","admin"}; 
	vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
	string Arg1 = "YES"; 
	verify_case(4, Arg1, isPossible(Arg0)); }
	void test_case_5() { 
	string Arr0[] = {"cyan","magenta","yellow","purple","black","white","purple"}; 
	vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
	string Arg1 = "YES"; 
	verify_case(5, Arg1, isPossible(Arg0)); }
	void test_case_6() { 
	string Arr0[] = {"cyan","magenta","yellow","purple","black","white","purple"}; 
	vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
	string Arg1 = "YES"; 
	verify_case(6, Arg1, isPossible(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
CubeStickers ___test;
___test.run_test(-1);
}
// END CUT HERE 
