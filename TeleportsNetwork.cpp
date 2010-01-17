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
class TeleportsNetwork {
public:
  vector <int> builtRoute(vector <int> cx, vector <int> cy)
  {
    vector <int> ret(cx.size());
    ret[0] = -1;
    // (distance, x, y, index)
    vector <pair<int, pair<int, pair <int, int> > > > fromCapiatl;

    for (int i=0; i<cx.size(); i++)
      {
	int distance = (cx[0]-cx[i])*(cx[0]-cx[i]) + (cy[0]-cy[i])*(cy[0]-cy[i]);
	fromCapiatl.push_back(make_pair(distance, make_pair(cx[i], make_pair(cy[i], i))));
      }

    sort(fromCapiatl.begin(), fromCapiatl.end());

    for (int i=1; i<fromCapiatl.size(); i++)
      {
	vector <pair<int, pair<int, pair <int, int> > > > candidates;
	vector <pair<int, pair<int, pair <int, int> > > > distanceFromHere;

	for (int j=0; j<i; j++)
	  if (fromCapiatl[j].first < fromCapiatl[i].first)
	    candidates.push_back(fromCapiatl[j]);

	for (int j=0; j<candidates.size(); j++)
	  {
	    int canIndex = candidates[j].second.second.second;
	    int distance = (cx[i]-cx[canIndex])*(cx[i]-cx[canIndex]) + (cy[i]-cy[canIndex])*(cy[i]-cy[canIndex]);
	    distanceFromHere.push_back(make_pair(distance, make_pair(cx[canIndex], make_pair(cy[canIndex], canIndex))));
	  }

	sort(distanceFromHere.begin(), distanceFromHere.end());
	ret[fromCapiatl[i].second.second.second] = (distanceFromHere[0].second.second.second);
      }

    return ret;
  }

  class allCombination
  {
  private:
    int _m, _n;
    vector <vector <int> > ret;

    int _s(int start, vector <int> com)
    {
      if (com.size() == _m)
	{
	  ret.push_back(com);
	  return 0;
	}
      else
	{
	  for (int i=start; i<_n; i++)
	    {
	      com.push_back(i);
	      _s(++start, com);
	      com.pop_back();
	    }
	}
      return 0;
    }

  public:
    vector <vector <int> > generate(int n, int m)
    {
      _n = n;
      _m = m;
      vector <int> com;

      _s(0, com);

      return ret;
    }
  };

  int calcInconvenient(vector <int> route, vector <int> teleportCities)
  {
    int ret = 0;

    return ret;
  }

  int distribute(int teleportCount, vector <int> citiesX, vector <int> citiesY)
  {
    int ret = 100;
    allCombination *alc = new allCombination();
    vector <vector <int> > placements = alc->generate(citiesX.size()-1, teleportCount);
    vector <int> route;

    route = builtRoute(citiesX, citiesY);

    for (int i=0; i<placements.size(); i++)
      ret = min(ret, calcInconvenient(route, placements[i]));

    return ret;
  }
   
  // BEGIN CUT HERE
public:
  void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
private:
  template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
  void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
  void test_case_0() { int Arg0 = 2; int Arr1[] = {0,1,1,1,2,2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1,0,1,2,0,2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 1; verify_case(0, Arg3, distribute(Arg0, Arg1, Arg2)); }
  void test_case_1() { int Arg0 = 1; int Arr1[] = {0,1,1,1,2,2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1,0,1,2,0,2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 2; verify_case(1, Arg3, distribute(Arg0, Arg1, Arg2)); }
  void test_case_2() { int Arg0 = 0; int Arr1[] = {0,1,1,1,2,3,3,4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1,1,2,0,0,0,2,1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 5; verify_case(2, Arg3, distribute(Arg0, Arg1, Arg2)); }
  void test_case_3() { int Arg0 = 1; int Arr1[] = {0,1,2,3,4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {0,0,0,0,0}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 1; verify_case(3, Arg3, distribute(Arg0, Arg1, Arg2)); }
  void test_case_4() { int Arg0 = 4; int Arr1[] = {64,200,384,294,175,107,303,374,224,220,223,99,442}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {79,161,83,281,344,217,184,336,431,262,75,474,257}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 1; verify_case(4, Arg3, distribute(Arg0, Arg1, Arg2)); }

  // END CUT HERE

};
// BEGIN CUT HERE
int main() {
TeleportsNetwork ___test;
___test.run_test(-1);
}
// END CUT HERE 
