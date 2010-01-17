#include <string>
#include <vector>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>

using namespace std;

class ParallelSpeedup {
public:
  int numProcessors(int k, int overhead)
  {
    int i;
    int time = k;
    int t;
    int ret = 1;
    
    for(i=2; i<k; i++)
      {
	cout << i << " ";
	t = factorial(i)/(2*factorial(i-2))*overhead + k/i;
	if(t < time)
	  {
	    cout << t << endl;
	    time = t;
	    ret = i;
	  }
	else if(t >= k)
	  break;
      }
    return ret;
  }

  int factorial(int n)
  {
    int i;
    int ret = 1;

    for(i=2; i<=n; i++)
      ret *= i;

    return ret;
  }

	
  // BEGIN CUT HERE
public:
  void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
private:
  template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
  void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
  void test_case_0() { int Arg0 = 12; int Arg1 = 1; int Arg2 = 2; verify_case(0, Arg2, numProcessors(Arg0, Arg1)); }
  void test_case_1() { int Arg0 = 50; int Arg1 = 3; int Arg2 = 3; verify_case(1, Arg2, numProcessors(Arg0, Arg1)); }
  void test_case_2() { int Arg0 = 9; int Arg1 = 10; int Arg2 = 1; verify_case(2, Arg2, numProcessors(Arg0, Arg1)); }
  void test_case_3() { int Arg0 = 3333; int Arg1 = 2; int Arg2 = 12; verify_case(3, Arg2, numProcessors(Arg0, Arg1)); }
  void test_case_4() { int Arg0 = 1000000; int Arg1 = 4; int Arg2 = 63; verify_case(4, Arg2, numProcessors(Arg0, Arg1)); }

  // END CUT HERE


};

  // BEGIN CUT HERE
  int main() {
    ParallelSpeedup ___test;
    ___test.run_test(-1);
  }
  // END CUT HERE
