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
using namespace std;
class RoadsAndFools {
public:
  string toStr(int n) {ostringstream ss; ss << n; return ss.str();}

  string determineOrientation(int length, vector <int> frontSides)
  {
    frontSides[0] = min(frontSides[0], length - frontSides[0]);
    for (int i=1; i<frontSides.size(); i++)
      {
	bool ok1 = false, ok2 = false;
	if (frontSides[i-1] < frontSides[i])
	  ok1 = true;
	if (frontSides[i-1] < (length - frontSides[i]))
	  ok2 = true;

	if (ok2)
	  frontSides[i] = length - frontSides[i];

	if (ok1 && ok2)
	  frontSides[i] = min(frontSides[i], length - frontSides[i]);

	if (!ok1 && !ok2)
	  return "NO SOLUTION";
      }

    vector <int> tmp = frontSides;
    tmp.insert(tmp.begin(), -1);
    tmp.push_back(1001);

    for (int i=1; i<tmp.size()-1; i++)
      {
	bool ok1 = false, ok2 = false;
	if (tmp[i-1] < tmp[i] && tmp[i] < tmp[i+1])
	  ok1 = true;
	if (tmp[i-1] < (length - tmp[i]) && (length - tmp[i]) < tmp[i+1])
	  ok2 = true;

	if (ok1 && ok2 && (tmp[i] != length - tmp[i]))
	  return "MULTIPLE SOLUTIONS";
      }

    string ret = "";

    for (int i=0; i<frontSides.size(); i++)
      {
	ret += toStr(frontSides[i]);
	ret += " ";
      }

    ret.erase(ret.end()-1);

    return ret;
  }
   
  // BEGIN CUT HERE
public:
  void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
private:
  template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
  void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
  void test_case_0() { int Arg0 = 5; int Arr1[] = {1, 2, 3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "1 2 3"; verify_case(0, Arg2, determineOrientation(Arg0, Arg1)); }
  void test_case_1() { int Arg0 = 5; int Arr1[] = {5, 2, 0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "MULTIPLE SOLUTIONS"; verify_case(1, Arg2, determineOrientation(Arg0, Arg1)); }
  void test_case_2() { int Arg0 = 5; int Arr1[] = {4, 4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "1 4"; verify_case(2, Arg2, determineOrientation(Arg0, Arg1)); }
  void test_case_3() { int Arg0 = 5; int Arr1[] = {4, 4, 4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "NO SOLUTION"; verify_case(3, Arg2, determineOrientation(Arg0, Arg1)); }
  void test_case_4() { int Arg0 = 5; int Arr1[] = {3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "MULTIPLE SOLUTIONS"; verify_case(4, Arg2, determineOrientation(Arg0, Arg1)); }
  void test_case_5() { int Arg0 = 10; int Arr1[] = {5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "5"; verify_case(5, Arg2, determineOrientation(Arg0, Arg1)); }

  // END CUT HERE

};
// BEGIN CUT HERE
int main() {
RoadsAndFools ___test;
___test.run_test(-1);
}
// END CUT HERE 
