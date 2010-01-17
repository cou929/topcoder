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
class EnemyTowers {
public:
  int getTurn(int units, int hp, int attack, int numt)
  {
    int ret = 0;
    int total = hp * numt;

    while (units > 0 && total > 0)
      {
	ret++;

	total -= units;
	units -= ceil((double)max(0, total) / hp) * attack;
      }

    if (units <= 0)
      ret = -1;

    return ret;
  }

  int attack(int myUnits, int hpT, int attackT, int numWodT, int numStoT)
  {
    int ret = -1;
    int left = 0;
    int mid = myUnits / 2;
    int right = myUnits;

    for (int i=0; i<500; i++)
      {
	int resWood = getTurn(mid, hpT, attackT, numWodT);
	int resStone = getTurn(myUnits - mid, hpT, attackT, numStoT);

	//	cout << mid << " " << resWood << " " << resStone << endl;

	if (resWood == -1 && resStone == -1)
	  return -1;

	if (resWood != -1 && resStone != -1)
	  {
	    if (resWood > resStone)
	      {
		left = mid;
		mid += (right - mid) / 2;
	      }
	    else
	      {
		right = mid;
		mid = (mid - left) / 2;
	      }
	  }
	else
	  {
	    if (resWood == -1)
	      {
		left = mid;
		mid += (right - mid) / 2;
	      }
	    else
	      {
		right = mid;
		mid = (mid - left) / 2;
	      }
	  }

	if (resWood != -1 && resStone != -1)
	  if (ret == -1)
	    ret = max(resWood, resStone);
	  else
	    ret = min(ret, max(resWood, resStone));
      }

    return ret;
  }
   
  // BEGIN CUT HERE
public:
  void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 3)) test_case_4(); if ((Case == -1) || (Case == 3)) test_case_5(); }
private:
  template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
  void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
  void test_case_0() { int Arg0 = 7; int Arg1 = 2; int Arg2 = 1; int Arg3 = 2; int Arg4 = 3; int Arg5 = 2; verify_case(0, Arg5, attack(Arg0, Arg1, Arg2, Arg3, Arg4)); }
  void test_case_1() { int Arg0 = 120; int Arg1 = 10; int Arg2 = 40000; int Arg3 = 6; int Arg4 = 6; int Arg5 = 1; verify_case(1, Arg5, attack(Arg0, Arg1, Arg2, Arg3, Arg4)); }
  void test_case_2() { int Arg0 = 119; int Arg1 = 10; int Arg2 = 40000; int Arg3 = 6; int Arg4 = 6; int Arg5 = -1; verify_case(2, Arg5, attack(Arg0, Arg1, Arg2, Arg3, Arg4)); }
  void test_case_3() { int Arg0 = 200; int Arg1 = 50; int Arg2 = 3; int Arg3 = 10; int Arg4 = 5; int Arg5 = 6; verify_case(3, Arg5, attack(Arg0, Arg1, Arg2, Arg3, Arg4)); }
  void test_case_4() { int Arg0 = 1000000000; int Arg1 = 40000; int Arg2 = 40000; int Arg3 = 449; int Arg4 = 40000; int Arg5 = 7; verify_case(4, Arg5, attack(Arg0, Arg1, Arg2, Arg3, Arg4)); }
  void test_case_5() { int Arg0 = 15960246; int Arg1 = 40000; int Arg2 = 1; int Arg3 = 40000; int Arg4 = 40000; int Arg5 = 1648; verify_case(5, Arg5, attack(Arg0, Arg1, Arg2, Arg3, Arg4)); }
  //, 40000, 40000, 449, 40000
  //{, 40000, 1, 40000, 40000}
  // END CUT HERE

};
// BEGIN CUT HERE
int main() {
EnemyTowers ___test;
___test.run_test(-1);
}
// END CUT HERE 
