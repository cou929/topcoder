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
class TheTriangleBothDivs {
public:
  string fix(string time) {
    string ret = "23:59";
//     set <string> candidates;

//     for (int h1=0; h1<3; h1++) {
//       string can;
//       if (time[0] == '?') can += '0' + h1;
//       else can += time[0];
//       for (int h2=0; h2 < 10; h2++) {
//         int left = 0, right = 0;
//         if (time[1] == '?') can += '0' + h2;
//         else can += time[1];
//         if (can[0] == '2' && can[1] > '3') goto END;

//         can += ':';
//         if (time[3] == '?') can += '0';
//         else can += time[3];
//         if (time[4] == '?') can += '0';
//         else can += time[4];


//         if (time[9] == '?' && time[10] != '?') {
//           int n = time[10] - '0';
//           int hour = (can[0] - '0') * 10 + can[1] - '0';
//           int next_hour = (hour + n) % 24;
//           if (hour + n < 0) next_hour = 24 - abs(hour + n);
//           string tmp = can;
//           tmp[0] = next_hour / 10 + '0';
//           tmp[1] = next_hour % 10 + '0';
//           candidates.insert(tmp);
//           next_hour = (hour - n) % 24;
//           if (hour - n < 0) next_hour = 24 - abs(hour - n);
//           tmp[0] = next_hour / 10 + '0';
//           tmp[1] = next_hour % 10 + '0';
//           candidates.insert(tmp);
//           goto END;
//         } else if (time[9] != '?' && time[10] != '?') {
//           int n = time[10] - '0';
//           if (time[9] == '+') n *= -1;
//           int hour = (can[0] - '0') * 10 + can[1] - '0';
//           int next_hour = (hour + n) % 24;
//           if (hour + n < 0) next_hour = 24 - abs(hour + n);
//           string tmp = can;
//           tmp[0] = next_hour / 10 + '0';
//           tmp[1] = next_hour % 10 + '0';
//           if (tmp == "00:00")
//             cout << h1 << " " << h2  << endl;
//           candidates.insert(tmp);
//           goto END;
//         }

//         if (time[9] == '?' && time[10] == '?') {
//           left = -9, right = 9;
//         } else if (time[9] != '?' && time[10] == '?') {
//           if (time[9] == '-')
//             left = 1, right = 9;
//           else
//             left = -9, right = 0;
//         }

//         for (int i=left; i<=right; i++) {
//           int hour = (can[0] - '0') * 10 + can[1] - '0';
//           int next_hour = (hour + i) % 24;
//           if (hour + i < 0) next_hour = 24 - abs(hour + i);
//           string tmp = can;
//           tmp[0] = next_hour / 10 + '0';
//           tmp[1] = next_hour % 10 + '0';

//           candidates.insert(tmp);
//         }
//       END:
//         string tmp = can;
//         can.clear();
//         can += tmp[0];
//       }
//     }

//     for (set <string>::iterator i=candidates.begin(); i!=candidates.end(); i++)
//       cout << *i << endl;
//     ret = *(candidates.begin());

    char s[11];
    for (int h=0; h<24; h++)
      for (int m=0; m<60; m++)
        for (int g=-9; g<10; g++) {
          if (g < 0)
            sprintf(s, "%02d:%02d GMT-%d", h, m, abs(g));
          else
            sprintf(s, "%02d:%02d GMT+%d", h, m, g);

          int i;
          for (i=0; i<time.size(); i++)
            if (time[i] != '?' && time[i] != s[i])
              break;

          if (i == time.size()) {
            sprintf(s, "%02d:%02d", (h-g+24)%24, m);
            ret = min(ret, string(s));
          }
        }

    return ret;
  }
   
  // BEGIN CUT HERE
public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "17:45 GMT-4"; string Arg1 = "21:45"; verify_case(0, Arg1, fix(Arg0)); }
	void test_case_1() { string Arg0 = "16:?? GMT??"; string Arg1 = "00:00"; verify_case(1, Arg1, fix(Arg0)); }
	void test_case_2() { string Arg0 = "?1:34 GMT-9"; string Arg1 = "06:34"; verify_case(2, Arg1, fix(Arg0)); }
	void test_case_3() { string Arg0 = "??:?? GMT??"; string Arg1 = "00:00"; verify_case(3, Arg1, fix(Arg0)); }
	void test_case_4() { string Arg0 = "10:00 GMT-?"; string Arg1 = "11:00"; verify_case(3, Arg1, fix(Arg0)); }
	void test_case_5() { string Arg0 = "?5:?? GMT+1"; string Arg1 = "04:00"; verify_case(3, Arg1, fix(Arg0)); }

  // END CUT HERE

};
// BEGIN CUT HERE
int main() {
TheTriangleBothDivs ___test;
___test.run_test(-1);
}
// END CUT HERE 
