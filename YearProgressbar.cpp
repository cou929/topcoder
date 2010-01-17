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

class YearProgressbar {
public:
  double percentage(string currentDate)
  {
    map <string, int> month;
    month["January"] = 0;
    month["February"] = 31;
    month["March"] = 59;
    month["April"] = 90;
    month["May"] = 120;
    month["June"] = 151;
    month["July"] = 181;
    month["August"] = 212;
    month["September"] = 243;
    month["October"] = 273;
    month["November"] = 304;
    month["December"] = 334;

    char monc[10];
    string mon;
    int day;
    int year;
    int hour;
    int min;

    sscanf(currentDate.c_str(), "%s %02d, %d %02d:%02d", monc, &day, &year, &hour, &min);
    mon = monc;

    bool isLeap = false;
    if (year % 400 == 0 || year % 4 == 0 && year % 100 != 0)
      isLeap = true;

    double md = 0, my = 0;
    if (isLeap)
      my = 366 * 24 * 60;
    else
      my = 365 * 24 * 60;

    if (isLeap && (mon != "January" && mon != "February"))
      day++;

    day--;

    md += month[mon] * 24 * 60;
    md += day * 24 * 60;
    md += hour * 60;
    md += min;

    return (md / my) * 100;
  }

   
  // BEGIN CUT HERE
public:
  void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
private:
  template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
  void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
  void test_case_0() { string Arg0 = "January 01, 2008 00:00"; double Arg1 = 0.0; verify_case(0, Arg1, percentage(Arg0)); }
  void test_case_1() { string Arg0 = "December 31, 2007 23:59"; double Arg1 = 99.99980974124807; verify_case(1, Arg1, percentage(Arg0)); }
  void test_case_2() { string Arg0 = "July 02, 2007 12:00"; double Arg1 = 50.0; verify_case(2, Arg1, percentage(Arg0)); }
  void test_case_3() { string Arg0 = "July 02, 2008 00:00"; double Arg1 = 50.0; verify_case(3, Arg1, percentage(Arg0)); }
  void test_case_4() { string Arg0 = "May 10, 1981 00:31"; double Arg1 = 35.348363774733635; verify_case(4, Arg1, percentage(Arg0)); }
  void test_case_5() { string Arg0 = "January 31, 1900 00:47"; double Arg1 = 8.228120243531203; verify_case(5, Arg1, percentage(Arg0)); }

  // END CUT HERE

};

// BEGIN CUT HERE
int main() {
YearProgressbar ___test;
___test.run_test(-1);
}
// END CUT HERE 
