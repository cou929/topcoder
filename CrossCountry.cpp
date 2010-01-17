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

class CrossCountry {
public:
  string scoreMeet(int numTeams, string finishOrder)
  {
    int i, j;
    char sum[numTeams];
    char count[numTeams];
    char six[numTeams];
    vector <int> sort;
    char tmp;
    string ret;

    for(i=0; i<numTeams; i++)
      {
	sum[i] = 0;        // sum
	count[i] = 0;        // count
	six[i] = 0;        // 6th
      }

    for(i=0; i<finishOrder.size(); i++)
      {
	if(count[finishOrder[i] - 'A'] < 5)
	  {
	    sum[finishOrder[i] - 'A'] += (i + 1);
	    count[finishOrder[i] - 'A']++;
	  }
	else if(count[finishOrder[i] - 'A'] == 5)
	  six[finishOrder[i] - 'A'] = i + 1;
      }

    for(i=0; i<numTeams; i++)
      if(sum[i] >= 5)
	sort.push_back(sum[i]);

    sort(sort.begin(), sort.end());

    for(i=0; i<sort.size(); i++)
      {
	if(sort[i] == sort[i-1])
	  if(table[sort[i] - 'A'][2] < table[sort[i-1] - 'A'][2])
	    {
	      tmp = sort[i];
	      sort[i] = sort[i-1];
	      sort[i-1] = tmp;
	    }
      }

    for(i=0; i<sort.size(); i++)
      ret.push_back(sort[i]);

    return ret;
  }

   
  // BEGIN CUT HERE
public:
  void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
private:
  template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
  void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
  void test_case_0() { int Arg0 = 2; string Arg1 = "AABBABBABBA"; string Arg2 = "AB"; verify_case(0, Arg2, scoreMeet(Arg0, Arg1)); }
  void test_case_1() { int Arg0 = 3; string Arg1 = "CCCBBBBBAAACC"; string Arg2 = "BC"; verify_case(1, Arg2, scoreMeet(Arg0, Arg1)); }
  void test_case_2() { int Arg0 = 4; string Arg1 = "ABDCBADBDCCDBCDBCAAAC"; string Arg2 = "BDCA"; verify_case(2, Arg2, scoreMeet(Arg0, Arg1)); }
  void test_case_3() { int Arg0 = 10; string Arg1 = "BDHCEAJBIDBCCHGCBDJEBAAHEGAGGADHGIECJEHAEBDADJCDHG"; string Arg2 = "BCDAHEG"; verify_case(3, Arg2, scoreMeet(Arg0, Arg1)); }
  void test_case_4() { int Arg0 = 3; string Arg1 = "BABCAABABAB"; string Arg2 = "AB"; verify_case(4, Arg2, scoreMeet(Arg0, Arg1)); }

  // END CUT HERE

};

// BEGIN CUT HERE
int main() {
CrossCountry ___test;
___test.run_test(-1);
}
// END CUT HERE
