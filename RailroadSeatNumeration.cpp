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
class RailroadSeatNumeration {
public:
  string toStr(int n) {ostringstream ss; ss << n; return ss.str();}
  
  string getInternational(vector <int> tickets)
  {
    string ret;
    vector <int> domestics;
    vector <int> internationals;
    int intSeat[] = {1, 3, 4, 6};

    for (int i=0; i<tickets.size(); i++)
      {
	if (tickets[i] <= 36)
	  {
	    int t = (double)tickets[i] / 4 + 0.9;
	    t = t*10 + intSeat[(tickets[i] - 1) % 4];
	    domestics.push_back(t);
	  }

	if (tickets[i] / 10 <= 9 && tickets[i] > 9)
	  if (tickets[i] % 10 == 1 || tickets[i] % 10 == 3 || tickets[i] % 10 == 4 || tickets[i] % 10 == 6)
	    internationals.push_back(tickets[i]);
      }

    if (domestics.size() != tickets.size() && internationals.size() != tickets.size())
      return "BAD DATA";
    else if (domestics.size() == tickets.size() && internationals.size() == tickets.size())
      return "AMBIGUOUS";

    if (domestics.size() == tickets.size())
      for (int i=0; i<domestics.size(); i++)
	ret += toStr(domestics[i]) + " ";

    if (internationals.size() == tickets.size())
      for (int i=0; i<internationals.size(); i++)
	ret += toStr(internationals[i]) + " ";

    ret.erase(ret.end()-1);

    return ret;
  }
   
  // BEGIN CUT HERE
public:
  void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 5)) test_case_6();}
private:
  template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
  void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
  void test_case_0() { int Arr0[] = {1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "11"; verify_case(0, Arg1, getInternational(Arg0)); }
  void test_case_1() { int Arr0[] = {11}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "AMBIGUOUS"; verify_case(1, Arg1, getInternational(Arg0)); }
  void test_case_2() { int Arr0[] = {45}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "BAD DATA"; verify_case(2, Arg1, getInternational(Arg0)); }
  void test_case_3() { int Arr0[] = {5, 7, 6}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "21 24 23"; verify_case(3, Arg1, getInternational(Arg0)); }
  void test_case_4() { int Arr0[] = {21, 24, 23}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "AMBIGUOUS"; verify_case(4, Arg1, getInternational(Arg0)); }
  void test_case_5() { int Arr0[] = {8, 28}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "26 76"; verify_case(5, Arg1, getInternational(Arg0)); }
  void test_case_6() { int Arr0[] = {36, 3, 19, 20, 5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "96 14 54 56 21"; verify_case(5, Arg1, getInternational(Arg0)); }

  // END CUT HERE

};
// BEGIN CUT HERE
int main() {
RailroadSeatNumeration ___test;
___test.run_test(-1);
}
// END CUT HERE 
