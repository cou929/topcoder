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

class CardStraights {
public:
  int longestStraight(vector <int> cards)
  {
    int ret = 0;
    int jorker = 0;
    int pos = -1;

    sort(cards.begin(), cards.end());

    for (int i=0; i<cards.size(); i++)
      if (cards[i] != 0)
	{
	  pos = i;
	  break;
	}

    jorker = (pos == -1) ? cards.size() : pos;
    cards.erase(cards.begin(), cards.begin() + jorker);

    if (cards.empty())
      {
	ret = jorker;
      }
    else
      {
	for (int i=1; i<cards.size(); i++)
	  if (cards[i] - cards[i-1] == 1)
	    ret++;
	ret += min(cards[0] - 1, jorker + 1);
      }


    for (int i=0; i<cards.size(); i++)
      {
	int start = cards[i];
	int c = 0;
	int jo = jorker;
	for (int j=0; start+j<1000000; j++)
	  {
	    if (find(cards.begin(), cards.end(), start + j) != cards.end())
	      {
		c++;
		continue;
	      }

	    if (jo > 0) 
	      {
		c++;
		jo--;
	      }
	    else
	      break;
	  }
	ret = max(c, ret);
      }

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
    int Arr0[] = {0,6,5,10,3,0,11}; 
    vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
    int Arg1 = 5; 
    verify_case(0, Arg1, longestStraight(Arg0));
  }
  void test_case_1() { int Arr0[] = {100,100,100,101,100,99,97,103}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(1, Arg1, longestStraight(Arg0)); }
  void test_case_2() { int Arr0[] = {0,0,0,1,2,6,8,1000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; verify_case(2, Arg1, longestStraight(Arg0)); }
  void test_case_3() { int Arr0[] = {1,9,5,7,3,4,0,0,0,10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; verify_case(3, Arg1, longestStraight(Arg0)); }
  void test_case_4() { int Arr0[] = {0, 0, 0, 0, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; verify_case(4, Arg1, longestStraight(Arg0)); }
  void test_case_5() { int Arr0[] = {0, 0, 999999}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(5, Arg1, longestStraight(Arg0)); }

  // END CUT HERE

};

// BEGIN CUT HERE
int main() {
  CardStraights ___test;
  ___test.run_test(-1);
}
// END CUT HERE 
