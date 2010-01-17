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
class LightsCube {
public:
  int N;
  int l[40][40][40];
  int tmp[40][40][40];

  bool inRange(int n)
  {
    if (0 <= n && n < N)
      return true;
    return false;
  }

  int ltotmp()
  {
    for (int x=0; x<N; x++)
      for (int y=0; y<N; y++)
	for (int z=0; z<N; z++)
	  tmp[x][y][z] = l[x][y][z];
    return 0;
  }

  int tmptol()
  {
    for (int x=0; x<N; x++)
      for (int y=0; y<N; y++)
	for (int z=0; z<N; z++)
	  l[x][y][z] = tmp[x][y][z];
    return 0;
  }

  vector <int> around(int _x, int _y, int _z)
  {
    map <int, int> m;
    vector <int> ret;
    char dir[2] = {-1, 1};

    for (int i=0; i<2; i++)
      {
	int x = _x + dir[i];
	int y = _y;
	int z = _z;

	if (inRange(x) && inRange(y) && inRange(z))
	  if (l[x][y][z] != -1)
	    m[l[x][y][z]]++;
      }

    for (int i=0; i<2; i++)
      {
	int x = _x;
	int y = _y + dir[i];
	int z = _z;

	if (inRange(x) && inRange(y) && inRange(z))
	  if (l[x][y][z] != -1)
	    m[l[x][y][z]]++;
      }

    for (int i=0; i<2; i++)
      {
	int x = _x;
	int y = _y;
	int z = _z + dir[i];

	if (inRange(x) && inRange(y) && inRange(z))
	  if (l[x][y][z] != -1)
	    m[l[x][y][z]]++;
      }

    for (map <int, int>::iterator i=m.begin(); i!=m.end(); i++)
      ret.push_back(i->first);

    return ret;
  }

  vector <int> count(int _N, vector <string> lights)
  {
    vector <int> ret;
    map <int, int> m;
    memset(l, -1, sizeof(l));
    N = _N;

    for (int i=0; i<lights.size(); i++)
      {
	int x, y ,z;
	sscanf(lights[i].c_str(), "%d %d %d", &x, &y, &z);
	l[x][y][z] = i;
      }

    while (1)
      {
	bool found = false;
	ltotmp();

	for (int x=0; x<N; x++)
	  for (int y=0; y<N; y++)
	    for (int z=0; z<N; z++)
	      if (l[x][y][z] == -1)
		{
		  found = true;
		  vector <int> res = around(x, y, z);
		  if (res.empty())
		    continue;

		  sort(res.begin(), res.end());
		  tmp[x][y][z] = res[0];
		}

	if (!found)
	  break;

	tmptol();
      }

    for (int x=0; x<N; x++)
      for (int y=0; y<N; y++)
	for (int z=0; z<N; z++)
	  m[l[x][y][z]]++;

    for (int i=0; i<lights.size(); i++)
      ret.push_back(m[i]);

    return ret;
  }
  // BEGIN CUT HERE
public:
  void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
private:
  template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
  void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
  void test_case_0() { int Arg0 = 2; string Arr1[] = {"0 0 0", "0 0 1", "0 1 0", "0 1 1", "1 0 0", "1 0 1", "1 1 0", "1 1 1"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1, 1, 1, 1, 1, 1, 1, 1 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, count(Arg0, Arg1)); }
  void test_case_1() { int Arg0 = 3; string Arr1[] = {"1 1 1"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {27 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, count(Arg0, Arg1)); }
  void test_case_2() { int Arg0 = 4; string Arr1[] = {"0 0 0", "3 3 3"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {32, 32 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(2, Arg2, count(Arg0, Arg1)); }
  void test_case_3() { int Arg0 = 5; string Arr1[] = {"0 2 4", "2 0 0", "3 4 4", "4 1 2"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {38, 28, 32, 27 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(3, Arg2, count(Arg0, Arg1)); }
  void test_case_4() { int Arg0 = 12; string Arr1[] = {"4 7 6", "8 0 0", "3 2 3", "7 7 2", "7 5 1",
						       "10 11 5", "4 9 7", "6 1 0", "10 1 1", "9 7 11",
						       "11 3 11", "9 0 3", "10 2 0"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {264, 18, 303, 236, 105, 124, 216, 44, 53, 146, 126, 80, 13 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(4, Arg2, count(Arg0, Arg1)); }
  void test_case_5() { int Arg0 = 40; string Arr1[] = {"29 13 9", "4 10 34", "11 26 16", "2 33 22", "27 31 14", "36 20 8"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {14657, 12834, 12364, 5902, 12678, 5565 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(5, Arg2, count(Arg0, Arg1)); }

  // END CUT HERE
};
// BEGIN CUT HERE
int main() {
LightsCube ___test;
___test.run_test(-1);
}
// END CUT HERE 
