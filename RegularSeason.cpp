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
typedef struct team
{
  string name;
  double score;
};

bool cmp(team a, team b)
{
  if (a.score == b.score)
    return a.name < b.name;
  else
    return a.score > b.score;
}

vector <string> splits(const string _s, const string del)
{
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

int toInt(string s) {int r = 0; istringstream ss(s); ss >> r; return r;}
string toStr(int n) {ostringstream ss; ss << n; return ss.str();}

class RegularSeason {
public:
  vector <string> finalStandings(vector <string> teams, int rounds)
  {
    vector <team> t;
    vector <vector <string> > steams;
    vector <string> ret;

    for (int i=0; i<teams.size(); i++)
      {
	vector <string> s = splits(teams[i], " ");
	team tt;
	tt.name = s[0];
	tt.score = 0;
	s.erase(s.begin());
	t.push_back(tt);
	steams.push_back(s);
      }

    for (int i=0; i<steams.size(); i++)
      for (int j=0; j<steams[i].size(); j++)
	if (i != j)
	  {
	    t[i].score += toInt(steams[i][j]) * rounds;
	    t[i].score += (100 - toInt(steams[j][i])) * rounds;
	  }

    sort(t.begin(), t.end(), cmp);

    for (int i=0; i<t.size(); i++)
      {
	string s;
	s = t[i].name;
	s += " ";
	double d = t[i].score / 100.0;
	d += 0.5;
	s += toStr((int)d);
	ret.push_back(s);
      }

    return ret;
  }
   
  // BEGIN CUT HERE
public:
  void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
private:
  template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
  void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
  void test_case_0() { string Arr0[] = {"A 0 10 50",
					"B 100 0 100",
					"C 50 10 0"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; string Arr2[] = { "B 19",  "A 6",  "C 6" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, finalStandings(Arg0, Arg1)); }
  void test_case_1() { string Arr0[] = {"SPURS 0 33 67 100",
					"LAKERS 67 0 33 100",
					"WOLVES 33 67 0 100",
					"KINGS 0 75 75 0"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; string Arr2[] = { "SPURS 8",  "LAKERS 7",  "WOLVES 7",  "KINGS 3" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, finalStandings(Arg0, Arg1)); }
  void test_case_2() { string Arr0[] = {"A 0 10 20 30 40 50 60 70 80 90",
					"AA 90 0 10 20 30 40 50 60 70 80",
					"AAA 80 90 0 10 20 30 40 50 60 70",
					"AAAA 70 80 90 0 10 20 30 40 50 60",
					"AAAAA 60 70 80 90 0 10 20 30 40 50",
					"AAAAAA 50 60 70 80 90 0 10 20 30 40",
					"AAAAAAA 40 50 60 70 80 90 0 10 20 30",
					"AAAAAAAA 30 40 50 60 70 80 90 0 10 20",
					"AAAAAAAAA 20 30 40 50 60 70 80 90 0 10",
					"AAAAAAAAAA 10 20 30 40 50 60 70 80 90 0"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; string Arr2[] = { "A 90",  "AA 90",  "AAA 90",  "AAAA 90",  "AAAAA 90",  "AAAAAA 90",  "AAAAAAA 90",  "AAAAAAAA 90",  "AAAAAAAAA 90",  "AAAAAAAAAA 90" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(2, Arg2, finalStandings(Arg0, Arg1)); }
  void test_case_3() { string Arr0[] = {"WF 0 0 71 10 62 87 49 75 50","OZ 38 0 79 55 36 96 63 17 37",
					"C 13 75 0 96 61 2 33 5 64","LCG 13 85 87 0 60 72 86 1 12",
					"GDDYC 71 62 21 6 0 17 63 34 32","B 37 66 81 81 53 0 61 80 90",
					"XK 14 63 40 25 13 86 0 6 43","YVN 57 30 55 22 31 11 81 0 13",
					"SKGAN 28 79 90 79 75 62 36 86 0"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; string Arr2[] = { "SKGAN 99",  "WF 93",  "B 92",  "LCG 84",  "YVN 80",  "OZ 76",  "GDDYC 72",  "C 63",  "XK 62" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(3, Arg2, finalStandings(Arg0, Arg1)); }
  void test_case_4() { string Arr0[] = {
      "ZSN 0 61 70 44 69 40 84 59 20",
      "SJKB 95 0 88 39 99 18 90 58 44",
      "EBIUF 63 71 0 5 28 26 41 90 71",
      "MA 73 90 39 0 40 91 31 39 57",
      "NPT 35 74 75 74 0 74 14 20 27",
      "JVY 68 92 37 52 11 0 91 20 52",
      "ZBOW 66 44 69 9 8 7 0 2 35",
      "HH 31 70 14 39 6 68 73 0 20",
      "P 70 62 66 54 9 55 5 98 0"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; string Arr2[] = { "MA 94",  "NPT 92",  "P 89",  "JVY 84",  "SJKB 77",  "ZSN 75",  "EBIUF 74",  "HH 74",  "ZBOW 61" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(4, Arg2, finalStandings(Arg0, Arg1)); }

  // END CUT HERE

};
// BEGIN CUT HERE
int main() {
RegularSeason ___test;
___test.run_test(-1);
}
// END CUT HERE 
