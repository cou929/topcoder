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
#include <numeric>
// BEGIN CUT HERE
#include "cout.hpp"
// END CUT HERE
using namespace std;
class Diving {
public:
  double toDouble(string s) {double r = 0.0; istringstream ss(s); ss >> r; return r;}

  vector <string> splits(const string _s, const string del) {
    vector <string> ret;
    string s = _s;

    while (!s.empty())
      {
        size_t pos = s.find(del);
        string sub = "";
        sub = s.substr(0, pos);
        ret.push_back(sub);
        if (pos != string::npos)
          pos += del.size();
        s.erase(0, pos);
      }

    return ret;
  }

  double getScore(vector <double> seq, double v, double mul) {
    double total = 0;
    int i;

    seq.push_back(v);
    sort(seq.begin(), seq.end());

    //    cout << seq << endl;
    
    for (i=1; i<seq.size()-1; i++) {
      total += seq[i];
    }

    return total * mul;
  }

  string needed(string _difficulty, string _need, string _ratings) {
    string ret = "-1.0";
    char tmp_ret[10];
    vector <string> tmp = splits(_ratings, " ");
    vector <double> ratings;
    double dif = toDouble(_difficulty);
    double need = toDouble(_need);
    int i;
    double j;

    for (i=0; i<tmp.size(); i++) {
      if (tmp[i][0] == '?')
        continue;
      ratings.push_back(toDouble(tmp[i]));
    }

    for (j=0; j<=10.0; j += 0.5) {
      if (getScore(ratings, j, dif) + 0.001 >= need) {
        sprintf(tmp_ret, "%.1f", j);
        ret = (string)tmp_ret;
        break;
      }
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
    if ((Case == -1) || (Case == 6)) test_case_6();
    if ((Case == -1) || (Case == 7)) test_case_7();
  }
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { 
    string Arg0 = "3.2"; 
    string Arg1 = "50.32"; 
    string Arg2 = "5.5 7.5 10.0 ?.? 4.5"; 
    string Arg3 = "0.0"; 
    verify_case(0, Arg3, needed(Arg0, Arg1, Arg2)); }
	void test_case_1() { 
    string Arg0 = "3.2"; 
    string Arg1 = "50.32"; 
    string Arg2 = "5.5 5.5 10.0 ?.? 4.5"; 
    string Arg3 = "5.0"; 
    verify_case(1, Arg3, needed(Arg0, Arg1, Arg2)); }
	void test_case_2() { 
    string Arg0 = "4.0"; 
    string Arg1 = "120.00"; 
    string Arg2 = "9.5 10.0 ?.? 10.0 10.0"; 
    string Arg3 = "10.0"; 
    verify_case(2, Arg3, needed(Arg0, Arg1, Arg2)); }
	void test_case_3() { 
    string Arg0 = "4.0"; 
    string Arg1 = "120.00"; 
    string Arg2 = "9.5 10.0 ?.? 9.5 10.0"; 
    string Arg3 = "-1.0"; 
    verify_case(3, Arg3, needed(Arg0, Arg1, Arg2)); }
	void test_case_4() { 
    string Arg0 = "2.3"; 
    string Arg1 = ".01"; 
    string Arg2 = "0.0 0.0 ?.? 0.0 0.5"; 
    string Arg3 = "0.5"; 
    verify_case(4, Arg3, needed(Arg0, Arg1, Arg2)); }
	void test_case_5() { 
    string Arg0 = "3.3"; 
    string Arg1 = "47.85"; 
    string Arg2 = "0.5 5.5 3.5 7.0 ?.?"; 
    string Arg3 = "5.5"; 
    verify_case(5, Arg3, needed(Arg0, Arg1, Arg2)); }
	void test_case_6() { 
    string Arg0 = "3.2"; 
    string Arg1 = "50.32"; 
    string Arg2 = "5.5 7.5 10.0 ?.? 4.5"; 
    string Arg3 = "0.0"; 
    verify_case(6, Arg3, needed(Arg0, Arg1, Arg2)); }
	void test_case_7() { 
    string Arg0 = "3.2"; 
    string Arg1 = "50.32"; 
    string Arg2 = "5.5 7.5 10.0 ?.? 4.5"; 
    string Arg3 = "0.0"; 
    verify_case(7, Arg3, needed(Arg0, Arg1, Arg2)); }

  // END CUT HERE

};
// BEGIN CUT HERE
int main() {
  Diving ___test;
  ___test.run_test(-1);
}
// END CUT HERE 
