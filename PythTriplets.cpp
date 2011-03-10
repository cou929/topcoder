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
class PythTriplets {
public:
  long gcd(const long _a, const long _b) {
    long a = max(_a, _b);
    long b = min(_a, _b);

    while (b) {
      long tmp = a % b;
      a = b;
      b = tmp;
    }

    return a;
  }

  bool ok(long a, long b) {
    long long n = a*a + b*b;
    return (sqrt(n) - (int)sqrt(n) == 0);
  }

  int toInt(string s) {int r = 0; istringstream ss(s); ss >> r; return r;}

  vector <int> split(const string _s, const string del) {
    vector <int> ret;
    string s = _s;

    while (!s.empty())
      {
        size_t pos = s.find(del);
        string sub = "";
        sub = s.substr(0, pos);
        ret.push_back(toInt(sub));
        if (pos != string::npos)
          pos += del.size();
        s.erase(0, pos);
      }

    return ret;
  }

  int findMax(vector <string> _stick) {
    int ret = 0;
    set <pair <int, int> > pairs;
    int i, j;
    string s;
    vector <int> stick;
    
    for (i=0; i<_stick.size(); i++)
      s += _stick[i];

    stick = split(s, " ");

    sort(stick.begin(), stick.end());

    for (i=0; i<stick.size(); i++)
      for (j=i+1; j<stick.size(); j++)
        if (gcd(stick[i], stick[j]) == 1 && ok(stick[i], stick[j]))
          pairs.insert(make_pair(stick[i], stick[j]));


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
  }
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { 
    string Arr0[] = {"3 4 4 3 11 5 12 9 4"}; 
    vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
    int Arg1 = 3; 
    verify_case(0, Arg1, findMax(Arg0)); }
	void test_case_1() { 
    string Arr0[] = {"20 21 3021 220"}; 
    vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
    int Arg1 = 2; 
    verify_case(1, Arg1, findMax(Arg0)); }
	void test_case_2() { 
    string Arr0[] = {"28 19", "5 1035 21412 37995"}; 
    vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
    int Arg1 = 2; 
    verify_case(2, Arg1, findMax(Arg0)); }
	void test_case_3() { 
    string Arr0[] = {"112 3449 848239 139322 12 38 940 8",
                     "112 3449 848239 139322 12 38 940 8",
                     "112 3449 848239 139322 12 38 940 8",
                     "112 3449 848239 139322 12 38 940 8",
                     "112 3449 848239 139322 12 38 940 8",
                     "112 3449 848239 139322 12 38 940 8",
                     "112 3449 848239 139322 12 38 940 8",
                     "112 3449 848239 139322 12 38 940 8",
                     "112 3449 848239 139322 12 38 940 8",
                     "112 3449 848239 139322 12 38 940 8",
                     "112 3449 848239 139322 12 38 940 8",
                     "112 3449 848239 139322 12 38 940 8",
                     "112 3449 848239 139322 12 38 940 8",
                     "112 3449 848239 139322 12 38 940 8",
                     "112 3449 848239 139322 12 38 940 8",
                     "112 3449 848239 139322 12 38 940 8",
                     "112 3449 848239 139322 12 38 940 8",
                     "112 3449 848239 139322 12 38 940 8",
                     "112 3449 848239 139322 12 38 940 8",
                     "112 3449 848239 139322 12 38 940 8",
                     "112 3449 848239 139322 12 38 940 8",
                     "112 3449 848239 139322 12 38 940 8",
                     "112 3449 848239 139322 12 38 940 8",
                     "112 3449 848239 139322 12 38 940 8",
                     "112 3449 848239 139322 12 38 940 8"
    }; 
    vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
    int Arg1 = 3; 
    verify_case(3, Arg1, findMax(Arg0)); }
	void test_case_4() { 
    string Arr0[] = {"3 4 4 3 11 5 12 9 4"}; 
    vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
    int Arg1 = 3; 
    verify_case(4, Arg1, findMax(Arg0)); }

  // END CUT HERE

};
// BEGIN CUT HERE
int main() {
PythTriplets ___test;
___test.run_test(-1);
}
// END CUT HERE 
