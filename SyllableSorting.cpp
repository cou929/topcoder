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
class SyllableSorting {
   public:
   vector <string> sortWords(vector <string> words) {
      vector <string> ret;

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
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { 
	string Arr0[] = {"xiaoxiao", "yamagawa", "gawayama"}; 
	vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
	string Arr1[] = {"gawayama", "yamagawa", "xiaoxiao" }; 
	vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); 
	verify_case(0, Arg1, sortWords(Arg0)); }
	void test_case_1() { 
	string Arr0[] = {"bcedba", "dbabce", "zyuxxo"}; 
	vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
	string Arr1[] = {"bcedba", "dbabce", "zyuxxo" }; 
	vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); 
	verify_case(1, Arg1, sortWords(Arg0)); }
	void test_case_2() { 
	string Arr0[] = {"hgnibqqaxeiuteuuvksi", "jxbuzui", "zrotyqeruiydozui",
 "ywuuzkto", "lmopbookoagyco", "vredfvavvexliu"}; 
	vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
	string Arr1[] = {"hgnibqqaxeiuteuuvksi", "vredfvavvexliu", "lmopbookoagyco", "jxbuzui", "zrotyqeruiydozui", "ywuuzkto" }; 
	vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); 
	verify_case(2, Arg1, sortWords(Arg0)); }
	void test_case_3() { 
	string Arr0[] = {"crazgo", "cwsoygiokiuo", "yueoseeu", "tuadiojvugeoe",
 "naumxditui", "sgukkelyoi", "nrohjuasoia", "mgabmo"}; 
	vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
	string Arr1[] = {"mgabmo", "crazgo", "cwsoygiokiuo", "tuadiojvugeoe", "nrohjuasoia", "sgukkelyoi", "naumxditui", "yueoseeu" }; 
	vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); 
	verify_case(3, Arg1, sortWords(Arg0)); }
	void test_case_4() { 
	string Arr0[] = {"wheewjuguoi", "coutcu", "hqivaa", "sgiibgwi", "ypaqpki",
 "bgyikouapae", "wqakeu", "skolfo", "pzesaa", "ypivhi"}; 
	vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
	string Arr1[] = {"sgiibgwi", "bgyikouapae", "coutcu", "wheewjuguoi", "hqivaa", "wqakeu", "skolfo", "pzesaa", "ypaqpki", "ypivhi" }; 
	vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); 
	verify_case(4, Arg1, sortWords(Arg0)); }
	void test_case_5() { 
	string Arr0[] = {"xiaoxiao", "yamagawa", "gawayama"}; 
	vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
	string Arr1[] = {"gawayama", "yamagawa", "xiaoxiao" }; 
	vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); 
	verify_case(5, Arg1, sortWords(Arg0)); }
	void test_case_6() { 
	string Arr0[] = {"xiaoxiao", "yamagawa", "gawayama"}; 
	vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
	string Arr1[] = {"gawayama", "yamagawa", "xiaoxiao" }; 
	vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); 
	verify_case(6, Arg1, sortWords(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
SyllableSorting ___test;
___test.run_test(-1);
}
// END CUT HERE 
