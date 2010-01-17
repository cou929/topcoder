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
class HanoiTower {
public:
  typedef struct state {
    string a;
    string b;
    string c;
  };

  bool equal(state a, state b) {
    if (a.a == b.a && a.b == b.b && a.c == b.c)
      return true;
    return false;
  }

  bool solved(state a) {
    for (int i=0; i<a.a.size(); i++)
      if (a.a[i] != 'A')
        return false;
    for (int i=0; i<a.b.size(); i++)
      if (a.b[i] != 'B')
        return false;
    for (int i=0; i<a.c.size(); i++)
      if (a.c[i] != 'C')
        return false;
    return true;
  }

  state move(state & _s, int from, int to) {
    state s = _s;
    string f;;
    if (from == 0) {
      f = s.a[s.a.size() - 1];
      s.a.erase(s.a.size() - 1);
    } else if (from == 1) {
      f = s.b[s.b.size() - 1];
      s.b.erase(s.b.size() - 1);
    } else if (from == 2) {
      f = s.c[s.c.size() - 1];
      s.c.erase(s.c.size() - 1);
    }

    if (to == 0)
      s.a += f;
    else if (to == 1)
      s.b += f;
    else if (to == 2)
      s.c += f;

    return s;
  }

  typedef pair <string, pair <string, string> > hash;
  hash makeHash(state s) {
    return make_pair(s.a, make_pair(s.b, s.c));
  }

  vector <hash> visited;

  bool isVisited(state s) {
    hash h = makeHash(s);
    for (int i=0; i<visited.size(); i++)
      if (visited[i] == h)
        return true;
    return false;
  }

  bool isEmpty(state &s, int pos) {
    if (pos == 0 && s.a == "")
      return true;
    if (pos == 1 && s.b == "")
      return true;
    if (pos == 2 && s.c == "")
      return true;
    return false;
  }

  int moves(string pegA, string pegB, string pegC) {
    int ret = 0;
    queue <pair <state, int> > q;
    state start;
    start.a = pegA, start.b = pegB, start.c = pegC;
    
    q.push(make_pair(start, 0));
    visited.push_back(makeHash(start));

    while (!q.empty()) {
      pair <state, int> cur = q.front();
      q.pop();

      if (solved(cur.first)) {
        ret = cur.second;
        break;
      }

      for (int i=0; i<3; i++)
        if (!isEmpty(cur.first, i))
          for (int j=0; j<3; j++)
            if (i != j) {
              state next = move(cur.first, i, j);
              if (!isVisited(next)) {
                q.push(make_pair(next, cur.second + 1));
                visited.push_back(makeHash(next));
              }
            }
    }

    return ret;
  }
   
  // BEGIN CUT HERE
public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "A"; string Arg1 = "AA"; string Arg2 = "AA"; int Arg3 = 4; verify_case(0, Arg3, moves(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arg0 = "B"; string Arg1 = "C"; string Arg2 = "A"; int Arg3 = 5; verify_case(1, Arg3, moves(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arg0 = "CBA"; string Arg1 = ""; string Arg2 = ""; int Arg3 = 5; verify_case(2, Arg3, moves(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arg0 = "BBBBBBBBBA"; string Arg1 = ""; string Arg2 = ""; int Arg3 = 11; verify_case(3, Arg3, moves(Arg0, Arg1, Arg2)); }
	void test_case_4() { string Arg0 = "CBACBACBAA"; string Arg1 = ""; string Arg2 = ""; int Arg3 = 19; verify_case(4, Arg3, moves(Arg0, Arg1, Arg2)); }

  // END CUT HERE

};
// BEGIN CUT HERE
int main() {
HanoiTower ___test;
___test.run_test(-1);
}
// END CUT HERE 
