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

typedef struct node {
  int weight;
  string name;
};

bool operator< (const node &a, const node &b) {
  if (a.weight == b.weight)
    return a.name < b.name;
  else
    return a.weight > b.weight;
}

class TheBestName {
public:
  vector <string> sort(vector <string> names) {
    vector <string> ret;
    vector <node> nodes;
    int number_of_john = 0;

    for (unsigned int i=0; i<names.size(); i++) {
      if (names[i] == "JOHN") {
        number_of_john++;
        continue;
      }
      node a;
      a.weight = 0;
      a.name = names[i];
      for (unsigned int j=0; j<names[i].size(); j++)
        a.weight += names[i][j] - 'A' + 1;
      nodes.push_back(a);
    }

    std::sort(nodes.begin(), nodes.end());

    for (int i=0; i<number_of_john; i++)
      ret.push_back("JOHN");

    for (unsigned int i=0; i<nodes.size(); i++)
      ret.push_back(nodes[i].name);

    return ret;
  }
   
  // BEGIN CUT HERE
public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"JOHN", "PETR", "ACRUSH"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"JOHN", "ACRUSH", "PETR" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, sort(Arg0)); }
	void test_case_1() { string Arr0[] = {"GLUK", "MARGARITKA"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"MARGARITKA", "GLUK" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, sort(Arg0)); }
	void test_case_2() { string Arr0[] = {"JOHN", "A", "AA", "AAA", "JOHN", "B", "BB", "BBB", "JOHN", "C", "CC", "CCC", "JOHN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"JOHN", "JOHN", "JOHN", "JOHN", "CCC", "BBB", "CC", "BB", "AAA", "C", "AA", "B", "A" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, sort(Arg0)); }
	void test_case_3() { string Arr0[] = {"BATMAN", "SUPERMAN", "SPIDERMAN", "TERMINATOR"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"TERMINATOR", "SUPERMAN", "SPIDERMAN", "BATMAN" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, sort(Arg0)); }

  // END CUT HERE

};
// BEGIN CUT HERE
int main() {
TheBestName ___test;
___test.run_test(-1);
}
// END CUT HERE 
