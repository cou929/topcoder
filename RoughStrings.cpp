// BEGIN CUT HERE
// END CUT HERE
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <map>

using namespace std;

class RoughStrings {
public:
  int minRoughness(string s, int n)
  {
    int i;
    map <char, int> occurence;
    map <char, int>::iterator it;
    vector <int> nums;
    int minimum = 1000;
    int c1, c2;

    for (i=0; i<s.size(); i++)
      occurence[s[i]]++;

    for (it=occurence.begin(); it!=occurence.end(); it++)
      nums.push_back(it->second);

    sort(nums.begin(), nums.end());

    c1 = nums[nums.size()-1];
    c2 = nums[0];

    minimum = c1 - c2;

    for (i=1; i<=n; i++)
      {
	if (c2 == 1)
	  if (minimum > c1 - nums[1])
	    {
	      minimum = c1 - nums[1];
	      nums.erase(nums.begin());
	      if (minimum == 0)
		break;

	      continue;
	    }

	if (minimum > abs(c1-1 - c2))
	  {
	    minimum = abs(c1-1 - c2);
	    nums[nums.size()-1]--;
	    if (minimum == 0)
	      break;
	  }
      }

    return minimum;
  }

   
  // BEGIN CUT HERE
public:
  void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
private:
  template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
  void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
  void test_case_0() { string Arg0 = "aaaaabbc"; int Arg1 = 1; int Arg2 = 3; verify_case(0, Arg2, minRoughness(Arg0, Arg1)); }
  void test_case_1() { string Arg0 = "aaaabbbbc"; int Arg1 = 5; int Arg2 = 0; verify_case(1, Arg2, minRoughness(Arg0, Arg1)); }
  void test_case_2() { string Arg0 = "veryeviltestcase"; int Arg1 = 1; int Arg2 = 2; verify_case(2, Arg2, minRoughness(Arg0, Arg1)); }
  void test_case_3() { string Arg0 = "gggggggooooooodddddddllllllluuuuuuuccckkk"; int Arg1 = 5; int Arg2 = 3; verify_case(3, Arg2, minRoughness(Arg0, Arg1)); }
  void test_case_4() { string Arg0 = "zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz"; int Arg1 = 17; int Arg2 = 0; verify_case(4, Arg2, minRoughness(Arg0, Arg1)); }
  void test_case_5() { string Arg0 = "bbbccca"; int Arg1 = 2; int Arg2 = 0; verify_case(5, Arg2, minRoughness(Arg0, Arg1)); }

  // END CUT HERE

};

// BEGIN CUT HERE
int main() {
RoughStrings ___test;
___test.run_test(-1);
}
// END CUT HERE 
