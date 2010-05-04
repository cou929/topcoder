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
class RobotSimulation {
public:
  int visited[500][500];

  pair <int, int> travel(string program, int x, int y) {
    int i;
    int n = program.size();

    for (i=0; i<n; i++) {
      if (program[i] == 'U')
        x += 1;
      else if (program[i] == 'D')
        x -= 1;
      else if (program[i] == 'L')
        y -= 1;
      else if (program[i] == 'R')
        y += 1;
      visited[x][y] = 1;
    }

    return make_pair(x, y);
  }

  int countVisited(void) {
    int ret = 0;
    int i, j;
    int n = 500;

    for (i=0; i<n; i++)
      for (j=0; j<n; j++)
        if (visited[i][j] == 1)
          ret++;

    return ret;
  }

  int cellsVisited(string program, int times) {
    int ret = 0;
    vector <int> counts;
    int i;
    
    memset(visited, 0, sizeof(visited));

    visited[250][250] = 1;

    pair <int, int> res(make_pair(250, 250));
    for (i=0; i<10; i++) {
      res = travel(program, res.first, res.second);
      int tmp = countVisited();
      if (i > 0)
        tmp -= accumulate(counts.begin(), counts.end(), 0);
      counts.push_back(tmp);
    }

    for (i=0; i<min((int)counts.size(), times); i++)
      ret += counts[i];

    int remain = times - counts.size();
    if (remain >= 0)
      ret += counts[counts.size() - 1] * remain;

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
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { 
    string Arg0 = "RRR"; 
    int Arg1 = 100; 
    int Arg2 = 301; 
    verify_case(0, Arg2, cellsVisited(Arg0, Arg1)); }
	void test_case_1() { 
    string Arg0 = "DDU"; 
    int Arg1 = 100; 
    int Arg2 = 102; 
    verify_case(1, Arg2, cellsVisited(Arg0, Arg1)); }
	void test_case_2() { 
    string Arg0 = "URLD"; 
    int Arg1 = 100; 
    int Arg2 = 3; 
    verify_case(2, Arg2, cellsVisited(Arg0, Arg1)); }
	void test_case_3() { 
    string Arg0 = "UUDUDDLLDR"; 
    int Arg1 = 1; 
    int Arg2 = 7; 
    verify_case(3, Arg2, cellsVisited(Arg0, Arg1)); }
	void test_case_4() { 
    string Arg0 = "UUDUDDLLDR"; 
    int Arg1 = 12345678; 
    int Arg2 = 37037039; 
    verify_case(4, Arg2, cellsVisited(Arg0, Arg1)); }
	void test_case_5() { 
    string Arg0 = "RRUUULLDD"; 
    int Arg1 = 3603602; 
    int Arg2 = 10810815; 
    verify_case(5, Arg2, cellsVisited(Arg0, Arg1)); }
	void test_case_6() { 
    string Arg0 = "RRR"; 
    int Arg1 = 100; 
    int Arg2 = 301; 
    verify_case(6, Arg2, cellsVisited(Arg0, Arg1)); }
	void test_case_7() { 
    string Arg0 = "RRRRRRRRRR"; 
    int Arg1 = 200000000; 
    int Arg2 = 301; 
    verify_case(7, Arg2, cellsVisited(Arg0, Arg1)); }

  // END CUT HERE

};
// BEGIN CUT HERE
int main() {
RobotSimulation ___test;
___test.run_test(-1);
}
// END CUT HERE 
