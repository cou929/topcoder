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
class AddElectricalWires {
public:
  int com(int n, int r)
  {
    int i, j;
    int result[r+1], tmp[r+1];

    for (i=0; i<=r; i++)
      {
        result[i] = 0;
        tmp[i] = 0;
      }

    result[0] = 1;

    for (i=1; i<=n; i++)
      {
        tmp[0] = 1;

        for (j=1; j<=r; j++)
          tmp[j] = result[j-1] + result[j];

        for (j=0; j<=r; j++)
          result[j] = tmp[j];
      }

    return result[r];
  }

  int maxNewWires(vector <string> wires, vector <int> gridConnections)
  {
    int ret = 0;
    int already = 0;
    int label[wires[0].size()];
    memset(label, -1, sizeof(label));

    for (int i=0; i<wires[0].size()-1; i++)
      for (int j=i+1; j<wires[i].size(); j++)
        if (wires[i][j] == '1')
          already++;

    for (int i=0; i<gridConnections.size(); i++)
      {
        stack <int> s;
        s.push(gridConnections[i]);
        label[gridConnections[i]] = gridConnections[i];

        while (!s.empty())
          {
            int cur = s.top();
            s.pop();

            for (int j=0; j<wires[cur].size(); j++)
              if (wires[cur][j] == '1')
                if (label[j] == -1)
                  {
                    s.push(j);
                    label[j] = gridConnections[i];
                  }
          }
      }

    int nonlabel = 0;
    vector <int> counter(wires[0].size());
    for (int i=0; i<wires[0].size(); i++)
      if (label[i] == -1)
        nonlabel++;
      else
        counter[label[i]]++;

    sort(counter.begin(), counter.end());

    counter[wires[0].size()-1] += nonlabel;

    for (int i=0; i<counter.size(); i++)
      ret += com(counter[i], 2);

    return ret - already;
  }
   
  // BEGIN CUT HERE
public:
  void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
private:
  template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
  void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
  void test_case_0() { string Arr0[] = {"000","000","000"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; verify_case(0, Arg2, maxNewWires(Arg0, Arg1)); }
  void test_case_1() { string Arr0[] = {"000","000","000"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; verify_case(1, Arg2, maxNewWires(Arg0, Arg1)); }
  void test_case_2() { string Arr0[] = {"01","10"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; verify_case(2, Arg2, maxNewWires(Arg0, Arg1)); }
  void test_case_3() { string Arr0[] = {"00000","00000","00000","00000","00000"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,1,2,3,4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; verify_case(3, Arg2, maxNewWires(Arg0, Arg1)); }
  void test_case_4() { string Arr0[] = {"01000","10100","01010","00100","00000"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2,4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; verify_case(4, Arg2, maxNewWires(Arg0, Arg1)); }

  // END CUT HERE

};
// BEGIN CUT HERE
int main() {
AddElectricalWires ___test;
___test.run_test(-1);
}
// END CUT HERE 
