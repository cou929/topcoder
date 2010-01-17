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
class TallPeople {
public:
  int toInt(string s) {int r = 0; istringstream ss(s); ss >> r; return r;}

  vector <int> split(const string _s, const string del)
  {
    vector <int> ret;
    string s = _s;

    while (!s.empty())
      {
	size_t pos = s.find(del);
	string sub = "";
	sub = s.substr(0, pos);
	ret.push_back(toInt(sub));
	if (pos != string::npos)
	  pos += del.size();
	s.erase(0, pos);
      }

    return ret;
  }

  vector <int> getPeople(vector <string> people)
  {
    vector <vector <int> > peoplei;
    vector <int> shortests;
    vector <int> tallests;
    int shor = 0;
    int tall = 1000000;

    for (int i=0; i<people.size(); i++)
      peoplei.push_back(split(people[i], " "));

    for (int i=0; i<peoplei.size(); i++)
      {
	int tmp = 100000;
	for (int j=0; j<peoplei[i].size(); j++)
	  tmp = min(tmp, peoplei[i][j]);
	shortests.push_back(tmp);
      }
    for (int i=0; i<peoplei[0].size(); i++)
      {
	int tmp = 0;
	for (int j=0; j<peoplei.size(); j++)
	  tmp = max(tmp, peoplei[j][i]);
	tallests.push_back(tmp);
      }

    for (int i=0; i<shortests.size(); i++)
      shor = max(shor, shortests[i]);

    for (int i=0; i<tallests.size(); i++)
      tall = min(tall, tallests[i]);

    vector <int> ret;
    ret.push_back(shor);
    ret.push_back(tall);

    return ret;
  }
   
  // BEGIN CUT HERE
public:
  void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
private:
  template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
  void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
  void test_case_0() { string Arr0[] = {"9 2 3",
					"4 8 7"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 4,  7 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, getPeople(Arg0)); }
  void test_case_1() { string Arr0[] = {"1 2",
					"4 5",
					"3 6"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 4,  4 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, getPeople(Arg0)); }
  void test_case_2() { string Arr0[] = {"1 1",
					"1 1"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 1,  1 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, getPeople(Arg0)); }

  // END CUT HERE

};
// BEGIN CUT HERE
int main() {
TallPeople ___test;
___test.run_test(-1);
}
// END CUT HERE 
