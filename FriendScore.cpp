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

using namespace std;

class FriendScore {
   public:
   int highestScore(vector <string> friends)
  {
    int i, j, k;
    int max = 0;

    for (i=0; i<friends.size(); i++)
      {
	vector <int> tmp;
	for (j=0; j<friends[i].size(); j++)
	  {
	    tmp.push_back(0);
	  }

	for (j=0; j<friends[i].size(); j++)
	  {
	    if (friends[i][j] == 'Y') 
	      {
		tmp[j] = 1;
		for (k=0; k<friends[j].size(); k++)
		  {
		    if (friends[j][k] == 'Y')
		      tmp[k] = 1;
		  }
	      }
	  }

	int count = 0;
	for (j=0; j<tmp.size(); j++)
	  {
	    if (tmp[j] == 1)
	      count++;
	  }
	count--;

	if (max < count)
	  max = count;
      }

    return max;
   }

   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"NNN",
 "NNN",
 "NNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(0, Arg1, highestScore(Arg0)); }
	void test_case_1() { string Arr0[] = {"NYY",
 "YNY",
 "YYN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(1, Arg1, highestScore(Arg0)); }
	void test_case_2() { string Arr0[] = {"NYNNN",
 "YNYNN", 
 "NYNYN", 
 "NNYNY", 
 "NNNYN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(2, Arg1, highestScore(Arg0)); }
	void test_case_3() { string Arr0[] = {"NNNNYNNNNN",
 "NNNNYNYYNN",
 "NNNYYYNNNN",
 "NNYNNNNNNN",
 "YYYNNNNNNY",
 "NNYNNNNNYN",
 "NYNNNNNYNN",
 "NYNNNNYNNN",
 "NNNNNYNNNN",
 "NNNNYNNNNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 8; verify_case(3, Arg1, highestScore(Arg0)); }
	void test_case_4() { string Arr0[] = {"NNNNNNNNNNNNNNY",
 "NNNNNNNNNNNNNNN",
 "NNNNNNNYNNNNNNN",
 "NNNNNNNYNNNNNNY",
 "NNNNNNNNNNNNNNY",
 "NNNNNNNNYNNNNNN",
 "NNNNNNNNNNNNNNN",
 "NNYYNNNNNNNNNNN",
 "NNNNNYNNNNNYNNN",
 "NNNNNNNNNNNNNNY",
 "NNNNNNNNNNNNNNN",
 "NNNNNNNNYNNNNNN",
 "NNNNNNNNNNNNNNN",
 "NNNNNNNNNNNNNNN",
 "YNNYYNNNNYNNNNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; verify_case(4, Arg1, highestScore(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
FriendScore ___test;
___test.run_test(-1);
}
// END CUT HERE 
