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
class LittleTree {
public:
  int toInt(string s) {int r = 0; istringstream ss(s); ss >> r; return r;}

  vector <string> split(const string _s, const string del) {
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

  int minCost(int N, vector <string> e, int height) {
    int ret = 0;
    string edge_string;
    int graph[100][100];
    bool fixed[100];
    memset(graph, 0, sizeof(graph));
    memset(fixed, false, sizeof(fixed));

    for (int i=0; i<e.size(); i++)
      edge_string += e[i];

    vector <string> tmp = split(edge_string, " ");
    for (int i=0; i<tmp.size(); i++) {
      vector <string> t = split(tmp[i], ",");
      graph[toInt(t[0])][toInt(t[1])] = 1;
    }

    queue <pair <int, int> > q;
    q.push(make_pair(0, 0));
    fixed[0] = true;

   
    while (!q.empty()) {
      pair <int, int> cur = q.front();
      q.pop();

      int cur_node = cur.first;
      int cur_level = cur.second;

      if (cur_level > height) {
        int parent = 0;
        int grandparent = 0;
        for (int i=0; i<100; i++)
          if (graph[i][cur_node] == 1) {
            parent = i;
            break;
          }
        for (int i=0; i<100; i++)
          if (graph[i][parent] == 1) {
            grandparent = i;
            break;
          }

        graph[parent][cur_node] = 0;
        graph[grandparent][cur_node] = 1;
        ret++;
        q.push(make_pair(cur_node, cur_level-1));
      } else {
        for (int i=0; i<100; i++)
          if (graph[cur_node][i] == 1 && !fixed[i])
            q.push(make_pair(i, cur_level+1));
        fixed[cur_node] = true;
      }
    }

    return ret;
  }
   
  // BEGIN CUT HERE
public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 5; string Arr1[] = {"0,1 1,2 2,3 2,4"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; int Arg3 = 1; verify_case(0, Arg3, minCost(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 5; string Arr1[] = {"0,1 1,2 2,3 2,4"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; int Arg3 = 3; verify_case(1, Arg3, minCost(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 3; string Arr1[] = {"0,1 1,2"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; int Arg3 = 0; verify_case(2, Arg3, minCost(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 9; string Arr1[] = {"0,3 3,1 1,8 ","8,","6 2,7 4,2 0,4 7",",5"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; int Arg3 = 2; verify_case(3, Arg3, minCost(Arg0, Arg1, Arg2)); }

  // END CUT HERE

};
// BEGIN CUT HERE
int main() {
LittleTree ___test;
___test.run_test(-1);
}
// END CUT HERE 
