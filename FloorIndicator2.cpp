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
class FloorIndicator {
public:
  int toInt(string s) {int r = 0; istringstream ss(s); ss >> r; return r;}
  string toStr(int n) {ostringstream ss; ss << n; return ss.str();}
  double averageFloor(int N, vector <string> indicator)
  {
    vector <string> nums;
    string s = "###...#.###.###.#.#.###.###.###.###.###";
    nums.push_back(s);
    s = "#.#...#...#...#.#.#.#...#.....#.#.#.#.#";
    nums.push_back(s);
    s = "#.#...#.###.###.###.###.###...#.###.###";
    nums.push_back(s);
    s = "#.#...#.#.....#...#...#.#.#...#.#.#...#";
    nums.push_back(s);
    s = "###...#.###.###...#.###.###...#.###.###";
    nums.push_back(s);

    vector <vector <int> > vals;

    for (int i=0; i<N; i++)
      {
	bool candidates[10];
	memset(candidates, true, sizeof(candidates));

	for (int j=0; j<10; j++)
	  for (int col=0; col<5; col++)
	    for (int row=0; row<3; row++)
	      if (indicator[col][row + i*4] == '#' && nums[col][row + j*4] == '.')
		candidates[j] = false;

	vector <int> t;
	for (int k=0; k<10; k++)
	  if (candidates[k])
	    t.push_back(k);

	if (t.empty())
	  return -1;
	
	vals.push_back(t);
      }

    double nume = 0;
    double deno = 0;
    queue <string> q;
    for (int i=0; i<vals[0].size(); i++)
      q.push(toStr(vals[0][i]));

    while (!q.empty())
      {
    	string cur = q.front();
    	q.pop();

    	if (cur.size() == N)
    	  {
    	    nume += (double)toInt(cur);
    	    deno += 1.0;
    	    continue;
    	  }

    	for (int i=0; i<vals[cur.size()].size(); i++)
    	  q.push(cur + toStr(vals[cur.size()][i]));
      }

    return nume / deno;
  }
  // BEGIN CUT HERE
public:
  void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
private:
  template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
  void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
  void test_case_0() { int Arg0 = 1; string Arr1[] = {"###",
						      "#.#",
						      "###",
						      "#.#",
						      "###"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 8.0; verify_case(0, Arg2, averageFloor(Arg0, Arg1)); }
  void test_case_1() { int Arg0 = 2; string Arr1[] = {"###.###",
						      "#.#.#.#",
						      "#.#.###",
						      "#.#...#",
						      "###.###"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 48.5; verify_case(1, Arg2, averageFloor(Arg0, Arg1)); }
  void test_case_2() { int Arg0 = 2; string Arr1[] = {".......",
						      ".......",
						      ".......",
						      ".......",
						      "......."}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 49.5; verify_case(2, Arg2, averageFloor(Arg0, Arg1)); }
  void test_case_3() { int Arg0 = 1; string Arr1[] = {"...",
						      ".#.",
						      "...",
						      "...",
						      "..."}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = -1.0; verify_case(3, Arg2, averageFloor(Arg0, Arg1)); }

  // END CUT HERE
};
// BEGIN CUT HERE
int main() {
FloorIndicator ___test;
___test.run_test(-1);
}
// END CUT HERE 
