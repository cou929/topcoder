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
class DivisorInc {
public:
  int countOperations(int N, int M)
  {
    int ret = -1;
    queue <int> q;
    int t[100001];
    memset(t, -1, sizeof(t));
    t[N] = 0;

    q.push(N);

    while (!q.empty())
      {
	int cur = q.front();
	q.pop();
  
	if(cur == M)
	  {
	    ret = t[cur];
	    break;
	  }

	for (int i=2; i*i<=cur; i++)
	  if (cur % i == 0)
	    {
	      if (cur + i <= M && t[cur + i] == -1)
		{
		  t[cur + i] = t[cur] + 1;
		  q.push(cur + i);
		}
	      if (cur + cur / i <= M && t[cur + cur / i] == -1)
		{
		  t[cur + cur / i] = t[cur] + 1;
		  q.push(cur + cur / i);
		}
	    }
      }

    return ret;
  }
   
  // BEGIN CUT HERE
public:
  void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
private:
  template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
  void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
  void test_case_0() { int Arg0 = 4; int Arg1 = 24; int Arg2 = 5; verify_case(0, Arg2, countOperations(Arg0, Arg1)); }
  void test_case_1() { int Arg0 = 4; int Arg1 = 576; int Arg2 = 14; verify_case(1, Arg2, countOperations(Arg0, Arg1)); }
  void test_case_2() { int Arg0 = 8748; int Arg1 = 83462; int Arg2 = 10; verify_case(2, Arg2, countOperations(Arg0, Arg1)); }
  void test_case_3() { int Arg0 = 235; int Arg1 = 98234; int Arg2 = 21; verify_case(3, Arg2, countOperations(Arg0, Arg1)); }
  void test_case_4() { int Arg0 = 4; int Arg1 = 99991; int Arg2 = -1; verify_case(4, Arg2, countOperations(Arg0, Arg1)); }
  void test_case_5() { int Arg0 = 82736; int Arg1 = 82736; int Arg2 = 0; verify_case(5, Arg2, countOperations(Arg0, Arg1)); }

  // END CUT HERE

};
// BEGIN CUT HERE
int main() {
DivisorInc ___test;
___test.run_test(-1);
}
// END CUT HERE 
