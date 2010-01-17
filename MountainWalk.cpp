// BEGIN CUT HERE
// END CUT HERE
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>

using namespace std;

class MountainWalk {
public:
  int cellsVisited(vector <string> areaMap, int heightDifference)
  { 
    unsigned int i, j;
    int visited[areaMap.size()][areaMap[0].size()];
    int counter = 1;
    int curX, curY, nextX, nextY;
    int direction[4][2] = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}};
    int checker;

    for (i=0; i<areaMap.size(); i++)
      for (j=0; j<areaMap[0].size(); j++)
	visited[i][j] = 0;

    curX = 0; curY = 0;

    while(1)
      {
	checker = 0;
	for (i=0; i<4; i++)
	  {
	    nextX = curX + direction[i][0];
	    nextY = curY + direction[i][1];

	    if (nextX < 0 || nextY < 0 || nextX >= areaMap.size() || nextY >= areaMap[0].size())
	      continue;

	    if (abs(areaMap[curX][curY] - areaMap[nextX][nextY]) > heightDifference)
	      continue;

	    if (visited[nextX][nextY] == 1)
	      continue;

	    counter++;
	    visited[curX][curY] = 1;
	    curX = nextX;
	    curY = nextY;
	    checker = 1;
	    break;
	  }
	if (checker == 0)
	  break;
      }

    return counter;
  }

   
  // BEGIN CUT HERE
public:
  void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
private:
  template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
  void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
  void test_case_0() { string Arr0[] = {"056",
					"135",
					"234"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 5; verify_case(0, Arg2, cellsVisited(Arg0, Arg1)); }
  void test_case_1() { string Arr0[] = {"056",
					"195",
					"234"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 8; verify_case(1, Arg2, cellsVisited(Arg0, Arg1)); }
  void test_case_2() { string Arr0[] = {"865",
					"123",
					"111"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 9; verify_case(2, Arg2, cellsVisited(Arg0, Arg1)); }
  void test_case_3() { string Arr0[] = {"00009876543210",
					"00009876543210",
					"00009876543210",
					"00009876543210"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 8; int Arg2 = 16; verify_case(3, Arg2, cellsVisited(Arg0, Arg1)); }
  void test_case_4() { string Arr0[] = {"0000",
					"0000",
					"0000",
					"0000",
					"9999",
					"8888",
					"7777",
					"6666",
					"5555",
					"4444",
					"3333",
					"2222",
					"1111",
					"0000"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 16; verify_case(4, Arg2, cellsVisited(Arg0, Arg1)); }
  void test_case_5() { string Arr0[] = {"173642855131893831828253420",
					"126290035950506994475683704",
					"381277675415026563959463393",
					"019782700912864681764582260",
					"496448425114634806770407597",
					"049628433145840178727435051",
					"117194708226266248973780562",
					"398138380998246682323622510",
					"408178777661559971959512111"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 8; int Arg2 = 135; verify_case(5, Arg2, cellsVisited(Arg0, Arg1)); }
  void test_case_6() { string Arr0[] = {"9"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; int Arg2 = 1; verify_case(6, Arg2, cellsVisited(Arg0, Arg1)); }

  // END CUT HERE

};

// BEGIN CUT HERE
int main() {
MountainWalk ___test;
___test.run_test(-1);
}
// END CUT HERE 
