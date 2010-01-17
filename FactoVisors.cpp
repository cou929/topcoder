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

using namespace std;

class FactoVisors {
   public:

  long long gcd(long long a, long long b)
  {

    while (b)
      {
	long long tmp = b;
	b = a % b;
	a = tmp;
      }

    return a;
  }

  int gcd(int a, int b)
  {

    while (b)
      {
	int tmp = a % b;
	a = b;
	b = tmp;
      }

    return a;
  }

  long long lcm(long long a, long long b)
  {
    return a*b / gcd(a, b);
  }

  int lcm(int a, int b)
  {
    return a*b / gcd(a, b);
  }

  int getNum(vector <int> divisors, vector <int> multiples)
  {
    int i;
    long long div = 0;
    long long mul = 0;
    int counter = 0;

    if (divisors.size() > 1)
      {
	div = lcm(max(divisors[0], divisors[1]), min(divisors[0], divisors[1]));
	for (i=2; i<divisors.size(); i++)
	  div = lcm(max((long long)divisors[i], div), min((long long)divisors[i], div));
      }
    else
      div = divisors[0];

    if (multiples.size() > 1)
      {
	mul = gcd(max(multiples[0], multiples[1]), min(multiples[0], multiples[1]));
	for (i=2; i<multiples.size(); i++)
	  mul = gcd(max((long long)multiples[i], mul), min((long long)multiples[i], mul));
      }
    else
      mul = multiples[0];

    cout << div << " " << mul << endl;

    for (i=div; i<=mul; i+=div)
      if (mul % i == 0)
	counter++;

    return counter;
  }  

   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {100}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 9; verify_case(0, Arg2, getNum(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {6,9}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {18}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; verify_case(1, Arg2, getNum(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {6,9}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {96,180}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; verify_case(2, Arg2, getNum(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {2,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {256}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 7; verify_case(3, Arg2, getNum(Arg0, Arg1)); }
  void test_case_4() { int Arr0[] = {19088, 5754076, 6029, 12058, 96464, 24116, 19088, 48232, 8}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {920652416, 34244656, 460326208, 230163104, 690489312, 575407760, 690489312, 805570864, 230163104, 345244656, 460326208}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; verify_case(4, Arg2, getNum(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
FactoVisors ___test;
___test.run_test(-1);
}
// END CUT HERE 
