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

using namespace std;

class Pathfinding {
public:
  set <pair<int, int> > visited;
  queue <pair <pair<int, int>, int> > q;
  int lx, ux, ly, uy;
  pair <int, int> goal;

  int bfs(int a, int b)
  {
    pair <pair <int, int>, int> cur;
    pair <int, int> t(a, b);
    pair <pair <int, int>, int> s(t, 0);
    q.push(s);
    visited.insert(t);

    while (!q.empty()) 
      {
	cur = q.front();
	q.pop();

	if (cur.first == goal)
	  break;
	
	pair <int, int> tmp;
	if (cur.first.second % 2 == 0)
	  {
	    tmp.first = cur.first.first+1;
	    tmp.second = cur.first.second;
	  }
	else
	  {
	    tmp.first = cur.first.first-1;
	    tmp.second = cur.first.second;
	  }

	if (lx <= tmp.first && tmp.first <= ux && ly <= tmp.second && tmp.second <= uy && visited.find(tmp) == visited.end())
	  {
	    visited.insert(tmp);
	    pair<pair<int, int>, int> t(tmp, cur.second+1);
	    q.push(t);
	  }

	if (cur.first.first % 2 == 0)
	  {
	    tmp.first = cur.first.first;
	    tmp.second = cur.first.second+1;
	  }
	else
	  {
	    tmp.first = cur.first.first;
	    tmp.second = cur.first.second-1;
	  }

	if (lx <= tmp.first && tmp.first <= ux && ly <= tmp.second && tmp.second <= uy && visited.find(tmp) == visited.end())
	  {
	    visited.insert(tmp);
	    pair<pair<int, int>, int> t(tmp, cur.second+1);
	    q.push(t);
	  }
      }

    return cur.second;
  }

  int getDirections(int x, int y)
  {
    goal.first = x;
    goal.second = y;

    if (x > 0)
      {
	ux = x + 2;
	lx = -2;
      }
    else if (x < 0)
      {
	ux = 2;
	lx = x - 2;
      }
    else
      {
	ux = x + 2;
	lx = x - 2;
      }

    if (y > 0)
      {
	uy = y + 2;
	ly = -2;
      }
    else if (y < 0)
      {
	uy = 2;
	ly = y - 2;
      }
    else
      {
	uy = y + 2;
	ly = y - 2;
      }

    return bfs(0, 0);
  }

   
  // BEGIN CUT HERE
public:
  void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
private:
  template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
  void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
  void test_case_0() { int Arg0 = 0; int Arg1 = -4; int Arg2 = 8; verify_case(0, Arg2, getDirections(Arg0, Arg1)); }
  void test_case_1() { int Arg0 = 5; int Arg1 = -4; int Arg2 = 9; verify_case(1, Arg2, getDirections(Arg0, Arg1)); }
  void test_case_2() { int Arg0 = 5; int Arg1 = 4; int Arg2 = 9; verify_case(2, Arg2, getDirections(Arg0, Arg1)); }
  void test_case_3() { int Arg0 = -1; int Arg1 = -4; int Arg2 = 7; verify_case(3, Arg2, getDirections(Arg0, Arg1)); }
  void test_case_4() { int Arg0 = 0; int Arg1 = 0; int Arg2 = 0; verify_case(4, Arg2, getDirections(Arg0, Arg1)); }
  void test_case_5() { int Arg0 = -822882; int Arg1 = 0; int Arg2 = 822886; verify_case(5, Arg2, getDirections(Arg0, Arg1)); }

  // END CUT HERE

};

// BEGIN CUT HERE
int main() {
Pathfinding ___test;
___test.run_test(5);
}
// END CUT HERE 
