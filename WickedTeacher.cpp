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
using namespace std;
class WickedTeacher {
public:
  double toDouble(string s) {double r = 0; istringstream ss(s); ss >> r; return r;}
  string toStr(int n) {ostringstream ss; ss << n; return ss.str();}
  string toStrd(double n) {ostringstream ss; ss << n; return ss.str();}

  long long factorial(int n)
  {
    int i;
    long long ret = 1;

    for (i=1; i<=n; i++)
      ret *= i;

    return ret;
  }

  long long gcd(long long _a, long long _b)
  {
    long long a = max(_a, _b);
    long long b = min(_a, _b);

    while (b)
      {
	long long tmp = a % b;
	a = b;
	b = tmp;
      }

    return a;
  }

  bool dividable(string s, int K)
  {
    double num = toDouble(s);
    num /= (double)K;
    string tmp = toStrd(num);
    cout << tmp << endl;

    for (int i=0; i<tmp.size(); i++)
      if (tmp[i] == '.')
	return false;
    
    return true;
  }

  string cheatProbability(vector <string> numbers, int K)
  {
    long long deno = factorial(numbers.size());
    long long nume = 0;
    long long ftmp = factorial(numbers.size()-1);

    for (int i=0; i<numbers.size(); i++)
      if (dividable(numbers[i], K))
	nume += ftmp;
   
    long long g = gcd(deno, nume);
    deno /= g;
    nume /= g;

    return toStr(nume) + "/" + toStr(deno);
  }
   
  // BEGIN CUT HERE
public:
  void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
private:
  template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
  void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
  void test_case_0() { string Arr0[] = {"3","2","1"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; string Arg2 = "1/3"; verify_case(0, Arg2, cheatProbability(Arg0, Arg1)); }
  void test_case_1() { string Arr0[] = {"10","100","1000","10000","100000"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; string Arg2 = "1/1"; verify_case(1, Arg2, cheatProbability(Arg0, Arg1)); }
  void test_case_2() { string Arr0[] = {"11","101","1001","10001","100001"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; string Arg2 = "0/1"; verify_case(2, Arg2, cheatProbability(Arg0, Arg1)); }
  void test_case_3() { string Arr0[] = {"13","10129414190271203","102","102666818896","1216","1217","1218","101278001","1000021412678412681"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 21; string Arg2 = "5183/36288"; verify_case(3, Arg2, cheatProbability(Arg0, Arg1)); }

  // END CUT HERE

};
// BEGIN CUT HERE
int main() {
WickedTeacher ___test;
___test.run_test(-1);
}
// END CUT HERE 
