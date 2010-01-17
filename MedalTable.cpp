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
typedef struct country
{
  string name;
  int gold;
  int silver;
  int bronze;
};

bool cmp(country a, country b)
{
  if (a.gold == b.gold)
    {
      if (a.silver == b.silver)
	{
	  if (a.bronze == b.bronze)
	    {
	      return b.name > a.name;
	    }
	  else
	    return a.bronze > b.bronze;
  	}
      else
	return a.silver > b.silver;
    }
  else
    return a.gold > b.gold;
}

class MedalTable {
public:
  typedef struct myst
  {
  public:
    int x;
    int y;

    bool operator<(const myst & a) const
    {
      if (a.y == y)
	return a.x > x;
      else
	return a.y > y;
    }
  };

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

  vector <string> generate(vector <string> results)
  {
    vector <country> countries;
    vector <vector <string> > s;
    map <string, pair <int, pair <int, int> > > m;
    map <string, pair <int, pair <int, int> > >::iterator mit;

    for (unsigned int i=0; i<results.size(); i++)
      {
	vector <string> c = splits(results[i], " ");
	s.push_back(c);
      }

    for (unsigned int i=0; i<s.size(); i++)
      for (unsigned int j=0; j<s[i].size(); j++)
	m[s[i][j]] = make_pair(0, make_pair(0, 0));

    for (unsigned int i=0; i<s.size(); i++)
      {
	m[s[i][0]].first++;
	m[s[i][1]].second.first++;
	m[s[i][2]].second.second++;
      }

    for (mit=m.begin(); mit!=m.end(); mit++)
      {
	country c;
	c.name = mit->first;
	c.gold = mit->second.first;
	c.silver = mit->second.second.first;
	c.bronze = mit->second.second.second;
	countries.push_back(c);
      }

    sort(countries.begin(), countries.end(), cmp);

    vector <string> ret;

    for (unsigned int i=0; i<countries.size(); i++)
      {
	char ch[1000];
	sprintf(ch, "%s %d %d %d", countries[i].name.c_str(), countries[i].gold, countries[i].silver, countries[i].bronze);
	string tmp = ch;
	ret.push_back(tmp);
      }

    // BEGIN CUT HERE
    vector <myst> myv;
    myst tmpm;
    tmpm.x = 10;
    tmpm.y = 1;
    myv.push_back(tmpm);
    tmpm.x = 1;
    tmpm.y = 10;
    myv.push_back(tmpm);
    sort(myv.begin(), myv.end());
    for (int i=0; i<myv.size(); i++)
      cout << myv[i].x << ", " << myv[i].y << endl;
    // END CUT HERE

    return ret;
  }
   
  // BEGIN CUT HERE
public:
  void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
private:
  template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
  void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
  void test_case_0() { string Arr0[] = {"ITA JPN AUS", "KOR TPE UKR", "KOR KOR GBR", "KOR CHN TPE"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "KOR 3 1 0",  "ITA 1 0 0",  "TPE 0 1 1",  "CHN 0 1 0",  "JPN 0 1 0",  "AUS 0 0 1",  "GBR 0 0 1",  "UKR 0 0 1" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, generate(Arg0)); }
  void test_case_1() { string Arr0[] = {"USA AUT ROM"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "USA 1 0 0",  "AUT 0 1 0",  "ROM 0 0 1" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, generate(Arg0)); }
  void test_case_2() { string Arr0[] = {"GER AUT SUI", "AUT SUI GER", "SUI GER AUT"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "AUT 1 1 1",  "GER 1 1 1",  "SUI 1 1 1" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, generate(Arg0)); }

  // END CUT HERE

};
// BEGIN CUT HERE
int main() {
MedalTable ___test;
___test.run_test(-1);
}
// END CUT HERE 
