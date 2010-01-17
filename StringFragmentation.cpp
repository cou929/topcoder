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

class StringFragmentation {
public:
  int largestFontSize(string text, int width, int height)
  {
    int i;
    int ret = -1;
    int font = 7;
    int cnum = 0;
    int lnum = 0;

    while (1)
      {
	cnum = width / (font + 2);
	lnum = 0;

	int pos = 0;
	while (1)
	  {
	    lnum++;
	    if (pos + cnum > text.size())
	      break;

	    if (text[pos + cnum + 1] == ' ')
	      pos += cnum +2;
	    else
	      {
		bool flg = false;
		for (i=0; i<cnum; i++)
		  if (text[pos + cnum - i] == ' ')
		    {
		      flg = true;
		      break;
		    }

		if (!flg)
		  break;
		pos = pos + cnum - i + 1;
	      }
	  }

	//	    cout << pos << " " << cnum << " " << font << endl;

	if (lnum * (font * 2) <= height)
	  {
	    ret = font;
	    font++;
	  }
	else
	  break;
      }
    return ret;
  }

   
  // BEGIN CUT HERE
public:
  void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
private:
  template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
  void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
  void test_case_0() { string Arg0 = "ONE TWO THREE FOUR FIVE"; int Arg1 = 150; int Arg2 = 40; int Arg3 = 9; verify_case(0, Arg3, largestFontSize(Arg0, Arg1, Arg2)); }
  void test_case_1() { string Arg0 = "ONE TWO THREE FOUR FIVE"; int Arg1 = 150; int Arg2 = 60; int Arg3 = 10; verify_case(1, Arg3, largestFontSize(Arg0, Arg1, Arg2)); }
  void test_case_2() { string Arg0 = "ONE TWO THREE FOUR FIVE"; int Arg1 = 150; int Arg2 = 10000; int Arg3 = 28; verify_case(2, Arg3, largestFontSize(Arg0, Arg1, Arg2)); }
  void test_case_3() { string Arg0 = "ONE TWO THREE FOUR FIVE"; int Arg1 = 10000; int Arg2 = 10000; int Arg3 = 1250; verify_case(3, Arg3, largestFontSize(Arg0, Arg1, Arg2)); }
  void test_case_4() { string Arg0 = "ONE TWO THREE FOUR FIVE"; int Arg1 = 50; int Arg2 = 50; int Arg3 = -1; verify_case(4, Arg3, largestFontSize(Arg0, Arg1, Arg2)); }
  void test_case_5() { string Arg0 = "A"; int Arg1 = 9; int Arg2 = 14; int Arg3 = -1; verify_case(5, Arg3, largestFontSize(Arg0, Arg1, Arg2)); }

  // END CUT HERE

};

// BEGIN CUT HERE
int main() {
StringFragmentation ___test;
___test.run_test(-1);
}
// END CUT HERE 
