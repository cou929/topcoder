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
class IngredientProportions {
public:
  int gcd(const int _a, const int _b) {
    int a = max(_a, _b);
    int b = min(_a, _b);

    while (b) {
      int tmp = a % b;
      a = b;
      b = tmp;
    }

    return a;
  }

  vector <int> getMasses(vector <string> proportions) {
    vector <int> ret(proportions.size()+1, 0);
    int graph[proportions.size()+1][proportions.size()+1];
    memset(graph, 0, sizeof(graph));

    for (int i=0; i<proportions.size(); i++) {
      int num1 = proportions[i][1] - '0';
      int num2 = proportions[i][8] - '0';
      int ratio1 = proportions[i][13] - '0';
      int ratio2 = proportions[i][15] - '0';
      graph[num1][num2] = ratio1;
      graph[num2][num1] = ratio2;
    }

    //     for (int i=0; i<=proportions.size(); i++) {
    //       for (int j=0; j<=proportions.size(); j++)
    //         cout << graph[i][j] << " ";
    //       cout << endl;
    //     }

    queue <pair <int, int> > q;

    for (int i=0; i<=proportions.size(); i++) {
      int counter = 0;
      int index = 0;
      for (int j=0; j<=proportions.size(); j++)
        if (graph[i][j] != 0) {
          counter++;
          index = j;
        }
      if (counter == 1) {
        q.push(make_pair(i, index));
        break;
      }
    }

    while (!q.empty()) {
      pair <int, int> cur = q.front();
      q.pop();

      int ratio1 = graph[cur.first][cur.second];
      int ratio2 = graph[cur.second][cur.first];
      graph[cur.second][cur.first] = 0;

      for (int i=0; i<=proportions.size(); i++)
        if (graph[cur.second][i] != 0)
          q.push(make_pair(cur.second, i));

      if (ret[cur.first] == 0 && ret[cur.second] == 0) {
        ret[cur.first] = ratio1;
        ret[cur.second] = ratio2;
      } else {
        int mul_for_cur = 0;
        int mul_for_exist = 0;
        int index = 0;
        if (ret[cur.first] != 0) {
          mul_for_cur = ret[cur.first] * ratio2;
          mul_for_exist = ratio1;
          index = cur.second;
        } else {
          mul_for_cur = ret[cur.second] * ratio1;
          mul_for_exist = ratio2;
          index = cur.first;
        }

        for (int i=0; i<ret.size(); i++)
          ret[i] *= mul_for_exist;

        ret[index] = mul_for_cur;
      }
    }

    int divisor = ret[0];
    for (int i=1; i<ret.size(); i++)
      divisor = gcd(divisor, ret[i]);

    for (int i=0; i<ret.size(); i++)
      ret[i] /= divisor;

    return ret;
  }
   
  // BEGIN CUT HERE
public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"#0 and #1 as 6:4"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {3, 2 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, getMasses(Arg0)); }
	void test_case_1() { string Arr0[] = {"#0 and #1 as 9:8","#1 and #2 as 9:8"}
    ; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {81, 72, 64 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, getMasses(Arg0)); }
	void test_case_2() { string Arr0[] = {"#4 and #0 as 1:1", "#4 and #1 as 3:1", "#4 and #2 as 5:1", "#4 and #3 as 7:1"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {105, 35, 21, 15, 105 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, getMasses(Arg0)); }
	void test_case_3() { string Arr0[] = {"#2 and #3 as 6:8", "#0 and #1 as 9:3", "#3 and #0 as 7:5"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {60, 20, 63, 84 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, getMasses(Arg0)); }

  // END CUT HERE

};
// BEGIN CUT HERE
int main() {
IngredientProportions ___test;
___test.run_test(-1);
}
// END CUT HERE 
