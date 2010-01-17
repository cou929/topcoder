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

typedef struct node
{
  int weapons;
  int shots;
};

bool operator<(const node & a, const node & b)
{
  return a.shots > b.shots;
}

class KiloManX {
public:
  int leastShots(vector <string> damageChart, vector <int> bossHealth)
  {
    priority_queue <node> q;
    bool visited[40000];

    memset(visited, false, sizeof(visited));

    node tmp;
    tmp.weapons = 0;
    tmp.shots = 0;
    q.push(tmp);

    while (!q.empty())
      {
        node n = q.top();
        q.pop();

        if (visited[n.weapons])
          continue;

        visited[n.weapons] = true;

        if (n.weapons == (1 << (int)damageChart.size()) - 1)
          return n.shots;

        for (int i=0; i<damageChart.size(); i++)
          {
            if ((n.weapons >> i) & 1)
              continue;

            int best = bossHealth[i];
            for (int j=0; j<damageChart.size(); j++)
              {
                if (i == j)
                  continue;

                if (((n.weapons >> j) & 1) && damageChart[j][i] != '0')
                  {
                    int shotNum = bossHealth[i] / (damageChart[j][i] - '0');
                    if (bossHealth[i] % (damageChart[j][i] - '0') != 0)
                      shotNum++;
                    best = min(best, shotNum);
                  }
              }

            node tmp;
            tmp.weapons = (n.weapons | (1 << i));
            tmp.shots = n.shots + best;
            q.push(tmp);
          }
      }

    return 0;
  }
   
  // BEGIN CUT HERE
public:
  void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
private:
  template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
  void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
  void test_case_0() { string Arr0[] = {"070","500","140"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {150,150,150}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 218; verify_case(0, Arg2, leastShots(Arg0, Arg1)); }
  void test_case_1() { string Arr0[] = {"1542", "7935", "1139", "8882"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {150,150,150,150}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 205; verify_case(1, Arg2, leastShots(Arg0, Arg1)); }
  void test_case_2() { string Arr0[] = {"07", "40"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {150,10}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 48; verify_case(2, Arg2, leastShots(Arg0, Arg1)); }
  void test_case_3() { string Arr0[] = {"198573618294842",
                                        "159819849819205",
                                        "698849290010992",
                                        "000000000000000",
                                        "139581938009384",
                                        "158919111891911",
                                        "182731827381787",
                                        "135788359198718",
                                        "187587819218927",
                                        "185783759199192",
                                        "857819038188122",
                                        "897387187472737",
                                        "159938981818247",
                                        "128974182773177",
                                        "135885818282838"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {157, 1984, 577, 3001, 2003, 2984, 5988, 190003,
                                                                                                                                               9000, 102930, 5938, 1000000, 1000000, 5892, 38}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 260445; verify_case(3, Arg2, leastShots(Arg0, Arg1)); }
  void test_case_4() { string Arr0[] = {"02111111", "10711111", "11071111", "11104111",
                                        "41110111", "11111031", "11111107", "11111210"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {28,28,28,28,28,28,28,28}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 92; verify_case(4, Arg2, leastShots(Arg0, Arg1)); }

  // END CUT HERE

};
// BEGIN CUT HERE
int main() {
  KiloManX ___test;
  ___test.run_test(-1);
}
// END CUT HERE 
